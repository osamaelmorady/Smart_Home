/*
 * KEY_Interface.h
 *
 *  Created on: Nov 6, 2020
 *      Author: Osama Elmorady
 */

#ifndef 	KEY_INTERFACE_H_
#define 	KEY_INTERFACE_H_



#include "LIB/ERROR_STATE.h"



/***************************************************/
/*************** Keypad Initialization *************/
/***************************************************/
ErrorState KEYPAD_VidInit (void) ;





/********************************************************/
/*************** Keypad Get the pressed key *************/
/********************************************************/
ErrorState KEYPAD_U8GetKey (u8 * Copy_PU8PressedKey) ;




#endif 
