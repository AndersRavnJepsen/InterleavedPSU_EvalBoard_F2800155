/*******************************************************
 * @ Author: ARJ
 * @ Create Time: 2025-08-19 11:03:20
 * @ Modified by: ARJ
 * @ Modified time: 2025-08-19 12:21:59
 * @ Description:
 *******************************************************/

#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"
#include "F280015x_Device.h"          // Header for bitfield commands.

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

    for (;;)
    {
    }
}
