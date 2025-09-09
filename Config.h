#ifndef __CONFIG_H__
#define __CONFIG_H__

// #define MAX_CURRENT_PEAK // CMPSS DAC comparator level for max current peak

#define INITIAL_PERIOD_COUNT 600U    // 600 @ 120MHz = 100kHz (NOTE: "period" = top counter value before counting back down.)
#define INITIAL_DUTY_CYCLE 10U  // Initial duty cycle in percent.
#define INITIAL_COMPARE_VALUE  (INITIAL_PERIOD_COUNT - ((INITIAL_PERIOD_COUNT * INITIAL_DUTY_CYCLE) / 100U))    // Calculate initial compare value from above values.

#define INITIAL_SETPOINT 0.0f // Setpoint is for the ADC measurement. (0 - 4095)

#endif // __CONFIG_H__