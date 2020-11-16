/*
 * LCD_Interface.h
 *
 *  Created on: Nov 6, 2020
 *      Author: Osama Elmorady
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



#include "LIB/ERROR_STATE.h"

/*********************************************/
/*********  Send a Character to LCD  *********/
/*********************************************/
ErrorState LCD_VidSendData (u8 Copy_U8Data) ;





/*********************************************/
/***********  Send a Command to LCD  *********/
/*********************************************/
ErrorState LCD_VidSendCommand (u8 Copy_U8Command) ;





/***********************************************/
/***********  Initialization of a LCD  *********/
/***********  LCD Connection Selection *********/
/*********** _8BIT MODE  or _4BIT MODE *********/
/***********************************************/
ErrorState LCD_VidInit(void) ;






/****************************************************************/
/***********  Set the LCD Cursor Position on the Screen *********/
/****************************************************************/
ErrorState LCD_VidSetPosition ( u8 Copy_U8RowNumber,u8 Copy_U8ColumnNumber ) ;






/****************************************************************/
/***********  Write a Sentence ( string ) on the Screen *********/
/****************************************************************/
ErrorState LCD_VidWriteString (u8 * Copy_PU8Name) ;






/*********************************************************************/
/***********  Write a Sentence ( INT Numbers ) on the Screen *********/
/*********************************************************************/
ErrorState LCD_VidWriteIntNum(s32 Copy_S32IntData) ;






/***********************************************************************/
/***********  Write a Sentence ( Float Numbers ) on the Screen *********/
/***********************************************************************/
ErrorState LCD_VidWriteFloatNum(f32 Copy_F32IntData) ;






/*******************************************************************/
/***********  Record a Special Character in the LCD CG-RAM *********/
/*******************************************************************/
ErrorState LCD_VidRecordSpecialChar (u8 Copy_U8PatternMatrix[8],u8 Copy_U8CGRAMPos) ;







/**************************************************************************/
/***********  Write a Special Character on the Screen form CG-RAM *********/
/**************************************************************************/
ErrorState LCD_VidWriteSpecialChar ( u8 Copy_U8CharPattern ) ;



























#endif /* LCD_INTERFACE_H_ */
