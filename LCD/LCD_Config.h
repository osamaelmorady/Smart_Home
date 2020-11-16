/*
 * LCD_Config.h
 *
 *  Created on: Nov 6, 2020
 *      Author: Osama Elmorady
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


/************************************************************/
/*************** LCD Connection Mode (4-8)Bits **************/
/************************************************************/
#define  LCD_MODE 	 LCD_8BIT_MODE
//#define  LCD_MODE  LCD_4BIT_MODE




/*******************************************************/
/*************** LCD Data CONNECTION PINS **************/
/*******************************************************/

#define LCD_D0		PIN16
#define LCD_D1		PIN17
#define LCD_D2		PIN18
#define LCD_D3		PIN19



/* This Pins For LCD 4Bit Mode */
/*******************************/
#define LCD_D4		PIN20
#define LCD_D5		PIN21
#define LCD_D6		PIN22
#define LCD_D7		PIN23



/*******************************************************/
/*************** LCD Data CONNECTION PINS **************/
/*******************************************************/
#define LCD_RS		PIN24
#define LCD_RW		PIN25
#define LCD_EN		PIN26






#endif /* LCD_CONFIG_H_ */
