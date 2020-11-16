/*
 * ADC_Program.c
 *
 *  Created on: Nov 6, 2020
 *      Author: Osama Elmorady
 */


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "LIB/ERROR_STATE.h"
#include "LIB/AVR32_REG.h"

#include "ADC_Private.h"
#include "ADC_Config.h"





/*****************************************/
/****  Define AVR_ADC Initialization  ****/
/*****************************************/
ErrorState ADC_EnuInit (void)
{
	ErrorState error =ES_NOK ;

	/**********************************************/
	/****  Define AVR_ADC Prescaler Selection  ****/
	/**********************************************/
#if ADC_PRESCALER == PRESCALER_2
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS2);

#elif ADC_PRESCALER == PRESCALER_4

	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS2);



#elif ADC_PRESCALER == PRESCALER_8

	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS2);





#elif ADC_PRESCALER == PRESCALER_16

	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);




#elif ADC_PRESCALER == PRESCALER_32

	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);




#elif ADC_PRESCALER == PRESCALER_64

	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);




#elif ADC_PRESCALER == PRESCALER_128

	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);



#else
#error "Wrong ADC_PRESCALER "
#endif





	/*****************************************/
	/****  Define AVR_ADC VREF Selection  ****/
	/*****************************************/
#if ADC_VREF ==INTERNAL_AREF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif ADC_VREF ==EXTERNAL_AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif ADC_VREF ==INTERNAL_256
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);

#else
#error "Wrong ADC_VREF "
#endif




	/******************************************************/
	/****  Define AVR_ADC Result Right or Left Adjust  ****/
	/******************************************************/
#if ADC_ADJ	== RIGHT_ADJ
	CLR_BIT(ADMUX,ADMUX_ADLAR);

#elif ADC_ADJ == LEFT_ADJ
	SET_BIT(ADMUX,ADMUX_ADLAR);

#else
#error "Wrong Result Adjust ADC_ADJ "
#endif


	error = ES_OK ;

	return error ;
}








/*************************************/
/****  Define AVR_ADC Turning ON  ****/
/*************************************/
ErrorState ADC_EnuEnable (void)
{
	ErrorState error = ES_NOK ;

	SET_BIT(ADCSRA,ADCSRA_ADEN);

	error = ES_OK ;

	return error ;
}






/**************************************/
/****  Define AVR_ADC Turning OFF  ****/
/**************************************/
ErrorState ADC_EnuDisable (void)
{
	ErrorState error = ES_NOK ;

	CLR_BIT(ADCSRA,ADCSRA_ADEN);

	error = ES_OK ;

	return error ;
}







/********************************************/
/****  Define AVR_ADC Channel Selection  ****/
/********************************************/
ErrorState ADC_EnuSelectChannel (u8 Copy_u8Channel)
{
	ErrorState error = ES_NOK ;

	/* Initialize Channel with 0 , All Channels are Deactivated */
	ADMUX = ADMUX & ADMUX_MUX_BITS ;

	if ( ( Copy_u8Channel >= CHANNEL0 ) && ( Copy_u8Channel <=CHANNEL7 ) )
	{
		ADMUX = ADMUX | Copy_u8Channel;

		error = ES_OK ;
	}
	else if ( ( Copy_u8Channel >= CHANNEL8 ) && ( Copy_u8Channel <=CHANNEL31 ) )
	{
		error = ES_OUT_OF_RANGE ;
	}
	else
	{
		error = ES_OUT_OF_RANGE ;
	}

	return error ;

}






/*******************************************/
/****  Define AVR_ADC Start Conversion  ****/
/*******************************************/
ErrorState ADC_EnuStartConversion (void)
{
	ErrorState error = ES_NOK ;

	SET_BIT ( ADCSRA , ADCSRA_ADSC );

	error = ES_OK ;

	return error ;
}






/******************************************/
/****  Define AVR_ADC Auto Triggering  ****/
/******************************************/
ErrorState ADC_EnuAutoTriggering (u8 Copy_u8Status)
{
	ErrorState error = ES_NOK ;

	switch (Copy_u8Status)
		{
			case AUTO_TRIGGER  : 	SET_BIT ( ADCSRA , ADCSRA_ADATE ); 	error = ES_OK ;	break;

			case !AUTO_TRIGGER	: 	CLR_BIT ( ADCSRA , ADCSRA_ADATE );  error = ES_OK ;	break   ;
		}

	return error ;
}






/*******************************************/
/****  Define AVR_ADC Interrupt Enable  ****/
/*******************************************/
ErrorState ADC_EnuEnableInterrupt (void)
{
	ErrorState error = ES_NOK ;

	SET_BIT ( ADCSRA , ADCSRA_ADIE );

	error = ES_OK ;

	return error ;
}






/********************************************/
/****  Define AVR_ADC Interrupt Disable  ****/
/********************************************/
ErrorState ADC_EnuDisableInterrupt (void)
{
	ErrorState error = ES_NOK ;

	CLR_BIT ( ADCSRA , ADCSRA_ADIE );

	error = ES_OK ;

	return error ;
}






/***********************************************/
/****  Define AVR_ADC Flag (ADIF) Checking  ****/
/***********************************************/
ErrorState ADC_EnuPolling (void)
{
	ErrorState error = ES_NOK ;

	ADC=0;

	while ( ! GET_BIT ( ADCSRA,ADCSRA_ADIF ) );

	/* Set the ADC flag To zero Manually */
	SET_BIT ( ADCSRA , ADCSRA_ADIF );

	error = ES_OK ;

	return error ;
}





/****************************************/
/****  Define AVR_ADC Value Reading  ****/
/****************************************/
ErrorState ADC_EnuRead (u16 * Copy_PU16Value)
{
	ErrorState error = ES_NOK ;

	*Copy_PU16Value = ADC;

	error = ES_OK ;

	return error ;
}



