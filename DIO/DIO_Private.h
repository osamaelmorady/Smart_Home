/*
 * DIO_Private.h
 *
 *  Created on: Nov 5, 2020
 *      Author: Osama Elmorady
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_





/**************************************************/
/**********  Define DIO Pins Mode  *************/
/**************************************************/
#define DIO_INPUT 	0
#define DIO_OUTPUT  1





/**************************************************/
/**********  Define DIO Pins Status  *************/
/**************************************************/
#define DIO_LOW		0
#define DIO_HIGH  	1




/**************************************************/
/**********  Define DIO Pins Numbers  *************/
/**************************************************/

#define  DIO_PIN0       0
#define  DIO_PIN1       1
#define  DIO_PIN2       2
#define  DIO_PIN3       3
#define  DIO_PIN4       4
#define  DIO_PIN5       5
#define  DIO_PIN6       6
#define  DIO_PIN7       7
#define  DIO_PIN8       8
#define  DIO_PIN9       9
#define  DIO_PIN10      10
#define  DIO_PIN11      11
#define  DIO_PIN12      12
#define  DIO_PIN13      13
#define  DIO_PIN14      14
#define  DIO_PIN15      15
#define  DIO_PIN16      16
#define  DIO_PIN17      17
#define  DIO_PIN18      18
#define  DIO_PIN19      19
#define  DIO_PIN20      20
#define  DIO_PIN21      21
#define  DIO_PIN22      22
#define  DIO_PIN23      23
#define  DIO_PIN24      24
#define  DIO_PIN25      25
#define  DIO_PIN26      26
#define  DIO_PIN27      27
#define  DIO_PIN28      28
#define  DIO_PIN29      29
#define  DIO_PIN30      30
#define  DIO_PIN31      31





/**************************************************/
/****  Define AVR Control Registers Addresses  ****/
/**************************************************/
#define DIO_DDRA  (*(volatile u8 *)REG_DDRA)
#define DIO_DDRB  (*(volatile u8 *)REG_DDRB)
#define DIO_DDRC  (*(volatile u8 *)REG_DDRC)
#define DIO_DDRD  (*(volatile u8 *)REG_DDRD)



/***********************************************/
/*****  Define AVR OUTPUT Ports Addresses  *****/
/***********************************************/
#define DIO_PORTA  (*(volatile u8 *)REG_PORTA)
#define DIO_PORTB  (*(volatile u8 *)REG_PORTB)
#define DIO_PORTC  (*(volatile u8 *)REG_PORTC)
#define DIO_PORTD  (*(volatile u8 *)REG_PORTD)




/********************************************/
/****  Define AVR INPUT Ports Addresses  ****/
/********************************************/
#define DIO_PINA  (*(volatile u8 *)REG_PINA)
#define DIO_PINB  (*(volatile u8 *)REG_PINB)
#define DIO_PINC  (*(volatile u8 *)REG_PINC)
#define DIO_PIND  (*(volatile u8 *)REG_PIND)








#endif /* DIO_PRIVATE_H_ */
