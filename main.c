/*******************************************************
 * @ Author: ARJ
 * @ Create Time: 2025-08-19 11:03:20
 * @ Modified by: ARJ
 * @ Modified time: 2025-09-16 15:26:59
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



void main()
{
    // Run the system initializations. Some settings (like initial duty cycle) are overwritten by settings in Config.h system_init();
    system_init();

    // At the moment we dont run an interrupt for the ADC, to avoid the overhead.
    // Instead we simply check the flag in each loop, to see if the four measurements are ready.
    AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;


    // State-machine function pointer initialization
    state_Ptr = &standby_state;

    while (1)
    {
        // State machine entry & exit point
        (*state_Ptr)(); // jump to a state function
    }
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

    // Next, fix various settings.
    // Configure pwm1 to use the one-shot latch for the sync out pulse.
    EPWM_enableOneShotSync(EPWM1_BASE);

    // // Set CMPSS up for a hard overcurrent one-shot protection
    // CmpssLite3Regs.DACHVALS.bit.DACVAL = INITIAL_ONESHOT_CMPSS_VALUE;

    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    EALLOW;
    EINT;
    ERTM;
    EDIS;

    // Force PWM outputs LOW and disable ADC triggers while fixing.
    EPwm1Regs.AQCSFRC.bit.CSFA = 1;
    EPwm2Regs.AQCSFRC.bit.CSFA = 1;
    EPwm3Regs.AQCSFRC.bit.CSFA = 1;
    EPwm4Regs.AQCSFRC.bit.CSFA = 1;

    EPwm1Regs.ETSEL.bit.SOCAEN = 0;
    EPwm2Regs.ETSEL.bit.SOCAEN = 0;
    EPwm3Regs.ETSEL.bit.SOCAEN = 0;
    EPwm4Regs.ETSEL.bit.SOCAEN = 0;

    // Stop TBCLK (timebase clock sync) while we write period and compare values.
    EALLOW;
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;
    EDIS;

    // Load initial period/compare values.
    EPWM_setTimeBasePeriod(ePWM1_BASE, INITIAL_PERIOD_COUNT); // slaves are linked to EPWM1 if configured
    EPWM_setCounterCompareValue(ePWM2_BASE, EPWM_COUNTER_COMPARE_A, INITIAL_COMPARE_VALUE);
    EPWM_setCounterCompareValue(ePWM3_BASE, EPWM_COUNTER_COMPARE_A, INITIAL_COMPARE_VALUE);
    EPWM_setCounterCompareValue(ePWM4_BASE, EPWM_COUNTER_COMPARE_A, INITIAL_COMPARE_VALUE);
    EPWM_setCounterCompareValue(ePWM1_BASE, EPWM_COUNTER_COMPARE_A, INITIAL_COMPARE_VALUE);

    // Ensure the "master" pwm counter is zero.
    EPwm1Regs.TBCTR = 0;

    // Start TBCLK and broadcast a sync so slaves update their TBPRD/CMP and align.
    EALLOW;
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    EDIS;

    // Force a sync pulse, to let pwm2-4 fire a global load event for transfering TBPRD and CMPA values from their shadow.
    EPWM_forceSyncPulse(EPWM1_BASE);

init_psu_values();  // Initializes values needed for the psu calculations.

    // short tea-time break. (let stuff settle.)
    SysCtl_delay(64);
}


