#include "PSU.h"

float setpoints[4] = { INITIAL_SETPOINT, INITIAL_SETPOINT, INITIAL_SETPOINT, INITIAL_SETPOINT };
float integrals[4] = { 0.0f };

// precompute inverse period every time we change frequency:
float inv_period = 0.0f;
float period = 0.0f;
float pwm_scale = 0.0f;;

float pwm_compare[4] = { INITIAL_PERIOD_COUNT, INITIAL_PERIOD_COUNT, INITIAL_PERIOD_COUNT, INITIAL_PERIOD_COUNT };



void init_psu_values()  // must be called after pwm is initialized
{
    period = (float)EPwm1Regs.TBPRD;    // pwm2-4's periods are linked to pwm1.
    inv_period = __einvf32(period); // Calculates 1/period
    pwm_scale = period * MAX_ADC_INV;
}
