/*
 * ADC_Config.h
 *
 *  Created on: Nov 6, 2020
 *      Author: Osama Elmorady
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_





/******************************************************/
/****  Define AVR_ADC Result Right or Left Adjust  ****/
/******************************************************/

#define ADC_ADJ  RIGHT_ADJ
//#define ADC_ADJ  LEFT_ADJ



/*****************************************/
/****  Define AVR_ADC VREF Selection  ****/
/*****************************************/

#define ADC_VREF 			EXTERNAL_AVCC
//#define ADC_VREF 			INTERNAL_AREF
//#define ADC_VREF 			INTERNAL_256



/**********************************************/
/****  Define AVR_ADC Prescaler Selection  ****/
/**********************************************/
//#define ADC_PRESCALER 		PRESCALER_2
//#define ADC_PRESCALER 		PRESCALER_4
//#define ADC_PRESCALER 		PRESCALER_8
//#define ADC_PRESCALER 		PRESCALER_16
//#define ADC_PRESCALER 		PRESCALER_32
#define ADC_PRESCALER 		PRESCALER_64
//#define ADC_PRESCALER 		PRESCALER_128







#endif /* ADC_CONFIG_H_ */
