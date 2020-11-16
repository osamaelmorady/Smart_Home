/*
 * ADC_Private.h
 *
 *  Created on: Nov 6, 2020
 *      Author: Osama Elmorady
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_



/************************************/
/****  Define AVR ADC Addresses  ****/
/************************************/
#define ADMUX 		(*(u8 *)REG_ADMUX )
#define ADCSRA		(*(u8 *)REG_ADCSRA)
#define SFIOR		(*(u8 *)REG_SFIOR )






/********************************************/
/****  Define AVR ADCH & ADCL Addresses  ****/
/********************************************/
#define  ADCH	(*(u8 *)REG_ADCH)
#define	 ADCL	(*(u8 *)REG_ADCH)
#define  ADC	(*(u16 *)REG_ADCL)




/**************************************/
/****  Define ADC ADMUX Addresses  ****/
/**************************************/
#define ADMUX_MUX0 		0
#define ADMUX_MUX1 		1
#define ADMUX_MUX2 		2
#define ADMUX_MUX3 		3
#define ADMUX_MUX4 		4
#define ADMUX_ADLAR 	5
#define ADMUX_REFS0		6
#define ADMUX_REFS1		7

#define ADMUX_MUX_BITS	 0xE0


/***************************************/
/****  Define ADC ADCSRA Addresses  ****/
/***************************************/
#define ADCSRA_ADPS0		0
#define ADCSRA_ADPS1		1
#define ADCSRA_ADPS2		2
#define ADCSRA_ADIE			3
#define ADCSRA_ADIF			4
#define ADCSRA_ADATE		5
#define ADCSRA_ADSC			6
#define ADCSRA_ADEN			7


/***************************************/
/****  Define ADC SFIOR Addresses  ****/
/***************************************/
#define SFIOR_ADTS0		5
#define SFIOR_ADTS1		6
#define SFIOR_ADTS2		7




/*****************************************/
/****  Define AVR_ADC VREF Selection  ****/
/*****************************************/
#define INTERNAL_AREF  0
#define EXTERNAL_AVCC  1
#define INTERNAL_256   3




/**********************************************/
/****  Define AVR_ADC Prescaler Selection  ****/
/**********************************************/
#define PRESCALER_2		0
#define PRESCALER_4		1
#define PRESCALER_8		2
#define PRESCALER_16	3
#define PRESCALER_32	4
#define PRESCALER_64	5
#define PRESCALER_128	6







/******************************************************/
/****  Define AVR_ADC Triggering Source Selection  ****/
/******************************************************/
#define  TRIGGERING_FREE_RUNNING 			0
#define  TRIGGERING_ANALOG_COMPARATOR 		1
#define  TRIGGERING_EXTI_INTERRUPT			2
#define  TRIGGERING_T0_COMPARE_M			3
#define  TRIGGERING_T0_OVERFLOW				4
#define  TRIGGERING_T1_COMPARE_M			5
#define  TRIGGERING_T1_OVERFLOW				6
#define  TRIGGERING_T1_CAPTURE_E			7


#define AUTO_TRIGGER  1


/******************************************************/
/****  Define AVR_ADC Result Right or Left Adjust  ****/
/******************************************************/
#define	RIGHT_ADJ		0
#define	LEFT_ADJ		1





/********************************************/
/****  Define AVR_ADC Channel Selection  ****/
/********************************************/
#define  CHANNEL0	0
#define  CHANNEL7	7

#define  CHANNEL8	8
#define  CHANNEL31	31





#endif /* ADC_PRIVATE_H_ */
