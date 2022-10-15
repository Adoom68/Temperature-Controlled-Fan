 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the AVR ADC driver
 *
 * Author: Adam Farid
 *
 *******************************************************************************/


#include "common_macros.h"
#include "avr/io.h"
#include "adc.h"

void ADC_init(const ADC_ConfigType (* Config_Ptr)){

	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr-> prescaler);      /*Prescaler set*/
	ADMUX = (ADMUX & 0x3F) | (Config_Ptr-> ref_volt<<6);    /*Setting The Refernce Voltage */

	SET_BIT(ADMUX,MUX1);     /*Using ADC2*/
	SET_BIT(ADCSRA,ADEN);    /*ADC Enable */
}

uint16 ADC_readChannel(uint8 channel_num){

	ADMUX = (ADMUX &0xE0) | (channel_num & 0x07);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}

