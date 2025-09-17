#include "PSU.h"

float setpoints[4] = { INITIAL_SETPOINT, INITIAL_SETPOINT, INITIAL_SETPOINT, INITIAL_SETPOINT };
float integrals[4] = { 0.0f };

// precompute inverse period every time we change frequency:
float inv_period = 0.0f;
float period = 0.0f;
float pwm_scale = 0.0f;;

float pwm_compare[4] = { INITIAL_PERIOD_COUNT, INITIAL_PERIOD_COUNT, INITIAL_PERIOD_COUNT, INITIAL_PERIOD_COUNT };

float32_t setpoint = 0.0f;

enum psu_state current_state = STANDBY_STATE;
enum psu_fault fault = NO_FAULT;
void (*state_Ptr)();


void init_psu_values()  // must be called after pwm is initialized
{
    period = (float)EPwm1Regs.TBPRD;    // pwm2-4's periods are linked to pwm1.
    inv_period = __einvf32(period); // Calculates 1/period
    pwm_scale = period * MAX_ADC_INV;
}


// Function to determine if we are ready to ramp up.
bool system_ready()
{
    return true;
}

// ========================== STATE FUNCTIONS ============================================

void standby_state()
{
    // 0) Stay safe until we’re ready
    setpoint = 0.0f;

    // TODO: Clear integrator ?


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
    current_state = SOFTSTART_STATE;
    setpoint = SOFTSTART_INITIAL_SETPOINT;
}


// TODO: move these
static uint16_t softstart_loop_div_count = 0;
static uint16_t target_reached_counter = 0;

int ss_count = 0;
int ss_loop_count = 0;
int ss_pi_count = 0;

void softStart_state()
{
    ss_count++;

    // Fault catch — OSHT is latched; jump to FAULT if it ever triggered
    if (EPwm1Regs.TZOSTFLG.all | EPwm2Regs.TZOSTFLG.all | EPwm3Regs.TZOSTFLG.all | EPwm4Regs.TZOSTFLG.all) 
    {
        state_Ptr = &fault_state;
        current_state = FAULT_STATE;
        fault = SS_TZ_OSHT;
        return;
    }


    // Ramp setpoint up sparsely
    if (++softstart_loop_div_count >= SOFTSTART_SETPOINT_UPDATE_DIV) 
    {
        ss_loop_count++;

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

    // Do current loop calculations when ADC has finished measuring.
    if (AdcaRegs.ADCINTFLG.bit.ADCINT1) 
    {
        ss_pi_count++;
        DCL_current_loop_C7();
    }


    // Stay at target a few cycles before handing over to run state.
    if (setpoint == SOFTSTART_SETPOINT_TARGET && target_reached_counter >= SOFTSTART_TARGET_CONFIDENCE_COUNT) 
    {
        softstart_loop_div_count = 0;
        target_reached_counter = 0;

        // Set the initial setpoint
        setpoint = INITIAL_SETPOINT;

        state_Ptr = &on_state;
        current_state = ON_STATE;
    }
}

// int cyclecounter = 0;
// #define CYCLECOUNT 4800
// bool highstate = false;

void on_state()
{
    // Catch any hard trip and go safe
    if (EPwm1Regs.TZOSTFLG.all | EPwm2Regs.TZOSTFLG.all | EPwm3Regs.TZOSTFLG.all | EPwm4Regs.TZOSTFLG.all) 
    {
        state_Ptr = &fault_state;
        current_state = FAULT_STATE;
        fault = ON_TZ_OSHT;
        return;
    }

    if (AdcaRegs.ADCINTFLG.bit.ADCINT1)
    {
        // if (++cyclecounter == CYCLECOUNT)
        // {
        //     cyclecounter = 0;
        //     setpoint = INITIAL_SETPOINT * highstate;
        //     highstate = !highstate;
        // }


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
    // Wallow in self-pity - cuddle up in a corner and keep whining.
    while (1)
        NOP;
}