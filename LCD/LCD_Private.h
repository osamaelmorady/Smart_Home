/*
 * LCD_Private.h
 *
 *  Created on: Nov 6, 2020
 *      Author: Osama Elmorady
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_



/******************************************************/
/*************** LCD Mode Configurations **************/
/******************************************************/
#define LCD_4BIT_MODE 0
#define LCD_8BIT_MODE 1




/********************************************************/
/*************** LCD Screen Configurations **************/
/********************************************************/
#define LCD_FIRSTROW 	0
#define LCD_SECONDROW 	1

#define LCD_MIN_COL 	0
#define LCD_MAX_COL 	31






/*****************************************************************/
/*************** LCD Data BIT number Representation **************/
/*****************************************************************/
#define BIT0  	 0
#define BIT1  	 1
#define BIT2  	 2
#define BIT3  	 3
#define BIT4  	 4
#define BIT5  	 5
#define BIT6  	 6
#define BIT7  	 7




/*********************************************************/
/*************** LCD Commands Abbreviations **************/
/*********************************************************/
#define LCD_4BIT_MODE_SET_FUNCTION		0b00101000
#define LCD_8BIT_MODE_SET_FUNCTION		0b00111000

#define LCD_ON_CONTROL_DISPLAY			0b00001100
#define LCD_CLEAR_DISPLAY				0b00000001





/***** Assistant Function *****/
static void LCD_VidLatch(u8 Copy_U8Value) ;



#endif /* LCD_PRIVATE_H_ */
