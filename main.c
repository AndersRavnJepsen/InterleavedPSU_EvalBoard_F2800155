/*******************************************************
 * @ Author: ARJ
 * @ Create Time: 2025-08-19 11:03:20
 * @ Modified by: ARJ
 * @ Modified time: 2025-09-04 15:36:14
 * @ Description:
 *******************************************************/

#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"
#include "F280015x_Device.h"          // Header for bitfield commands.

#include "Config.h"

// ============ Prototypes ==============
void system_init();

// ========================================= TRIP ==============================================================
// TEMPORARY TRIP SETUP TO ENSURE PWM SHUTDOWN AFTER SPECIFIED CLOCK CYCLES 
static inline void TZ_Init_AllPWM_ForceLow();
static inline void TZ_TripAll_OneShot();
static inline void TZ_ClearAll_OneShot();
// ============================================ TRIP END =====================================================




void main()
{
    // Device_init();               // Initialize device clock and peripherals
    // Device_initGPIO();           // Disable pin locks and enable internal pull-ups.
    // Interrupt_initModule();      // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    // Interrupt_initVectorTable(); // Initialize the PIE vector table with pointers to the shell Interrupt Service Routines (ISR).
    // Board_init();                // Configure ePWM1, ePWM2, and TZ GPIOs/Modules
    // C2000Ware_libraries_init();  // C2000Ware Library initialization
system_init();


    EALLOW;
    //EPWM_enableOneShotSync(EPWM1_BASE);

    //EPWM_forceSyncPulse(EPWM1_BASE);
    
// Clear any latched trips
TZ_ClearAll_OneShot();
// Force pwm low on a trip
TZ_Init_AllPWM_ForceLow();

// fixings...
EALLOW;
EPwm1Regs.TZCLR.bit.OST = 1;   EPwm1Regs.TZCLR.bit.CBC = 1;
EPwm1Regs.TZCLR.bit.DCAEVT1 = 1; EPwm1Regs.TZCLR.bit.DCAEVT2 = 1;
EPwm1Regs.TZCLR.bit.DCBEVT1 = 1; EPwm1Regs.TZCLR.bit.DCBEVT2 = 1;
EDIS;


    // At the moment we dont run an interrupt for the ADC, to avoid the overhead.
    // Instead we simply check the flag in each loop, to see if the four measurements are ready.
    AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1; // Make sure INT1 flag is cleared initially.

    // EALLOW;
    // CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    // EDIS;

    // Fetch 12 samples. then stop and print them out.


    // Test, run for a short while, then disable pwms
    //SysCtl_delay(3000);


// Check what trips
volatile uint16_t flg   = EPwm1Regs.TZFLG.all;
volatile uint16_t ost   = EPwm1Regs.TZOSTFLG.all;
volatile uint16_t cbc   = EPwm1Regs.TZCBCFLG.all;



// Trip to stop pwms
//TZ_TripAll_OneShot();

    // EALLOW;
    // CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;
    // EDIS;
#define TEST_CYCLES 26

    unsigned int count = 0;
    volatile int16_t adcvalues[TEST_CYCLES] = {};
    volatile float32_t volts[TEST_CYCLES] = {};
    volatile float32_t amps[TEST_CYCLES] = {};
    const float32_t volt_step = 0.1561;
    const float32_t amp_step = 0.0031227;
    
    while(1)
    {
        //__asm(" NOP"); // wallow in self-pity.

        if (AdcaRegs.ADCINTFLG.bit.ADCINT1)
        {
            //GpioDataRegs.GPASET.bit.GPIO28 = 1;


            //adcvalues[count] = AdcaResultRegs.ADCRESULT1;
            adcvalues[count] = AdcaResultRegs.ADCPPB1RESULT.bit.PPBRESULT;
            volts[count] = AdcaResultRegs.ADCPPB1RESULT.bit.PPBRESULT * volt_step;
            amps[count] = AdcaResultRegs.ADCPPB1RESULT.bit.PPBRESULT * amp_step;
            
            count++;

            if (count >= TEST_CYCLES)
            {
                TZ_TripAll_OneShot();
                break;
            }
            else
                AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1; // clear interrupt flag

            //GpioDataRegs.GPACLEAR.bit.GPIO28 = 1;

        }

    }

    ESTOP0; // do a breakpoint

}


// #############################################################################################################
// #################################### IMLEMENTATIONS BELOW HERE ##############################################
// #############################################################################################################

// ========================================= TRIP ==============================================================
// TEMPORARY TRIP SETUP TO ENSURE PWM SHUTDOWN AFTER SPECIFIED CLOCK CYCLES 
static inline void TZ_Init_AllPWM_ForceLow()
{
    EALLOW;
    EPwm1Regs.TZCTL.bit.TZA = EPWM_TZ_ACTION_LOW; EPwm1Regs.TZCTL.bit.TZB = EPWM_TZ_ACTION_LOW;
    EPwm2Regs.TZCTL.bit.TZA = EPWM_TZ_ACTION_LOW; EPwm2Regs.TZCTL.bit.TZB = EPWM_TZ_ACTION_LOW;
    EPwm3Regs.TZCTL.bit.TZA = EPWM_TZ_ACTION_LOW; EPwm3Regs.TZCTL.bit.TZB = EPWM_TZ_ACTION_LOW;
    EPwm4Regs.TZCTL.bit.TZA = EPWM_TZ_ACTION_LOW; EPwm4Regs.TZCTL.bit.TZB = EPWM_TZ_ACTION_LOW;

    EDIS;
}

static inline void TZ_TripAll_OneShot()
{
    EALLOW;
    EPwm1Regs.TZFRC.bit.OST = 1;
    EPwm2Regs.TZFRC.bit.OST = 1;
    EPwm3Regs.TZFRC.bit.OST = 1;
    EPwm4Regs.TZFRC.bit.OST = 1;
    EDIS;
}

static inline void TZ_ClearAll_OneShot()
{
    EALLOW;
    EPwm1Regs.TZCLR.bit.OST = 1;
    EPwm2Regs.TZCLR.bit.OST = 1;
    EPwm3Regs.TZCLR.bit.OST = 1;
    EPwm4Regs.TZCLR.bit.OST = 1;
    EDIS;
}
// ============================================ TRIP END =====================================================

void system_init()
{
    // ================== Run the DriverLib/SysConfig initializations ===================
    Device_init();               // Initialize device clock and peripherals
    Device_initGPIO();           // Disable pin locks, enable pull-ups.
    Interrupt_initModule();      // Init PIE, clear PIE. Disables CPU interrupts.
    Interrupt_initVectorTable(); // Init PIE vector table w. pointers to ISR's
    Board_init();                // PinMux and Peripheral Initialization.
    C2000Ware_libraries_init();  // C2000Ware Library initialization. (DCL, FPU)

    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    EINT;
    ERTM;
    // ================== End of  DriverLib/SysConfig initializations ===================

    // ================== Fix various issues from SysConfig ===================
    // Pwm2-4 would initially be high. Force low.
    EALLOW;

    // Hold pwm outputs LOW, while we fix the configuration.
    EPwm1Regs.AQCSFRC.bit.CSFA = 1; 
    EPwm2Regs.AQCSFRC.bit.CSFA = 1;
    EPwm3Regs.AQCSFRC.bit.CSFA = 1;
    EPwm4Regs.AQCSFRC.bit.CSFA = 1;

    // Disable ADC triggers while configuring:
    EPwm1Regs.ETSEL.bit.SOCAEN = 0;
    EPwm2Regs.ETSEL.bit.SOCAEN = 0;
    EPwm3Regs.ETSEL.bit.SOCAEN = 0;
    EPwm4Regs.ETSEL.bit.SOCAEN = 0;

    // Configure pwm1 to use the one-shot latch for the sync out pulse.
    EPWM_enableOneShotSync(EPWM1_BASE);

    // Now, set the initial top counter value (TBPRD) and the compare value (CMPA) from definitions in Config.h
    EPWM_setTimeBasePeriod(ePWM1_BASE, INITIAL_PERIOD_COUNT); // Pwm2-4 period are linked to pwm1.
    EPWM_setCounterCompareValue(ePWM4_BASE, EPWM_COUNTER_COMPARE_A, INITIAL_COMPARE_VALUE);
    EPWM_setCounterCompareValue(ePWM3_BASE, EPWM_COUNTER_COMPARE_A, INITIAL_COMPARE_VALUE);
    EPWM_setCounterCompareValue(ePWM2_BASE, EPWM_COUNTER_COMPARE_A, INITIAL_COMPARE_VALUE);
    EPWM_setCounterCompareValue(ePWM1_BASE, EPWM_COUNTER_COMPARE_A, INITIAL_COMPARE_VALUE);

    // Ensure master starts at CTR=0 (while TBCLK stopped)
    EPwm1Regs.TBCTR = 0;

    // Start TBCLK to let the pwm's transfer values from shadow to active registers.
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;

    // Force a sync pulse, to let pwm2-4 fire a global load event for transfering TBPRD and CMPA values from shadow.
    EPWM_forceSyncPulse(EPWM1_BASE);

    // 8) Small delay then release continuous force
    EDIS;
    SysCtl_delay(64);
    EALLOW;
    EPwm1Regs.AQCSFRC.bit.CSFA = 0;
    EPwm2Regs.AQCSFRC.bit.CSFA = 0;
    EPwm3Regs.AQCSFRC.bit.CSFA = 0;
    EPwm4Regs.AQCSFRC.bit.CSFA = 0;

    // 9) Re-enable SOCA if desired (and set source/prescale as needed)
    EPwm1Regs.ETSEL.bit.SOCAEN = 1; EPwm1Regs.ETPS.bit.SOCAPRD = 1;
    EPwm2Regs.ETSEL.bit.SOCAEN = 1; EPwm2Regs.ETPS.bit.SOCAPRD = 1;
    EPwm3Regs.ETSEL.bit.SOCAEN = 1; EPwm3Regs.ETPS.bit.SOCAPRD = 1;
    EPwm4Regs.ETSEL.bit.SOCAEN = 1; EPwm4Regs.ETPS.bit.SOCAPRD = 1;
    EDIS;

}

