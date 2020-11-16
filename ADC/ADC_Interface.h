/*
 * ADC_Interface.h
 *
 *  Created on: Nov 6, 2020
 *      Author: Osama Elmorady
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#include "LIB/ERROR_STATE.h"
#include "ADC_Config.h"


/*****************************************/
/****  Define AVR_ADC Initialization  ****/
/*****************************************/
ErrorState ADC_EnuInit (void) ;




/*************************************/
/****  Define AVR_ADC Turning ON  ****/
/*************************************/
ErrorState ADC_EnuEnable (void);





/**************************************/
/****  Define AVR_ADC Turning OFF  ****/
/**************************************/
ErrorState ADC_EnuDisable (void);






/********************************************/
/****  Define AVR_ADC Channel Selection  ****/
/********************************************/
ErrorState ADC_EnuSelectChannel (u8 Copy_u8Channel);





/*******************************************/
/****  Define AVR_ADC Start Conversion  ****/
/*******************************************/
ErrorState ADC_EnuStartConversion (void);






/*****************************************/
/****  Define AVR_ADC TriggeringMode  ****/
/*****************************************/
ErrorState ADC_EnuAutoTriggering (u8 Copy_u8Status) ;






/*******************************************/
/****  Define AVR_ADC Interrupt Enable  ****/
/*******************************************/
ErrorState ADC_EnuEnableInterrupt (void);






/********************************************/
/****  Define AVR_ADC Interrupt Disable  ****/
/********************************************/
ErrorState ADC_EnuDisableInterrupt (void);






/***********************************************/
/****  Define AVR_ADC Flag (ADIF) Checking  ****/
/***********************************************/
ErrorState ADC_EnuPolling (void);






/****************************************/
/****  Define AVR_ADC Value Reading  ****/
/****************************************/
ErrorState  ADC_EnuRead (u16 * Copy_PU16Value);





#endif /* ADC_INTERFACE_H_ */
