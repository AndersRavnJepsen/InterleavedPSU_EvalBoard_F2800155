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

#include "board.h"

//*****************************************************************************
//
// Board Configurations
// Initializes the rest of the modules. 
// Call this function in your application if you wish to do all module 
// initialization.
// If you wish to not use some of the initializations, instead of the 
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init()
{
	EALLOW;

	PinMux_init();
	SYSCTL_init();
	SYNC_init();
	ASYSCTL_init();
	ADC_init();
	CMPSSLITE_init();
	EPWM_init();
	EPWMXBAR_init();
	GPIO_init();

	EDIS;
}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
	//
	// PinMux for modules assigned to CPU1
	//
	
	//
	// ANALOG -> myANALOGPinMux0 Pinmux
	//
	// Analog PinMux for A15/C7
	GPIO_setPinConfig(GPIO_233_GPIO233);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(233, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A2/C9, GPIO224
	GPIO_setPinConfig(GPIO_224_GPIO224);
	// AGPIO -> Analog mode selected
	GPIO_setAnalogMode(224, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A3/C5, GPIO242
	GPIO_setPinConfig(GPIO_242_GPIO242);
	// AGPIO -> Analog mode selected
	GPIO_setAnalogMode(242, GPIO_ANALOG_ENABLED);
	// Analog PinMux for C4/A14
	GPIO_setPinConfig(GPIO_239_GPIO239);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(239, GPIO_ANALOG_ENABLED);
	//
	// EPWM2 -> ePWM2 Pinmux
	//
	GPIO_setPinConfig(ePWM2_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(ePWM2_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ePWM2_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(ePWM2_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(ePWM2_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ePWM2_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM3 -> ePWM3 Pinmux
	//
	GPIO_setPinConfig(ePWM3_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(ePWM3_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ePWM3_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(ePWM3_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(ePWM3_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ePWM3_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM4 -> ePWM4 Pinmux
	//
	GPIO_setPinConfig(ePWM4_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(ePWM4_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ePWM4_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(ePWM4_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(ePWM4_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ePWM4_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM1 -> ePWM1 Pinmux
	//
	GPIO_setPinConfig(ePWM1_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(ePWM1_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ePWM1_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(ePWM1_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(ePWM1_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ePWM1_EPWMB_GPIO, GPIO_QUAL_SYNC);

	// A16/C16, GPIO28 -> gpio28 Pinmux
	GPIO_setPinConfig(GPIO_28_GPIO28);
	// AGPIO -> GPIO mode selected
	GPIO_setAnalogMode(28, GPIO_ANALOG_DISABLED);

}

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
void ADC_init(){
	ADC_A_init();
}

void ADC_A_init(){
	//
	// ADC Initialization: Write ADC configurations and power up the ADC
	//
	// Set the analog voltage reference selection and ADC module's offset trims.
	// This function sets the analog voltage reference to internal (with the reference voltage of 1.65V or 2.5V) or external for ADC
	// which is same as ASysCtl APIs.
	//
	ADC_setVREF(ADC_A_BASE, ADC_REFERENCE_EXTERNAL, ADC_REFERENCE_3_3V);
	//
	// Configures the analog-to-digital converter module prescaler.
	//
	ADC_setPrescaler(ADC_A_BASE, ADC_CLK_DIV_2_0);
	//
	// Sets the timing of the end-of-conversion pulse
	//
	ADC_setInterruptPulseMode(ADC_A_BASE, ADC_PULSE_END_OF_CONV);
	//
	// Powers up the analog-to-digital converter core.
	//
	ADC_enableConverter(ADC_A_BASE);
	//
	// Delay for 1ms to allow ADC time to power up
	//
	DEVICE_DELAY_US(500);
	//
	// SOC Configuration: Setup ADC EPWM channel and trigger settings
	//
	// Disables SOC burst mode.
	//
	ADC_disableBurstMode(ADC_A_BASE);
	//
	// Sets the priority mode of the SOCs.
	//
	ADC_setSOCPriority(ADC_A_BASE, ADC_PRI_ALL_ROUND_ROBIN);
	//
	// Start of Conversion 1 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 1
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN3
	//	 	Sample Window	: 15 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(ADC_A_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN3, 15U);
	ADC_setInterruptSOCTrigger(ADC_A_BASE, ADC_SOC_NUMBER1, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 2 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 2
	//	  	Trigger			: ADC_TRIGGER_EPWM2_SOCA
	//	  	Channel			: ADC_CH_ADCIN2
	//	 	Sample Window	: 15 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(ADC_A_BASE, ADC_SOC_NUMBER2, ADC_TRIGGER_EPWM2_SOCA, ADC_CH_ADCIN2, 15U);
	ADC_setInterruptSOCTrigger(ADC_A_BASE, ADC_SOC_NUMBER2, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 3 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 3
	//	  	Trigger			: ADC_TRIGGER_EPWM3_SOCA
	//	  	Channel			: ADC_CH_ADCIN15
	//	 	Sample Window	: 15 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(ADC_A_BASE, ADC_SOC_NUMBER3, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN15, 15U);
	ADC_setInterruptSOCTrigger(ADC_A_BASE, ADC_SOC_NUMBER3, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 4 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 4
	//	  	Trigger			: ADC_TRIGGER_EPWM4_SOCA
	//	  	Channel			: ADC_CH_ADCIN14
	//	 	Sample Window	: 15 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(ADC_A_BASE, ADC_SOC_NUMBER4, ADC_TRIGGER_EPWM4_SOCA, ADC_CH_ADCIN14, 15U);
	ADC_setInterruptSOCTrigger(ADC_A_BASE, ADC_SOC_NUMBER4, ADC_INT_SOC_TRIGGER_NONE);
	//
	// ADC Interrupt 1 Configuration
	// 		Source	: ADC_SOC_NUMBER4
	// 		Interrupt Source: enabled
	// 		Continuous Mode	: disabled
	//
	//
	ADC_setInterruptSource(ADC_A_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER4);
	ADC_clearInterruptStatus(ADC_A_BASE, ADC_INT_NUMBER1);
	ADC_disableContinuousMode(ADC_A_BASE, ADC_INT_NUMBER1);
	ADC_enableInterrupt(ADC_A_BASE, ADC_INT_NUMBER1);
			
	//
	// PPB Configuration: Configure high and low limits detection for ADCPPB
	//
	// Post Processing Block 1 Configuration
	// 		Configures a post-processing block (PPB) in the ADC.
	// 		PPB Number				: 1
	// 		SOC/EOC number			: 1
	// 		Calibration Offset		: 0
	// 		Reference Offset		: 4095
	// 		Two's Complement		: Enabled
	// 		Trip High Limit			: 0
	// 		Trip Low Limit			: 0
	// 		Clear PPB Event Flags	: Disabled
	//
	ADC_setupPPB(ADC_A_BASE, ADC_PPB_NUMBER1, ADC_SOC_NUMBER1);
	ADC_disablePPBEvent(ADC_A_BASE, ADC_PPB_NUMBER1, (ADC_EVT_TRIPHI | ADC_EVT_TRIPLO | ADC_EVT_ZERO));
	ADC_disablePPBEventInterrupt(ADC_A_BASE, ADC_PPB_NUMBER1, (ADC_EVT_TRIPHI | ADC_EVT_TRIPLO | ADC_EVT_ZERO));
	ADC_setPPBCalibrationOffset(ADC_A_BASE, ADC_PPB_NUMBER1, 0);
	ADC_setPPBReferenceOffset(ADC_A_BASE, ADC_PPB_NUMBER1, 4095);
	ADC_enablePPBTwosComplement(ADC_A_BASE, ADC_PPB_NUMBER1);
	ADC_setPPBTripLimits(ADC_A_BASE, ADC_PPB_NUMBER1, 0, 0);
	ADC_disablePPBEventCBCClear(ADC_A_BASE, ADC_PPB_NUMBER1);
}


//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************
void ASYSCTL_init(){
	//
	// asysctl initialization
	//
	// Disables the temperature sensor output to the ADC.
	//
	ASysCtl_disableTemperatureSensor();
	//
	// Set the analog voltage reference selection to external.
	//
	ASysCtl_setAnalogReferenceExternal( ASYSCTL_VREFHI );
}

//*****************************************************************************
//
// CMPSS-LITE Configurations
//
//*****************************************************************************
void CMPSSLITE_init(){
	cmpss3_init();
}

void cmpss3_init(){
    //
    // Select the value for CMP3HPMXSEL.
    //
    ASysCtl_selectCMPHPMux(ASYSCTL_CMPHPMUX_SELECT_3,3U);
    //
    // Select the value for CMP3LPMXSEL.
    //
    ASysCtl_selectCMPLPMux(ASYSCTL_CMPLPMUX_SELECT_3,4U);
    //
    // Sets the configuration for the high comparator.
    //
    CMPSSLITE_configHighComparator(cmpss3_BASE,(CMPSS_INSRC_DAC | CMPSS_INV_INVERTED));
    //
    // Sets the configuration for the low comparator.
    //
    CMPSSLITE_configLowComparator(cmpss3_BASE,(CMPSS_INSRC_DAC));
    //
    // Sets the configuration for the internal comparator DACs.
    //
    CMPSSLITE_configDAC(cmpss3_BASE, CMPSS_DACVAL_SYSCLK);
    //
    // Sets the value of the internal DAC of the high comparator.
    //
    CMPSSLITE_setDACValueHigh(cmpss3_BASE,2000U);
    //
    // Sets the value of the internal DAC of the low comparator.
    //
    CMPSSLITE_setDACValueLow(cmpss3_BASE,0U);
    //
    //  Configures the digital filter of the high comparator.
    //
    CMPSSLITE_configFilterHigh(cmpss3_BASE, 0U, 8U, 6U);
    //
    // Configures the digital filter of the low comparator.
    //
    CMPSSLITE_configFilterLow(cmpss3_BASE, 0U, 1U, 1U);
    //
    // Sets the comparator hysteresis settings.
    //
    CMPSSLITE_setHysteresis(cmpss3_BASE,0U);
    //
    // Disables reset of HIGH comparator digital filter output latch on PWMSYNC
    //
    CMPSSLITE_disableLatchResetOnPWMSYNCHigh(cmpss3_BASE);
    //
    // Disables reset of LOW comparator digital filter output latch on PWMSYNC
    //
    CMPSSLITE_disableLatchResetOnPWMSYNCLow(cmpss3_BASE);
    //
    // Sets the ePWM module blanking signal that holds trip in reset.
    //
    CMPSSLITE_configBlanking(cmpss3_BASE,1U);
    //
    // Disables an ePWM blanking signal from holding trip in reset.
    //
    CMPSSLITE_disableBlanking(cmpss3_BASE);
    //
    // Configures whether or not the digital filter latches are reset by PWMSYNC
    //
    CMPSSLITE_configLatchOnPWMSYNC(cmpss3_BASE,false,false);
    //
    // Enables the CMPSSLITE module.
    //
    CMPSSLITE_enableModule(cmpss3_BASE);
    //
    // Delay for CMPSSLITE DAC to power up.
    //
    DEVICE_DELAY_US(500);
}

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init(){
    EPWM_enableGlobalLoad(ePWM2_BASE);	
    EPWM_setGlobalLoadTrigger(ePWM2_BASE, EPWM_GL_LOAD_PULSE_SYNC);	
    EPWM_setGlobalLoadEventPrescale(ePWM2_BASE, 1);	
    EPWM_setClockPrescaler(ePWM2_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(ePWM2_BASE, 600);	
    EPWM_setupEPWMLinks(ePWM2_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_TBPRD);	
    EPWM_enableGlobalLoadRegisters(ePWM2_BASE, EPWM_GL_REGISTER_TBPRD_TBPRDHR);	
    EPWM_setTimeBaseCounter(ePWM2_BASE, 0);	
    EPWM_setTimeBaseCounterMode(ePWM2_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_enablePhaseShiftLoad(ePWM2_BASE);	
    EPWM_setPhaseShift(ePWM2_BASE, 300);	
    EPWM_setCounterCompareValue(ePWM2_BASE, EPWM_COUNTER_COMPARE_A, 540);	
    EPWM_setCounterCompareShadowLoadMode(ePWM2_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(ePWM2_BASE, EPWM_COUNTER_COMPARE_B, 0);	
    EPWM_setCounterCompareShadowLoadMode(ePWM2_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_disableActionQualifierShadowLoadMode(ePWM2_BASE, EPWM_ACTION_QUALIFIER_A);	
    EPWM_setActionQualifierShadowLoadMode(ePWM2_BASE, EPWM_ACTION_QUALIFIER_A, EPWM_AQ_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(ePWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(ePWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(ePWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(ePWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(ePWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(ePWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_disableActionQualifierShadowLoadMode(ePWM2_BASE, EPWM_ACTION_QUALIFIER_B);	
    EPWM_setActionQualifierShadowLoadMode(ePWM2_BASE, EPWM_ACTION_QUALIFIER_B, EPWM_AQ_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(ePWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(ePWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(ePWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(ePWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(ePWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(ePWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(ePWM2_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(ePWM2_BASE);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(ePWM2_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(ePWM2_BASE);	
    EPWM_setDigitalCompareEventSyncMode(ePWM2_BASE, EPWM_DC_MODULE_A, EPWM_DC_EVENT_1, EPWM_DC_EVENT_INPUT_NOT_SYNCED);	
    EPWM_enableDigitalCompareEdgeFilter(ePWM2_BASE);	
    EPWM_enableADCTrigger(ePWM2_BASE, EPWM_SOC_A);	
    EPWM_setADCTriggerSource(ePWM2_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_PERIOD);	
    EPWM_setADCTriggerEventPrescale(ePWM2_BASE, EPWM_SOC_A, 1);	
    EPWM_enableGlobalLoad(ePWM3_BASE);	
    EPWM_setGlobalLoadTrigger(ePWM3_BASE, EPWM_GL_LOAD_PULSE_SYNC);	
    EPWM_setGlobalLoadEventPrescale(ePWM3_BASE, 1);	
    EPWM_setClockPrescaler(ePWM3_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(ePWM3_BASE, 600);	
    EPWM_setupEPWMLinks(ePWM3_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_TBPRD);	
    EPWM_enableGlobalLoadRegisters(ePWM3_BASE, EPWM_GL_REGISTER_TBPRD_TBPRDHR);	
    EPWM_setTimeBaseCounter(ePWM3_BASE, 0);	
    EPWM_setTimeBaseCounterMode(ePWM3_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_enablePhaseShiftLoad(ePWM3_BASE);	
    EPWM_setPhaseShift(ePWM3_BASE, 600);	
    EPWM_setCounterCompareValue(ePWM3_BASE, EPWM_COUNTER_COMPARE_A, 540);	
    EPWM_setCounterCompareShadowLoadMode(ePWM3_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(ePWM3_BASE, EPWM_COUNTER_COMPARE_B, 0);	
    EPWM_setCounterCompareShadowLoadMode(ePWM3_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_disableActionQualifierShadowLoadMode(ePWM3_BASE, EPWM_ACTION_QUALIFIER_A);	
    EPWM_setActionQualifierShadowLoadMode(ePWM3_BASE, EPWM_ACTION_QUALIFIER_A, EPWM_AQ_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(ePWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(ePWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(ePWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(ePWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(ePWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(ePWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_disableActionQualifierShadowLoadMode(ePWM3_BASE, EPWM_ACTION_QUALIFIER_B);	
    EPWM_setActionQualifierShadowLoadMode(ePWM3_BASE, EPWM_ACTION_QUALIFIER_B, EPWM_AQ_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(ePWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(ePWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(ePWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(ePWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(ePWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(ePWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(ePWM3_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(ePWM3_BASE);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(ePWM3_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(ePWM3_BASE);	
    EPWM_enableGlobalLoad(ePWM4_BASE);	
    EPWM_setGlobalLoadTrigger(ePWM4_BASE, EPWM_GL_LOAD_PULSE_SYNC);	
    EPWM_setGlobalLoadEventPrescale(ePWM4_BASE, 1);	
    EPWM_setClockPrescaler(ePWM4_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(ePWM4_BASE, 600);	
    EPWM_setupEPWMLinks(ePWM4_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_TBPRD);	
    EPWM_enableGlobalLoadRegisters(ePWM4_BASE, EPWM_GL_REGISTER_TBPRD_TBPRDHR);	
    EPWM_setTimeBaseCounter(ePWM4_BASE, 0);	
    EPWM_setTimeBaseCounterMode(ePWM4_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_setCountModeAfterSync(ePWM4_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    EPWM_enablePhaseShiftLoad(ePWM4_BASE);	
    EPWM_setPhaseShift(ePWM4_BASE, 300);	
    EPWM_setCounterCompareValue(ePWM4_BASE, EPWM_COUNTER_COMPARE_A, 540);	
    EPWM_setCounterCompareShadowLoadMode(ePWM4_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(ePWM4_BASE, EPWM_COUNTER_COMPARE_B, 0);	
    EPWM_setCounterCompareShadowLoadMode(ePWM4_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_disableActionQualifierShadowLoadMode(ePWM4_BASE, EPWM_ACTION_QUALIFIER_A);	
    EPWM_setActionQualifierShadowLoadMode(ePWM4_BASE, EPWM_ACTION_QUALIFIER_A, EPWM_AQ_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(ePWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(ePWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(ePWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(ePWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(ePWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(ePWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_disableActionQualifierShadowLoadMode(ePWM4_BASE, EPWM_ACTION_QUALIFIER_B);	
    EPWM_setActionQualifierShadowLoadMode(ePWM4_BASE, EPWM_ACTION_QUALIFIER_B, EPWM_AQ_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(ePWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(ePWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(ePWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(ePWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(ePWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(ePWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(ePWM4_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(ePWM4_BASE);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(ePWM4_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(ePWM4_BASE);	
    EPWM_enableADCTrigger(ePWM4_BASE, EPWM_SOC_A);	
    EPWM_setADCTriggerSource(ePWM4_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_PERIOD);	
    EPWM_setADCTriggerEventPrescale(ePWM4_BASE, EPWM_SOC_A, 1);	
    EPWM_enableGlobalLoad(ePWM1_BASE);	
    EPWM_setGlobalLoadEventPrescale(ePWM1_BASE, 1);	
    EPWM_enableGlobalLoadOneShotMode(ePWM1_BASE);	
    EPWM_setGlobalLoadOneShotLatch(ePWM1_BASE);	
    EPWM_setClockPrescaler(ePWM1_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(ePWM1_BASE, 600);	
    EPWM_enableGlobalLoadRegisters(ePWM1_BASE, EPWM_GL_REGISTER_TBPRD_TBPRDHR);	
    EPWM_setTimeBaseCounter(ePWM1_BASE, 0);	
    EPWM_setTimeBaseCounterMode(ePWM1_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_setCountModeAfterSync(ePWM1_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    EPWM_enablePhaseShiftLoad(ePWM1_BASE);	
    EPWM_setPhaseShift(ePWM1_BASE, 0);	
    EPWM_setSyncInPulseSource(ePWM1_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);	
    EPWM_enableSyncOutPulseSource(ePWM1_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO | EPWM_SYNC_OUT_PULSE_ON_SOFTWARE);	
    EPWM_setCounterCompareValue(ePWM1_BASE, EPWM_COUNTER_COMPARE_A, 450);	
    EPWM_setCounterCompareShadowLoadMode(ePWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(ePWM1_BASE, EPWM_COUNTER_COMPARE_B, 1);	
    EPWM_setCounterCompareShadowLoadMode(ePWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierShadowLoadMode(ePWM1_BASE, EPWM_ACTION_QUALIFIER_A, EPWM_AQ_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierSWAction(ePWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW);	
    EPWM_setActionQualifierAction(ePWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(ePWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(ePWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(ePWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(ePWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(ePWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierShadowLoadMode(ePWM1_BASE, EPWM_ACTION_QUALIFIER_B, EPWM_AQ_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(ePWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(ePWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(ePWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(ePWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(ePWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(ePWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(ePWM1_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(ePWM1_BASE);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(ePWM1_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(ePWM1_BASE);	
    EPWM_enableTripZoneAdvAction(ePWM1_BASE);	
    EPWM_setTripZoneAction(ePWM1_BASE, EPWM_TZ_ACTION_EVENT_DCAEVT1, EPWM_TZ_ACTION_LOW);	
    EPWM_setTripZoneAdvAction(ePWM1_BASE, EPWM_TZ_ADV_ACTION_EVENT_TZA_D, EPWM_TZ_ADV_ACTION_LOW);	
    EPWM_setTripZoneAdvAction(ePWM1_BASE, EPWM_TZ_ADV_ACTION_EVENT_TZA_U, EPWM_TZ_ADV_ACTION_LOW);	
    EPWM_setTripZoneAdvDigitalCompareActionA(ePWM1_BASE, EPWM_TZ_ADV_ACTION_EVENT_DCxEVT1_U, EPWM_TZ_ADV_ACTION_DISABLE);	
    EPWM_setTripZoneAdvDigitalCompareActionA(ePWM1_BASE, EPWM_TZ_ADV_ACTION_EVENT_DCxEVT1_D, EPWM_TZ_ADV_ACTION_DISABLE);	
    EPWM_enableTripZoneSignals(ePWM1_BASE, EPWM_TZ_SIGNAL_DCAEVT1);	
    EPWM_selectDigitalCompareTripInput(ePWM1_BASE, EPWM_DC_TRIP_TRIPIN4, EPWM_DC_TYPE_DCAH);	
    EPWM_selectDigitalCompareTripInput(ePWM1_BASE, EPWM_DC_TRIP_TRIPIN4, EPWM_DC_TYPE_DCAL);	
    EPWM_setTripZoneDigitalCompareEventCondition(ePWM1_BASE, EPWM_TZ_DC_OUTPUT_A1, EPWM_TZ_EVENT_DCXH_HIGH);	
    EPWM_setDigitalCompareEventSyncMode(ePWM1_BASE, EPWM_DC_MODULE_A, EPWM_DC_EVENT_1, EPWM_DC_EVENT_INPUT_NOT_SYNCED);	
    EPWM_enableADCTrigger(ePWM1_BASE, EPWM_SOC_A);	
    EPWM_setADCTriggerSource(ePWM1_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_PERIOD);	
    EPWM_setADCTriggerEventPrescale(ePWM1_BASE, EPWM_SOC_A, 1);	
}

//*****************************************************************************
//
// EPWMXBAR Configurations
//
//*****************************************************************************
void EPWMXBAR_init(){
	epwmxbar0_init();
}

void epwmxbar0_init(){
		
	XBAR_setEPWMMuxConfig(epwmxbar0, XBAR_EPWM_MUX04_CMPSS3_CTRIPH);
	XBAR_enableEPWMMux(epwmxbar0, XBAR_MUX04);
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init(){
	gpio28_init();
}

void gpio28_init(){
	GPIO_writePin(gpio28, 0);
	GPIO_setPadConfig(gpio28, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(gpio28, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(gpio28, GPIO_DIR_MODE_OUT);
}

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************
void SYNC_init(){
	SysCtl_setSyncOutputConfig(SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT);
	//
	// SOCA
	//
	SysCtl_enableExtADCSOCSource(0);
	//
	// SOCB
	//
	SysCtl_enableExtADCSOCSource(0);
}
//*****************************************************************************
//
// SYSCTL Configurations
//
//*****************************************************************************
void SYSCTL_init(){
	//
    // sysctl initialization
	//
    SysCtl_setStandbyQualificationPeriod(2);
    SysCtl_configureType(SYSCTL_ECAPTYPE, 0, 0);
    SysCtl_selectErrPinPolarity(0);

    SysCtl_disableMCD();


    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TIMER0);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TIMER1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TIMER2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_HRCAL);
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM3);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM4);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM5);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM6);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM7);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP3);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EQEP1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EQEP2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SCIA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SCIB);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SCIC);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SPIA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_I2CA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_I2CB);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CANA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_MCANA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADCA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADCC);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS3);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS4);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_LINA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_PMBUSA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DCC0);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPG1);



}

