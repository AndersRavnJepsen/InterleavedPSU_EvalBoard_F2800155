/*******************************************************
 * @ Author: ARJ
 * @ Create Time: 2025-08-19 11:03:20
 * @ Modified by: ARJ
 * @ Modified time: 2025-09-16 12:21:29
 * @ Description:
 *******************************************************/

#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"
#include "F280015x_Device.h" // Header for bitfield commands.

#include "Config.h"
#include "PSU.h"

// ============ Prototypes ==============
void system_init();
bool system_ready();

float32_t setpoint = 0.0f;
bool somethings_rotten_in_the_state_of_la_la_land = false;
int state = 0;

// ============================== STATE MACHINE SETUP ====================================================
// Initialize state pointers
void (*state_Ptr)(); // Base States pointer

// Declare State function prototypes
void init_state();
void idle_state();
void softStart_state();
void run_state();
void fault_state();

void main()
{
    // Run the system initializations. Some settings (like initial duty cycle) are overwritten by settings in Config.h system_init();
    system_init();
    // At the moment we dont run an interrupt for the ADC, to avoid the overhead.
    // Instead we simply check the flag in each loop, to see if the four measurements are ready.
    AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;

    // Make sure INT1 flag is cleared initially.
    // Test, run for a short while, then disable pwms
    // SysCtl_delay(3000);
    // State-machine initialization
    state_Ptr = &init_state;

    while (1)
    {
        // State machine entry & exit point
        (*state_Ptr)(); // jump to a state function
    }
}

// ####################################################################################################################
// ###################################################################################################################

void init_state()
{
    state = 1;

    // 1) Force outputs LOW (A/B) and stop ADC triggers
    EPwm1Regs.AQCSFRC.bit.CSFA = 1;
    // EPwm1Regs.AQCSFRC.bit.CSFB = 1;
    EPwm2Regs.AQCSFRC.bit.CSFA = 1;
    // EPwm2Regs.AQCSFRC.bit.CSFB = 1;
    EPwm3Regs.AQCSFRC.bit.CSFA = 1;
    // EPwm3Regs.AQCSFRC.bit.CSFB = 1;
    EPwm4Regs.AQCSFRC.bit.CSFA = 1;
    // EPwm4Regs.AQCSFRC.bit.CSFB = 1;

    // Disable ADC triggers
    EPwm1Regs.ETSEL.bit.SOCAEN = 0;
    EPwm2Regs.ETSEL.bit.SOCAEN = 0;
    EPwm3Regs.ETSEL.bit.SOCAEN = 0;
    EPwm4Regs.ETSEL.bit.SOCAEN = 0;

    // 2) Stop TBCLK while we write period and compare values.
    EALLOW;
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;
    EDIS;

    // 3) Load initial period/compare.
    EPWM_setTimeBasePeriod(ePWM1_BASE, INITIAL_PERIOD_COUNT); // slaves linked to EPWM1 if configured
    EPWM_setCounterCompareValue(ePWM2_BASE, EPWM_COUNTER_COMPARE_A, INITIAL_COMPARE_VALUE);
    EPWM_setCounterCompareValue(ePWM3_BASE, EPWM_COUNTER_COMPARE_A, INITIAL_COMPARE_VALUE);
    EPWM_setCounterCompareValue(ePWM4_BASE, EPWM_COUNTER_COMPARE_A, INITIAL_COMPARE_VALUE);
    EPWM_setCounterCompareValue(ePWM1_BASE, EPWM_COUNTER_COMPARE_A, INITIAL_COMPARE_VALUE);

    // Ensure the "master" pwm counter is zero.
    EPwm1Regs.TBCTR = 0;

    // 4) Start TBCLK and broadcast a sync so slaves latch TBPRD/CMP and align
    EALLOW;
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    EDIS;

    // Force a sync pulse, to let pwm2-4 fire a global load event for transfering TBPRD and CMPA values from shadow.
    EPWM_forceSyncPulse(EPWM1_BASE);

    // short tea-time break. (let stuff settle.)
    SysCtl_delay(64);

    // // 5) Keep outputs forced LOW and SOCA disabled; clear any stale TZ flags
    // uint16_t const TZCLR_MASK1 = (EPWM_TZCLR_CBC | EPWM_TZCLR_OST |
    //                               EPWM_TZCLR_DCAEVT1 | EPWM_TZCLR_DCAEVT2 |
    //                               EPWM_TZCLR_DCBEVT1 | EPWM_TZCLR_DCBEVT2);

    // EALLOW;
    // EPwm1Regs.TZCLR.all = TZCLR_MASK1;
    // EPwm2Regs.TZCLR.all = TZCLR_MASK1;
    // EPwm3Regs.TZCLR.all = TZCLR_MASK1;
    // EPwm4Regs.TZCLR.all = TZCLR_MASK1;
    // EDIS;

    // 6) Hand off to IDLE
    state_Ptr = &idle_state;
}



void idle_state()
{
    state = 2;

    // 0) Stay safe until we’re ready
    setpoint = 0.0f;

    // Clear integrator ?


    // If any prerequisite (VIN, temperature, GPIO interlocks, etc.) fails → remain in IDLE
    if (!system_ready())
    {
        // keep outputs forced low and triggers off
        EPwm1Regs.AQCSFRC.bit.CSFA = 1;
        EPwm2Regs.AQCSFRC.bit.CSFA = 1;
        EPwm3Regs.AQCSFRC.bit.CSFA = 1;
        EPwm4Regs.AQCSFRC.bit.CSFA = 1;
        EPwm1Regs.ETSEL.bit.SOCAEN = 0;
        EPwm2Regs.ETSEL.bit.SOCAEN = 0;
        EPwm3Regs.ETSEL.bit.SOCAEN = 0;
        EPwm4Regs.ETSEL.bit.SOCAEN = 0;
        return;
    }

    // 3) Release outputs and enable ADC triggers
    EPwm1Regs.AQCSFRC.bit.CSFA = 0;
    EPwm2Regs.AQCSFRC.bit.CSFA = 0;
    EPwm3Regs.AQCSFRC.bit.CSFA = 0;
    EPwm4Regs.AQCSFRC.bit.CSFA = 0;

    EPwm1Regs.ETSEL.bit.SOCAEN = 1;
    EPwm2Regs.ETSEL.bit.SOCAEN = 1;
    EPwm3Regs.ETSEL.bit.SOCAEN = 1;
    EPwm4Regs.ETSEL.bit.SOCAEN = 1;

    // Clear ADC EoS flag once before starting
    AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;

    // 4) Hand off to soft-start
    state_Ptr = &softStart_state;

}



// ======= Tuning (codes are CMPSS DAC codes, not amps) =======
// Compute these once from Vref/VDDA
// #define SOFTSTART_RAMP_LIMIT (/* ceiling during softstart */ 2989) // e.g. ~3 A
// #define HARD_OC_DAC_CODE (/* hard OC for RUN        */ 850)        // e.g. ~10 A
// #define SOFTSTART_DAC_STEP (/* DAC steps per update */ 2)          // ~6.5 mA per update with your LSB
// #define SOFTSTART_UPDATE_DIV (/* update every N calls */ 120)
// #define SOFTSTART_DONE_COUNT (/* promote after M clean */ 4)

#define SOFTSTART_SETPOINT_TARGET        (/* e.g. target avg in your units */  900.0f)
#define SOFTSTART_SETPOINT_STEP          (/* per update increment          */    10.0f)
#define SOFTSTART_SETPOINT_UPDATE_DIV    (/* update every N calls          */     1200)
#define SOFTSTART_TARGET_CONFIDENCE_COUNT    (/* extra loops after reach       */     10)



static uint16_t softstart_loop_div_count = 0;
static uint16_t target_reached_counter = 0;

void softStart_state()
{
    state = 3;

    // Fault catch — OSHT is latched; jump to FAULT if it ever triggered
    if (EPwm1Regs.TZOSTFLG.all | EPwm2Regs.TZOSTFLG.all | EPwm3Regs.TZOSTFLG.all | EPwm4Regs.TZOSTFLG.all) 
    {
        state_Ptr = &fault_state;
        return;
    }


    // Ramp setpoint up sparsely
    if (++softstart_loop_div_count >= SOFTSTART_SETPOINT_UPDATE_DIV) 
    {
        softstart_loop_div_count = 0;
    
        float new_setpoint = setpoint + SOFTSTART_SETPOINT_STEP;

        // Clamp to target.
        if (new_setpoint >= SOFTSTART_SETPOINT_TARGET) 
        {
            new_setpoint = SOFTSTART_SETPOINT_TARGET;

            if (target_reached_counter < 0xFFFF) 
            {
                target_reached_counter++;
            }
        }
        else 
        {
            target_reached_counter = 0;
        }
        
        // Apply ramp
        setpoint = new_setpoint;

    }

    // Do current loop calculations.
    if (AdcaRegs.ADCINTFLG.bit.ADCINT1) 
    {
        DCL_current_loop_C7();
    }


    // Stay at target a few cycles before handing over to run state.
    if (setpoint == SOFTSTART_SETPOINT_TARGET && target_reached_counter >= SOFTSTART_TARGET_CONFIDENCE_COUNT) 
    {
        softstart_loop_div_count = 0;
        target_reached_counter = 0;

        // Set the initial setpoint
        setpoint = INITIAL_SETPOINT;

        state_Ptr = &run_state;
    }
}

void run_state()
{
    state = 4;

    // Catch any hard trip and go safe
    if (EPwm1Regs.TZOSTFLG.all | EPwm2Regs.TZOSTFLG.all | EPwm3Regs.TZOSTFLG.all | EPwm4Regs.TZOSTFLG.all) 
    {
        state_Ptr = &fault_state;
        return;
    }
    
    if (AdcaRegs.ADCINTFLG.bit.ADCINT1)
    {
        // GpioDataRegs.GPATOGGLE.bit.GPIO24 = 1;
        //  debug - check timing
        //  GpioDataRegs.GPASET.bit.GPIO23 = 1;
        //  uint16_t val = AdcaResultRegs.ADCRESULT0;
        // current_loop_all_2(); DCL_current_loop_C7();
        // AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;
        //  clear interrupt flag gets done at the end of my DCL function...
        //  GpioDataRegs.GPACLEAR.bit.GPIO23 = 1;
        DCL_current_loop_C7(); 
    }
}

void fault_state()
{
    state = 99;
    // Wallow in self-pity - just keep whining.

    somethings_rotten_in_the_state_of_la_la_land = true;
    while (1)
        NOP;
}

void system_init()
{
    // ================== Run the DriverLib/SysConfig initializations ===================
    Device_init();

    // Initialize device clock and peripherals
    Device_initGPIO();

    // Disable pin locks, enable pull-ups.
    Interrupt_initModule();

    // Init PIE, clear PIE. Disables CPU interrupts.
    Interrupt_initVectorTable();

    // Init PIE vector table w. pointers to ISR's
    Board_init();

    // PinMux and Peripheral Initialization.
    C2000Ware_libraries_init(); // C2000Ware Library initialization. (DCL, FPU)

    // ================== End of DriverLib/SysConfig initializations ===================
    // ================== Fix various issues from SysConfig ===================

    
    // Configure pwm1 to use the one-shot latch for the sync out pulse.
    EPWM_enableOneShotSync(EPWM1_BASE);

    // Set CMPSS up for a hard overcurrent one-shot protection
    CmpssLite3Regs.DACHVALS.bit.DACVAL = INITIAL_ONESHOT_CMPSS_VALUE;
    // EALLOW; 
    // EPwm1Regs.TZSEL.bit.DCAEVT1 = 1;
    // EDIS;


    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    EALLOW;
    EINT;
    ERTM;
    EDIS;
}

// Function to determine if we are ready to do a softstart
bool system_ready()
{
    return true;
}
