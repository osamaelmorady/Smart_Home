/*
 * TIM_Program.c
 *
 *  Created on: Nov 8, 2020
 *      Author: Osama Elmorady
 */

#ifndef TIM0_PROGRAM_C_
#define TIM0_PROGRAM_C_

#include "LIB/AVR32_REG.h"
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "LIB/ERROR_STATE.h"

#include "TIM2_Config.h"
#include "TIM2_Private.h"





ErrorState TIM2_VidInit(void)
{

	ErrorState error = ES_NOK ;

	/* Enable Global Interrupt */
	CLR_BIT(SREG,SREG_INTERRUPT_BIT) ;


	/* Reset all Configuration */
	TCCR2=0x00 ;

	TCNT2 = 0x00 ;





	/*********************************************/
	/********* Timer Mode Configuration **********/
	/*********************************************/
#if TIMER_MODE == NORMAL_TIMER
	/* Set a Normal Timer */
	CLR_BIT(TCCR2,WGM20) ;
	CLR_BIT(TCCR2,WGM21) ;

	/* Timer Initial Value = 0 */
		TCNT2=184    ;


#elif TIMER_MODE == PHASE_PWM_TIMER
	/* Set a PWM Phase Correct */
	CLR_BIT(TCCR2,WGM20) ;
	SET_BIT(TCCR2,WGM21) ;


#elif TIMER_MODE == CTC_TIMER
	/* Set a CTC Timer */
	CLR_BIT(TCCR2,WGM20) ;
	SET_BIT(TCCR2,WGM21) ;

	OCR0=255  ;



#elif TIMER_MODE == FAST_PWM_TIMER
	/* Set a Fast PWM */
	SET_BIT(TCCR2,WGM20) ;
	SET_BIT(TCCR2,WGM21) ;


#else
#error "Wrong Timer Mode Input"
#endif




	/******************************************************/
	/********* Timer Compare Match Configuration **********/
	/******************************************************/
#if TIMER_COMPARE_MATCH == NORMAL_COMPARE
	/* Compare output mode , Non PWM */
	CLR_BIT(TCCR2,COM20) ;
	CLR_BIT(TCCR2,COM21) ;

#elif TIMER_COMPARE_MATCH == TOGGLE_ON_COMPARE
	/* Compare output mode , Non PWM */
	SET_BIT(TCCR2,COM20) ;
	CLR_BIT(TCCR2,COM21) ;

#elif TIMER_COMPARE_MATCH == CLEAR_ON_COMPARE
	/* Compare output mode , Non PWM */
	CLR_BIT(TCCR2,COM20) ;
	SET_BIT(TCCR2,COM21) ;

#elif TIMER_COMPARE_MATCH == SET_ON_COMPARE
	/* Compare output mode , Non PWM */
	SET_BIT(TCCR2,COM20) ;
	SET_BIT(TCCR2,COM21) ;

#else
#error "Wrong Compare Match Mode"
#endif




	/**************************************************/
	/********* Timer Prescaler Configuration **********/
	/**************************************************/
#if TIMER_PRESCALER == TIMER_NK_SOURCE
	/* Close the Clock   */
	CLR_BIT(TCCR2,CS20) ;
	CLR_BIT(TCCR2,CS21) ;
	CLR_BIT(TCCR2,CS22) ;

#elif TIMER_PRESCALER == TIMER_PRESCALER_1
	/* Set the Prescaler  1   */
	SET_BIT(TCCR2,CS20) ;
	CLR_BIT(TCCR2,CS21) ;
	CLR_BIT(TCCR2,CS22) ;

#elif TIMER_PRESCALER == TIMER_PRESCALER_8
	/* Set the Prescaler  8   */
	CLR_BIT(TCCR2,CS20) ;
	SET_BIT(TCCR2,CS21) ;
	CLR_BIT(TCCR2,CS22) ;

#elif TIMER_PRESCALER == TIMER_PRESCALER_64
	/* Set the Prescaler  64   */
	SET_BIT(TCCR2,CS20) ;
	SET_BIT(TCCR2,CS21) ;
	CLR_BIT(TCCR2,CS22) ;

#elif TIMER_PRESCALER == TIMER_PRESCALER_256
	/* Set the Prescaler  256   */
	CLR_BIT(TCCR2,CS20) ;
	CLR_BIT(TCCR2,CS21) ;
	SET_BIT(TCCR2,CS22) ;

#elif TIMER_PRESCALER == TIMER_PRESCALER_1024
	/* Set the Prescaler  1024   */
	SET_BIT(TCCR2,CS20) ;
	CLR_BIT(TCCR2,CS21) ;
	SET_BIT(TCCR2,CS22) ;

#elif TIMER_PRESCALER == TIMER_CLK_ON_FALLING_EDGE
	/* External Clock Source on Falling Edge   */
	SET_BIT(TCCR2,CS20) ;
	CLR_BIT(TCCR2,CS21) ;
	SET_BIT(TCCR2,CS22) ;

#elif TIMER_PRESCALER == TIMER_CLK_ON_RISING_EDGE
	/* External Clock Source on Rising Edge */
	SET_BIT(TCCR2,CS20) ;
	CLR_BIT(TCCR2,CS21) ;
	SET_BIT(TCCR2,CS22) ;

#else
#error "Wrong Prescaler Input"
#endif

	/* Interrupt enable   */
	//CLR_BIT(TIMSK,TOIE2) ;

	error =ES_OK ;

	return error ;

}





ErrorState TIM2_VidEnable (void)
{
	ErrorState error = ES_NOK ;

	error =ES_OK ;

	return error ;

}



ErrorState TIM2_VidDisable (void)
{
	ErrorState error = ES_NOK ;

	error =ES_OK ;

	return error ;
}








static void (* PVid_SetCallBack2)(void) = NULL ;

ErrorState TIM2_VidSetCallBack(void (* PF)(void))
{
	ErrorState error = ES_NOK ;

	PVid_SetCallBack2=PF ;

	error =ES_OK ;

	return error ;

}











/*************************************/
/****** ISR Calling From System ******/
/*************************************/
u32 TIM2_U32Counts=0 ;

void __vector_5(void)
{
	if 	(TIM2_U32Counts == 488 )
	{
		PVid_SetCallBack2() ;

		TCNT2=184 ;

		TIM2_U32Counts=0 ;
	}
	else
	{
		TIM2_U32Counts+=1 ;
	}


}







void PWM2_SetDutyCycle(u8 Copy_U8Percent)
{

Copy_U8Percent=Copy_U8Percent*255/100 ;

OCR2=Copy_U8Percent  ;

}








#endif /* TIM_PROGRAM_C_ */
