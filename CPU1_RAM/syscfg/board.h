/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// EPWM2 -> ePWM2 Pinmux
//
//
// EPWM2_A - GPIO Settings
//
#define GPIO_PIN_EPWM2_A 41
#define ePWM2_EPWMA_GPIO 41
#define ePWM2_EPWMA_PIN_CONFIG GPIO_41_EPWM2_A
//
// EPWM2_B - GPIO Settings
//
#define GPIO_PIN_EPWM2_B 40
#define ePWM2_EPWMB_GPIO 40
#define ePWM2_EPWMB_PIN_CONFIG GPIO_40_EPWM2_B

//
// EPWM3 -> ePWM3 Pinmux
//
//
// EPWM3_A - GPIO Settings
//
#define GPIO_PIN_EPWM3_A 0
#define ePWM3_EPWMA_GPIO 0
#define ePWM3_EPWMA_PIN_CONFIG GPIO_0_EPWM3_A
//
// EPWM3_B - GPIO Settings
//
#define GPIO_PIN_EPWM3_B 1
#define ePWM3_EPWMB_GPIO 1
#define ePWM3_EPWMB_PIN_CONFIG GPIO_1_EPWM3_B

//
// EPWM4 -> ePWM4 Pinmux
//
//
// EPWM4_A - GPIO Settings
//
#define GPIO_PIN_EPWM4_A 2
#define ePWM4_EPWMA_GPIO 2
#define ePWM4_EPWMA_PIN_CONFIG GPIO_2_EPWM4_A
//
// EPWM4_B - GPIO Settings
//
#define GPIO_PIN_EPWM4_B 3
#define ePWM4_EPWMB_GPIO 3
#define ePWM4_EPWMB_PIN_CONFIG GPIO_3_EPWM4_B

//
// EPWM1 -> ePWM1 Pinmux
//
//
// EPWM1_A - GPIO Settings
//
#define GPIO_PIN_EPWM1_A 4
#define ePWM1_EPWMA_GPIO 4
#define ePWM1_EPWMA_PIN_CONFIG GPIO_4_EPWM1_A
//
// EPWM1_B - GPIO Settings
//
#define GPIO_PIN_EPWM1_B 5
#define ePWM1_EPWMB_GPIO 5
#define ePWM1_EPWMB_PIN_CONFIG GPIO_5_EPWM1_B
//
// GPIO28 - GPIO Settings
//
#define gpio28_GPIO_PIN_CONFIG GPIO_28_GPIO28

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define ePWM2_BASE EPWM2_BASE
#define ePWM2_TBPRD 600
#define ePWM2_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define ePWM2_TBPHS 300
#define ePWM2_CMPA 540
#define ePWM2_CMPB 0
#define ePWM2_CMPC 0
#define ePWM2_CMPD 0
#define ePWM2_DBRED 0
#define ePWM2_DBFED 0
#define ePWM2_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ePWM2_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ePWM2_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define ePWM3_BASE EPWM3_BASE
#define ePWM3_TBPRD 600
#define ePWM3_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define ePWM3_TBPHS 600
#define ePWM3_CMPA 540
#define ePWM3_CMPB 0
#define ePWM3_CMPC 0
#define ePWM3_CMPD 0
#define ePWM3_DBRED 0
#define ePWM3_DBFED 0
#define ePWM3_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ePWM3_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ePWM3_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define ePWM4_BASE EPWM4_BASE
#define ePWM4_TBPRD 600
#define ePWM4_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define ePWM4_TBPHS 300
#define ePWM4_CMPA 540
#define ePWM4_CMPB 0
#define ePWM4_CMPC 0
#define ePWM4_CMPD 0
#define ePWM4_DBRED 0
#define ePWM4_DBFED 0
#define ePWM4_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ePWM4_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ePWM4_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define ePWM1_BASE EPWM1_BASE
#define ePWM1_TBPRD 600
#define ePWM1_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define ePWM1_TBPHS 0
#define ePWM1_CMPA 450
#define ePWM1_CMPB 1
#define ePWM1_CMPC 0
#define ePWM1_CMPD 0
#define ePWM1_DBRED 0
#define ePWM1_DBFED 0
#define ePWM1_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ePWM1_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ePWM1_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define gpio28 28
void gpio28_init();

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// SYSCTL Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	EPWM_init();
void	GPIO_init();
void	SYNC_init();
void	SYSCTL_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
