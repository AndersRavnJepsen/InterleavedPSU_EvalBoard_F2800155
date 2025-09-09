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
// pi_current1 variables
//
DCL_PI pi_current1 = PI_DEFAULTS;
DCL_PI_SPS pi_current1_sps = PI_SPS_DEFAULTS;
DCL_CSS pi_current1_css = DCL_CSS_DEFAULTS;
//
// pi_current2 variables
//
DCL_PI pi_current2 = PI_DEFAULTS;
DCL_PI_SPS pi_current2_sps = PI_SPS_DEFAULTS;
DCL_CSS pi_current2_css = DCL_CSS_DEFAULTS;
//
// pi_current3 variables
//
DCL_PI pi_current3 = PI_DEFAULTS;
DCL_PI_SPS pi_current3_sps = PI_SPS_DEFAULTS;
DCL_CSS pi_current3_css = DCL_CSS_DEFAULTS;
//
// pi_current4 variables
//
DCL_PI pi_current4 = PI_DEFAULTS;
DCL_PI_SPS pi_current4_sps = PI_SPS_DEFAULTS;
DCL_CSS pi_current4_css = DCL_CSS_DEFAULTS;
void pi_current1_init(){
    //
    // pi_current1 settings
    //
    pi_current1.sps = &pi_current1_sps;
    pi_current1.css = &pi_current1_css;
    pi_current1.Kp = 0.001f;
    pi_current1.Ki = 0.0001f;
    pi_current1.i10 = 0.0f;
    pi_current1.Umax = 1.0f;
    pi_current1.Umin = 0.0f;
    pi_current1.i6 = 1.0f;
    pi_current1.i11 = 0.0f;
    pi_current1.Imax = 1.0f;
    pi_current1.Imin = 0.0f;
}
void pi_current2_init(){
    //
    // pi_current2 settings
    //
    pi_current2.sps = &pi_current2_sps;
    pi_current2.css = &pi_current2_css;
    pi_current2.Kp = 0.001f;
    pi_current2.Ki = 0.0001f;
    pi_current2.i10 = 0.0f;
    pi_current2.Umax = 1.0f;
    pi_current2.Umin = 0.0f;
    pi_current2.i6 = 1.0f;
    pi_current2.i11 = 0.0f;
    pi_current2.Imax = 1.0f;
    pi_current2.Imin = 0.0f;
}
void pi_current3_init(){
    //
    // pi_current3 settings
    //
    pi_current3.sps = &pi_current3_sps;
    pi_current3.css = &pi_current3_css;
    pi_current3.Kp = 0.001f;
    pi_current3.Ki = 0.0001f;
    pi_current3.i10 = 0.0f;
    pi_current3.Umax = 1.0f;
    pi_current3.Umin = 0.0f;
    pi_current3.i6 = 1.0f;
    pi_current3.i11 = 0.0f;
    pi_current3.Imax = 1.0f;
    pi_current3.Imin = 0.0f;
}
void pi_current4_init(){
    //
    // pi_current4 settings
    //
    pi_current4.sps = &pi_current4_sps;
    pi_current4.css = &pi_current4_css;
    pi_current4.Kp = 0.001f;
    pi_current4.Ki = 0.0001f;
    pi_current4.i10 = 0.0f;
    pi_current4.Umax = 1.0f;
    pi_current4.Umin = 0.0f;
    pi_current4.i6 = 1.0f;
    pi_current4.i11 = 0.0f;
    pi_current4.Imax = 1.0f;
    pi_current4.Imin = 0.0f;
}
void CONTROLLER_init(){
    pi_current1_init();
    pi_current2_init();
    pi_current3_init();
    pi_current4_init();
}

void FFR_init()
{

}

