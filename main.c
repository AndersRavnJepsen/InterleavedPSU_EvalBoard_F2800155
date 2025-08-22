/*******************************************************
 * @ Author: ARJ
 * @ Create Time: 2025-08-19 11:03:20
 * @ Modified by: ARJ
 * @ Modified time: 2025-08-22 10:58:25
 * @ Description:
 *******************************************************/

#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"
#include "F280015x_Device.h"          // Header for bitfield commands.


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

void main()
{
    Device_init();               // Initialize device clock and peripherals
    Device_initGPIO();           // Disable pin locks and enable internal pull-ups.
    Interrupt_initModule();      // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    Interrupt_initVectorTable(); // Initialize the PIE vector table with pointers to the shell Interrupt Service Routines (ISR).
    Board_init();                // Configure ePWM1, ePWM2, and TZ GPIOs/Modules
    C2000Ware_libraries_init();  // C2000Ware Library initialization

    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    EINT;
    ERTM;

    EALLOW;
    //EPWM_enableOneShotSync(EPWM1_BASE);

    //EPWM_forceSyncPulse(EPWM1_BASE);
    
// Clear any latched trips
TZ_ClearAll_OneShot();
// Force pwm low on a trip
TZ_Init_AllPWM_ForceLow();

    EALLOW;
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    EDIS;

    // Test, run for a short while, then disable pwms
    SysCtl_delay(12000);

// Trip to stop pwms
TZ_TripAll_OneShot();

    // EALLOW;
    // CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;
    // EDIS;

    while(1)
    {

    }


}
