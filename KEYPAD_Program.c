/*
 * KEY_Program.c
 *
 *  Created on: Nov 6, 2020
 *      Author: Osama Elmorady
 */


#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "LIB/ERROR_STATE.h"

#include "DIO/DIO_Interface.h"

#include "KEYPAD_Private.h"
#include "KEYPAD_Config.h"

#include <util/delay.h>




/***************************************************/
/*************** Keypad Initialization *************/
/***************************************************/
ErrorState KEYPAD_VidInit (void)
{
	ErrorState error = ES_NOK ;

	/*  Input Pins */
	DIO_EnuSetPinDir( KEY_R1 , INPUT ) ;
	DIO_EnuSetPinDir( KEY_R2 , INPUT ) ;
	DIO_EnuSetPinDir( KEY_R3 , INPUT ) ;
	DIO_EnuSetPinDir( KEY_R4 , INPUT ) ;

	/*  Output Pins */
	DIO_EnuSetPinDir( KEY_C1 , OUTPUT ) ;
	DIO_EnuSetPinDir( KEY_C2 , OUTPUT ) ;
	DIO_EnuSetPinDir( KEY_C3 , OUTPUT ) ;
	DIO_EnuSetPinDir( KEY_C4 , OUTPUT ) ;


	/*  Latch the Pull Up Resistor */
	DIO_EnuSetPinVal( KEY_R1 , HIGH ) ;
	DIO_EnuSetPinVal( KEY_R2 , HIGH ) ;
	DIO_EnuSetPinVal( KEY_R3 , HIGH ) ;
	DIO_EnuSetPinVal( KEY_R4 , HIGH ) ;
	
	error = ES_OK ;
	
	return error ;
}









/********************************************************/
/*************** Keypad Get the pressed key *************/
/********************************************************/

u8 KEY_U8Rows[4]={KEY_R1,KEY_R2,KEY_R3,KEY_R4} ;

u8 KEY_U8Columns[4]={KEY_C1,KEY_C2,KEY_C3,KEY_C4} ;

u8 KEYPAD_U8Numbers[4][4]= KEYPAD_U8DATA ;



ErrorState KEYPAD_U8GetKey (u8 * Copy_PU8PressedKey)
{	
	ErrorState error = ES_NOK ;

	u32 Local_U8ButtonStatus=HIGH ;
	
	for (u8 U8_ColCounter=0 ; U8_ColCounter < KEY_PAD_COLUMNS ; U8_ColCounter++)
	{
		DIO_EnuSetPinVal ( KEY_U8Columns[U8_ColCounter] , LOW ) ;
		
		for (u8 U8_RowCounter=0 ; U8_RowCounter < KEY_PAD_ROWS ; U8_RowCounter++)
		{

			/* Get the pin value twice or more with delay for noise canceling and also bouncing effect */
			for(u8 Local_U8I=0 ; Local_U8I < 3 ; Local_U8I++ )
			{
				DIO_EnuGetPinVal( KEY_U8Rows[U8_RowCounter], &Local_U8ButtonStatus ) ;
				//_delay_ms(1) ;
			}

			if (!Local_U8ButtonStatus )
				
			{
				/* Polling on the button status until relief hand */
				while (!Local_U8ButtonStatus) 	{	DIO_EnuGetPinVal( KEY_U8Rows[U8_RowCounter], &Local_U8ButtonStatus ) ;	   }

				* Copy_PU8PressedKey = KEYPAD_U8Numbers[U8_RowCounter][U8_ColCounter] ;
			}
		}

		DIO_EnuSetPinVal( KEY_U8Columns[U8_ColCounter] , HIGH ) ;
	}
	
	error = ES_OK ;

	return error ;

}







