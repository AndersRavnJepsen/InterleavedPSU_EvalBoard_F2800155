/*
 * Copyright (c) 2021 Texas Instruments Incorporated - http://www.ti.com
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

#include "c2000ware_libraries.h"


void C2000Ware_libraries_init()
{
    CONTROLLER_init();
    FFR_init();
}


//
// DCL CONTROLLER
//
//
// pi1 variables
//
DCL_PI pi1 = PI_DEFAULTS;
DCL_PI_SPS pi1_sps = PI_SPS_DEFAULTS;
DCL_CSS pi1_css = DCL_CSS_DEFAULTS;
//
// pi2 variables
//
DCL_PI pi2 = PI_DEFAULTS;
DCL_PI_SPS pi2_sps = PI_SPS_DEFAULTS;
DCL_CSS pi2_css = DCL_CSS_DEFAULTS;
//
// pi3 variables
//
DCL_PI pi3 = PI_DEFAULTS;
DCL_PI_SPS pi3_sps = PI_SPS_DEFAULTS;
DCL_CSS pi3_css = DCL_CSS_DEFAULTS;
//
// pi4 variables
//
DCL_PI pi4 = PI_DEFAULTS;
DCL_PI_SPS pi4_sps = PI_SPS_DEFAULTS;
DCL_CSS pi4_css = DCL_CSS_DEFAULTS;
void pi1_init(){
    //
    // pi1 settings
    //
    pi1.sps = &pi1_sps;
    pi1.css = &pi1_css;
    pi1.Kp = 0.001f;
    pi1.Ki = 0.0001f;
    pi1.i10 = 0.0f;
    pi1.Umax = 1.0f;
    pi1.Umin = 0.0f;
    pi1.i6 = 1.0f;
    pi1.i11 = 0.0f;
    pi1.Imax = 1.0f;
    pi1.Imin = 0.0f;
}
void pi2_init(){
    //
    // pi2 settings
    //
    pi2.sps = &pi2_sps;
    pi2.css = &pi2_css;
    pi2.Kp = 0.001f;
    pi2.Ki = 0.0001f;
    pi2.i10 = 0.0f;
    pi2.Umax = 1.0f;
    pi2.Umin = 0.0f;
    pi2.i6 = 1.0f;
    pi2.i11 = 0.0f;
    pi2.Imax = 1.0f;
    pi2.Imin = 0.0f;
}
void pi3_init(){
    //
    // pi3 settings
    //
    pi3.sps = &pi3_sps;
    pi3.css = &pi3_css;
    pi3.Kp = 0.001f;
    pi3.Ki = 0.0001f;
    pi3.i10 = 0.0f;
    pi3.Umax = 1.0f;
    pi3.Umin = 0.0f;
    pi3.i6 = 1.0f;
    pi3.i11 = 0.0f;
    pi3.Imax = 1.0f;
    pi3.Imin = 0.0f;
}
void pi4_init(){
    //
    // pi4 settings
    //
    pi4.sps = &pi4_sps;
    pi4.css = &pi4_css;
    pi4.Kp = 0.001f;
    pi4.Ki = 0.0001f;
    pi4.i10 = 0.0f;
    pi4.Umax = 1.0f;
    pi4.Umin = 0.0f;
    pi4.i6 = 1.0f;
    pi4.i11 = 0.0f;
    pi4.Imax = 1.0f;
    pi4.Imin = 0.0f;
}
void CONTROLLER_init(){
    pi1_init();
    pi2_init();
    pi3_init();
    pi4_init();
}

void FFR_init()
{

}

