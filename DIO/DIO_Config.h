/*
 * DIO_Config.h
 *
 *  Created on: Nov 5, 2020
 *      Author: Osama Elmorady
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_



/*****************************************************************/
/*************** DIO PINS NUMBER CONFIGURATION *******************/
/*****************************************************************/
typedef enum DIO_PIN_NUMBER
{
	PIN0=0, PIN1  , PIN2  , PIN3  , PIN4  , PIN5  , PIN6  , PIN7   ,
	PIN8  ,	PIN9  , PIN10 , PIN11 , PIN12 , PIN13 , PIN14 , PIN15  ,
	PIN16 ,	PIN17 , PIN18 , PIN19 , PIN20 , PIN21 , PIN22 , PIN23  ,
	PIN24 ,	PIN25 , PIN26 , PIN27 , PIN28 , PIN29 , PIN30 , PIN31

}DIO_PIN_NUMBER ;





/*****************************************************************/
/*************** DIO PORT NUMBER CONFIGURATION *******************/
/*****************************************************************/
typedef enum DIO_PORT_NUMBER
{
	PORTA=0   ,   PORTB   ,   PORTC    ,  PORTD ,
	PINA=0    ,   PINB    ,   PINC     ,  PIND  ,
	DDRA=0    ,   DDRB    ,   DDRC     ,  DDRD

}DIO_PORT_NUMBER ;





/*****************************************************************/
/*************** DIO PINS STATUS CONFIGURATION *******************/
/*****************************************************************/
typedef enum DIO_PIN_STATUS
{
	LOW = 0 ,
	HIGH

} DIO_PIN_STATUS ;





/***************************************************************/
/*************** DIO PINS MODE CONFIGURATION *******************/
/***************************************************************/
typedef enum DIO_PIN_MODE
{
	INPUT = 0 ,
	OUTPUT

} DIO_PIN_MODE ;





#endif /* DIO_CONFIG_H_ */
