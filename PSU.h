#ifndef PSU_H
#define PSU_H

#include "c2000ware_libraries.h"
#include "f28x_project.h"
#include "Config.h"
//#include "ADC.h"

//#include "DCLF32.h"

// Using Software Frequency Response Analyzer
// #include "sfra_f32.h"
// #include <stddef.h>
// #include "sfra_f32.h"
// #include "sfra_gui_scicomms_driverlib.h"



// #define KP 0.001f
// #define KI 0.0001f
// #define INTEGRAL_MAX 1.0f  //4095.0f
// #define INTEGRAL_MIN 0.0f
#define MAX_ADC_INV 0.0002442002f // precomputed 1 / 4095.0f

#define SOFTSTART_SETPOINT_TARGET (2000.0f)
#define SOFTSTART_SETPOINT_STEP (1.0f)  // How much to increase setpoint each time.
#define SOFTSTART_INITIAL_SETPOINT (150.0f) // Softstart starts from this setpoint, to avoid too small duty initially.
#define SOFTSTART_SETPOINT_UPDATE_DIV (240) // Cycles between setpoint increments.
#define SOFTSTART_TARGET_CONFIDENCE_COUNT (10)


// Use an enum for indexing the integrals and compare value arrays.
enum pwm_index
{
    ePWM1, ePWM2, ePWM3, ePWM4
};


// Enum for tracking states
enum psu_state
{
    STANDBY_STATE,
    SOFTSTART_STATE,
    ON_STATE,
    FAULT_STATE
};

enum psu_fault
{
    NO_FAULT,
    SS_TZ_OSHT,
    ON_TZ_OSHT
};

extern float setpoint;
extern float integrals[4];

extern float inv_period;
extern float period;
extern float pwm_scale;
extern float pwm_compare[4];    // Keeping local copy of compare register values - faster access

//extern enum psu_state current_state;


// PROTOTYPES
void init_psu_values();
bool system_ready();

// ============================== STATE MACHINE SETUP ====================================================
// Initialize state pointers
extern void (*state_Ptr)(); // Base States pointer

// Declare State function prototypes
void init_state();
void standby_state();
void softStart_state();
void on_state();
void fault_state();

// ############################### INLINE FUNCTION IMPLEMENTATIONS ###########################################

static inline void change_frequency(float new_period_value)
{
    // Calculate scaler
    float duty_scale = inv_period * new_period_value; // (1/old_period) * new_period

    // Update local period values for next frequency change + current loop
    period = new_period_value;
    inv_period = __einvf32(period);
    
    // Update pwm_scaler for current loops.
    pwm_scale = period * MAX_ADC_INV;

    // Calculate and write new compare values to local array, then write to the shadow registers (using intrinsic convertion to integer)
    pwm_compare[ePWM1] *= duty_scale;
    EPwm1Regs.CMPA.bit.CMPA = __f32toui16r(pwm_compare[ePWM1]);
    pwm_compare[ePWM2] *= duty_scale;
    EPwm2Regs.CMPA.bit.CMPA = __f32toui16r(pwm_compare[ePWM2]);
    pwm_compare[ePWM3] *= duty_scale;
    EPwm3Regs.CMPA.bit.CMPA = __f32toui16r(pwm_compare[ePWM3]);
    pwm_compare[ePWM4] *= duty_scale;
    EPwm4Regs.CMPA.bit.CMPA = __f32toui16r(pwm_compare[ePWM4]);

    // Write the new period values to shadow. (TBPRD registers are linked to ePWM1, so only one write necessary)
    uint16_t new_period_uint = __f32toui16r(period);
    EPwm1Regs.TBPRD = new_period_uint;

    // We also need to upate the phase load values
    uint16_t half_period = new_period_uint / 2;
EPwm2Regs.TBPHS.bit.TBPHS = half_period; // counts down
EPwm3Regs.TBPHS.bit.TBPHS = new_period_uint;  
EPwm4Regs.TBPHS.bit.TBPHS = half_period;    // counts up.


    // Update pwm4's CMPC, that is used for triggering the ADC (to avoid triggers on phase-load)
    //EPwm4Regs.CMPC = new_period_uint;
    
    // Call a sync
    EPwm1Regs.GLDCTL2.bit.OSHTLD = 1;   // Arm the global load latch in pwm1.
    EPwm1Regs.TBCTL2.bit.OSHTSYNC = 1;  // Fire the sync on next ZERO-event in pwm1    
}







//#pragma CODE_SECTION(DCL_current_loop_C7, "ramfuncs")
static inline void DCL_current_loop_C7()
{
    // Clear ADC end-of-sequence flag once.
    AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;

    // PHASE 1 -----------------------------------------------------------    
    // 1. Calculate mean of adc sample.
    float compare = pwm_compare[ePWM1];
    float old_duty_cycle = 1.0f - (inv_period * compare);
    float adc_avg = (float)AdcaResultRegs.ADCRESULT1 * old_duty_cycle;

    // 2. Do PI calculations and scale.
    float pi_output = DCL_runPI_C7(&pi_current1, setpoint, adc_avg); // Run the PI controller.
    // float error = setpoint - adc_avg;
    // float P = error * KP;
    // integrals[ePWM1] = __fsat(integrals[ePWM1] + (error * KI), INTEGRAL_MAX, INTEGRAL_MIN); // Anti-windup clamp
    //float PI_scaled = (P + integrals[ePWM1]) * pwm_scale;

    // 3. Clamp new compare value, and update the array copy
    //compare = __fsat(compare - PI_scaled, period, 0.0f);
    compare = period - (pi_output * period);
    pwm_compare[ePWM1] = compare;
    EPwm1Regs.CMPA.bit.CMPA = __f32toui16r(compare);


    // PHASE 2 -----------------------------------------------------------
    compare = pwm_compare[ePWM2];
    old_duty_cycle = 1.0f - (inv_period * compare);
    adc_avg = (float)AdcaResultRegs.ADCRESULT2 * old_duty_cycle;
    // error = setpoint - adc_avg;
    // P = error * KP;
    // integrals[ePWM2] = __fsat(integrals[ePWM2] + (error * KI), INTEGRAL_MAX, INTEGRAL_MIN);
    // PI_scaled = (P + integrals[ePWM2]) * pwm_scale;
    pi_output = DCL_runPI_C7(&pi_current2, setpoint, adc_avg);
    compare = period - (pi_output * period);
    pwm_compare[ePWM2] = compare;
    EPwm2Regs.CMPA.bit.CMPA = __f32toui16r(compare);

    // PHASE 3 -----------------------------------------------------------
    compare = pwm_compare[ePWM3];
    old_duty_cycle = 1.0f - (inv_period * compare);
    adc_avg = (float)AdcaResultRegs.ADCRESULT3 * old_duty_cycle;
    // error = setpoint - adc_avg;
    // P = error * KP;
    // integrals[ePWM3] = __fsat(integrals[ePWM3] + (error * KI), INTEGRAL_MAX, INTEGRAL_MIN);
    // PI_scaled = (P + integrals[ePWM3]) * pwm_scale;
    pi_output = DCL_runPI_C7(&pi_current3, setpoint, adc_avg);
    compare = period - (pi_output * period);
    pwm_compare[ePWM3] = compare;
    EPwm3Regs.CMPA.bit.CMPA = __f32toui16r(compare);

    // PHASE 4 -----------------------------------------------------------
    compare = pwm_compare[ePWM4];
    old_duty_cycle = 1.0f - (inv_period * compare);
    adc_avg = (float)AdcaResultRegs.ADCRESULT4 * old_duty_cycle;
    // error = setpoint - adc_avg;
    // P = error * KP;
    // integrals[ePWM4] = __fsat(integrals[ePWM4] + (error * KI), INTEGRAL_MAX, INTEGRAL_MIN);
    // PI_scaled = (P + integrals[ePWM4]) * pwm_scale;
    pi_output = DCL_runPI_C7(&pi_current4, setpoint, adc_avg);
    compare = period - (pi_output * period);
    pwm_compare[ePWM4] = compare;
    EPwm4Regs.CMPA.bit.CMPA = __f32toui16r(compare);

    // Arm and fire latch, to transfer from shadow.
    // EPwm1Regs.GLDCTL2.bit.OSHTLD  = 1;
    // EPwm1Regs.GLDCTL2.bit.GFRCLD  = 1;
    // Arm latch and do a force load to transfer from shadow.
    EPwm1Regs.GLDCTL2.bit.OSHTLD  = 1;
    EPwm2Regs.GLDCTL2.bit.OSHTLD  = 1;
    EPwm3Regs.GLDCTL2.bit.OSHTLD  = 1;
    EPwm4Regs.GLDCTL2.bit.OSHTLD  = 1;

    EPwm1Regs.GLDCTL2.bit.GFRCLD  = 1;
    EPwm2Regs.GLDCTL2.bit.GFRCLD  = 1;
    EPwm3Regs.GLDCTL2.bit.GFRCLD  = 1;
    EPwm4Regs.GLDCTL2.bit.GFRCLD  = 1;
}



// // Single channel current loop (Manual)
// static inline void current_loop()
// {
//     // 1. Clear the interrupt flag first - mandatory.
//     AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;

//     // 2. Read adc samples, and convert to float.
//     float adc_sample1 = (float)AdcaResultRegs.ADCRESULT0;

//     // 2. Calculate mean of the measurement
//     float compare = pwm_compare[ePWM1];
//     float duty_cycle = 1.0f - (inv_period * compare);
//     float adc_avg = adc_sample1 * duty_cycle;

//     // 5. Do the PI calculations and scale.
//     float error = setpoint - adc_avg;
//     float P = error * KP;
//     integrals[0] = __fsat(integrals[0] + (error * KI), INTEGRAL_MAX, INTEGRAL_MIN);    // Clamp integral for anti-windup
//     float PI_scaled = (P + integrals[0]) * pwm_scale;   // Rescale from ADC resolution to PWM resolution. (multiply by period, divide by max-adc)

//     // 6. Clamp new compare value, and update our array copy.
//     compare = __fsat(compare - PI_scaled, period, 0.0f);
//     pwm_compare[ePWM1] = compare;

//     // 7. convert to integer, and write the new value to shadow register.
//     EPwm1Regs.CMPA.bit.CMPA = __f32toui16r(compare);

//     // 8. Arm and fire latch, to transfer from shadow.
//     EPwm1Regs.GLDCTL2.bit.OSHTLD = 1; 
//     EPwm1Regs.GLDCTL2.bit.GFRCLD = 1;
// }



// // DCL library current loop
// static inline void DCL_current_loop_C4()
// {
//     // Clear ADC end-of-sequence flag once.
//     AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;

//     // PHASE 1 -----------------------------------------------------------    
//     // 1. Calculate mean of adc sample.
//     float compare = pwm_compare[ePWM1];
//     float old_duty_cycle = 1.0f - (inv_period * compare);
//     float adc_avg = (float)AdcaResultRegs.ADCRESULT1 * old_duty_cycle;

//     // 3. Do PI calculations and scale.
//     float pi_output = DCL_runPI_C4(&pi_current1, setpoint, adc_avg); // Run the PI controller.
//     // float error = setpoint - adc_avg;
//     // float P = error * KP;
//     // integrals[ePWM1] = __fsat(integrals[ePWM1] + (error * KI), INTEGRAL_MAX, INTEGRAL_MIN); // Anti-windup clamp
//     //float PI_scaled = (P + integrals[ePWM1]) * pwm_scale;

//     // 4. Clamp new compare value, and update the array copy
//     //compare = __fsat(compare - PI_scaled, period, 0.0f);
//     compare = period - (pi_output * period);
//     pwm_compare[ePWM1] = compare;
//     EPwm1Regs.CMPA.bit.CMPA = __f32toui16r(compare);


//     // PHASE 2 -----------------------------------------------------------
//     compare = pwm_compare[ePWM2];
//     old_duty_cycle = 1.0f - (inv_period * compare);
//     adc_avg = (float)AdcaResultRegs.ADCRESULT2 * old_duty_cycle;
//     // error = setpoint - adc_avg;
//     // P = error * KP;
//     // integrals[ePWM2] = __fsat(integrals[ePWM2] + (error * KI), INTEGRAL_MAX, INTEGRAL_MIN);
//     // PI_scaled = (P + integrals[ePWM2]) * pwm_scale;
//     pi_output = DCL_runPI_C4(&pi_current2, setpoint, adc_avg);
//     compare = period - (pi_output * period);
//     pwm_compare[ePWM2] = compare;
//     EPwm2Regs.CMPA.bit.CMPA = __f32toui16r(compare);

//     // PHASE 3 -----------------------------------------------------------
//     compare = pwm_compare[ePWM3];
//     old_duty_cycle = 1.0f - (inv_period * compare);
//     adc_avg = (float)AdcaResultRegs.ADCRESULT3 * old_duty_cycle;
//     // error = setpoint - adc_avg;
//     // P = error * KP;
//     // integrals[ePWM3] = __fsat(integrals[ePWM3] + (error * KI), INTEGRAL_MAX, INTEGRAL_MIN);
//     // PI_scaled = (P + integrals[ePWM3]) * pwm_scale;
//     pi_output = DCL_runPI_C4(&pi_current3, setpoint, adc_avg);
//     compare = period - (pi_output * period);
//     pwm_compare[ePWM3] = compare;
//     EPwm3Regs.CMPA.bit.CMPA = __f32toui16r(compare);

//     // PHASE 4 -----------------------------------------------------------
//     compare = pwm_compare[ePWM4];
//     old_duty_cycle = 1.0f - (inv_period * compare);
//     adc_avg = (float)AdcaResultRegs.ADCRESULT4 * old_duty_cycle;
//     // error = setpoint - adc_avg;
//     // P = error * KP;
//     // integrals[ePWM4] = __fsat(integrals[ePWM4] + (error * KI), INTEGRAL_MAX, INTEGRAL_MIN);
//     // PI_scaled = (P + integrals[ePWM4]) * pwm_scale;
//     pi_output = DCL_runPI_C4(&pi_current4, setpoint, adc_avg);
//     compare = period - (pi_output * period);
//     pwm_compare[ePWM4] = compare;
//     EPwm4Regs.CMPA.bit.CMPA = __f32toui16r(compare);

//     // Arm and fire latch, to transfer from shadow.
//     // EPwm1Regs.GLDCTL2.bit.OSHTLD  = 1;
//     // EPwm1Regs.GLDCTL2.bit.GFRCLD  = 1;
//     // Arm and fire latch, to transfer from shadow.
//     EPwm1Regs.GLDCTL2.bit.OSHTLD  = 1;
//     EPwm2Regs.GLDCTL2.bit.OSHTLD  = 1;
//     EPwm3Regs.GLDCTL2.bit.OSHTLD  = 1;
//     EPwm4Regs.GLDCTL2.bit.OSHTLD  = 1;

//     EPwm1Regs.GLDCTL2.bit.GFRCLD  = 1;
//     EPwm2Regs.GLDCTL2.bit.GFRCLD  = 1;
//     EPwm3Regs.GLDCTL2.bit.GFRCLD  = 1;
//     EPwm4Regs.GLDCTL2.bit.GFRCLD  = 1;
// }


// static inline void current_loop_all_2()
// {
//     // Clear ADC end-of-sequence flag once.
//     AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;

//     // PHASE 1 -----------------------------------------------------------    
//     // 1. Calculate mean of adc sample.
//     float compare = pwm_compare[ePWM1];
//     float old_duty_cycle = 1.0f - (inv_period * compare);
//     float adc_avg = (float)AdcaResultRegs.ADCRESULT1 * old_duty_cycle;

//     // 3. Do PI calculations and scale.
//     float error = setpoint - adc_avg;
//     float P = error * KP;
//     integrals[ePWM1] = __fsat(integrals[ePWM1] + (error * KI), INTEGRAL_MAX, INTEGRAL_MIN); // Anti-windup clamp
//     //float PI_scaled = (P + integrals[ePWM1]) * pwm_scale; // no more scale - aim for pi output = 0-1 range.

//     float pi_output = __fsat(P + integrals[ePWM1], 1.0f, 0.0f);

//     // 4. Clamp new compare value, and update the array copy
//     //compare = __fsat(compare - PI_scaled, period, 0.0f);
//     compare = period - (pi_output * period);
//     pwm_compare[ePWM1] = compare;
//     EPwm1Regs.CMPA.bit.CMPA = __f32toui16r(compare);

//     // PHASE 2 -----------------------------------------------------------
//     compare = pwm_compare[ePWM2];
//     old_duty_cycle = 1.0f - (inv_period * compare);
//     adc_avg = (float)AdcaResultRegs.ADCRESULT2 * old_duty_cycle;
//     error = setpoint - adc_avg;
//     P = error * KP;
//     integrals[ePWM2] = __fsat(integrals[ePWM2] + (error * KI), INTEGRAL_MAX, INTEGRAL_MIN);
//     //PI_scaled = (P + integrals[ePWM2]) * pwm_scale;
//     pi_output = __fsat(P + integrals[ePWM2], 1.0f, 0.0f);
//     //compare = __fsat(compare - PI_scaled, period, 0.0f);
//     compare = period - (pi_output * period);
//     pwm_compare[ePWM2] = compare;
//     EPwm2Regs.CMPA.bit.CMPA = __f32toui16r(compare);

//     // PHASE 3 -----------------------------------------------------------
//     compare = pwm_compare[ePWM3];
//     old_duty_cycle = 1.0f - (inv_period * compare);
//     adc_avg = (float)AdcaResultRegs.ADCRESULT3 * old_duty_cycle;
//     error = setpoint - adc_avg;
//     P = error * KP;
//     integrals[ePWM3] = __fsat(integrals[ePWM3] + (error * KI), INTEGRAL_MAX, INTEGRAL_MIN);
//     pi_output = __fsat(P + integrals[ePWM3], 1.0f, 0.0f);
//     //PI_scaled = (P + integrals[ePWM3]) * pwm_scale;
//     //compare = __fsat(compare - PI_scaled, period, 0.0f);
//     compare = period - (pi_output * period);
//     pwm_compare[ePWM3] = compare;
//     EPwm3Regs.CMPA.bit.CMPA = __f32toui16r(compare);

//     // PHASE 4 -----------------------------------------------------------
//     compare = pwm_compare[ePWM4];
//     old_duty_cycle = 1.0f - (inv_period * compare);
//     adc_avg = (float)AdcaResultRegs.ADCRESULT4 * old_duty_cycle;
//     error = setpoint - adc_avg;
//     P = error * KP;
//     integrals[ePWM4] = __fsat(integrals[ePWM4] + (error * KI), INTEGRAL_MAX, INTEGRAL_MIN);
//     pi_output = __fsat(P + integrals[ePWM4], 1.0f, 0.0f);
//     //PI_scaled = (P + integrals[ePWM4]) * pwm_scale;
//     //compare = __fsat(compare - PI_scaled, period, 0.0f);
//     compare = period - (pi_output * period);
//     pwm_compare[ePWM4] = compare;
//     EPwm4Regs.CMPA.bit.CMPA = __f32toui16r(compare);

//     // Arm and fire latch, to transfer from shadow.
//     EPwm1Regs.GLDCTL2.bit.OSHTLD  = 1;
//     EPwm2Regs.GLDCTL2.bit.OSHTLD  = 1;
//     EPwm3Regs.GLDCTL2.bit.OSHTLD  = 1;
//     EPwm4Regs.GLDCTL2.bit.OSHTLD  = 1;

//     EPwm1Regs.GLDCTL2.bit.GFRCLD  = 1;
//     EPwm2Regs.GLDCTL2.bit.GFRCLD  = 1;
//     EPwm3Regs.GLDCTL2.bit.GFRCLD  = 1;
//     EPwm4Regs.GLDCTL2.bit.GFRCLD  = 1;
//     //EPWM_startOneShotSync(EPWM1_BASE);

// }


#endif /* PSU_H */
