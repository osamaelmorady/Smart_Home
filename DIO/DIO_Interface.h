/*
 * DIO_Interface.h
 *
 *  Created on: Nov 5, 2020
 *      Author: Osama Elmorady
 */


/**************************************************/
/****  Define DIO_Interface Functions For User ****/
/**************************************************/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#include "DIO_Config.h"
#include "LIB/ERROR_STATE.h"







/****************************************************************/
/****  Define the direction of Pin as an input or an output  ****/
/****************************************************************/
ErrorState DIO_EnuSetPinDir( u8 Copy_U8PinNumber , u8 Copy_U8PinDir ) ;





/************************************/
/****  Define a value on a pin   ****/
/************************************/
ErrorState DIO_EnuSetPinVal(u8 Copy_U8PinNumber , u8 Copy_U8Value) ;






/*********************************/
/****  Get a value from a pin ****/
/*********************************/
ErrorState DIO_EnuGetPinVal(u8 Copy_U8PinNumber , u32 * Copy_PU8Value) ;





/*****************************/
/****  Toggle a pin Value ****/
/*****************************/
ErrorState DIO_EnuTogglePin(u8 Copy_U8PinNumber) ;








/*****************************************************************/
/****  To set the port direction as an input or as an output  ****/
/*****************************************************************/
ErrorState DIO_EnuSetPortDir( u8 Copy_U8PortNum , u8 Copy_U8PortDirectionValue ) ;



/************************************/
/****  To set a value on a port  ****/
/************************************/
ErrorState DIO_EnuSetPortVal( u8 Copy_U8PortNum , u8 Copy_U8Value ) ;








#endif /* DIO_INTERFACE_H_ */
