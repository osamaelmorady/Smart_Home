/*
 * AVR32_REG.h
 *
 *  Created on: Nov 5, 2020
 *      Author: Osama Elmorady
 */

/**************************************************/
/********  Define AVR DIO_PRIVATE Header  *********/
/**************************************************/
#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_




/********************************/
/*  Define Input & Output mode  */
/********************************/
#define  PIN_INPUT   0
#define  PIN_OUTPUT  1



/********************************/
/*  Define Input & Output mode  */
/********************************/
#define  PIN_LOW   0
#define  PIN_HIGH  1




/**************************************************/
/****  Define AVR Control Registers Addresses  ****/
/**************************************************/
#define REG_DDRA  0x3A
#define REG_DDRB  0x37
#define REG_DDRC  0x34
#define REG_DDRD  0x31



/***********************************************/
/*****  Define AVR OUTPUT Ports Addresses  *****/
/***********************************************/
#define REG_PORTA  0x3B
#define REG_PORTB  0x38
#define REG_PORTC  0x35
#define REG_PORTD  0x32




/********************************************/
/****  Define AVR INPUT Ports Addresses  ****/
/********************************************/
#define REG_PINA  0x39
#define REG_PINB  0x36
#define REG_PINC  0x33
#define REG_PIND  0x30



/************************************/
/****  Define AVR ADC Addresses  ****/
/************************************/
#define REG_ADMUX 		0x27
#define REG_ADCSRA		0x26
#define REG_SFIOR		0x50

#define REG_ADCH			0x25
#define REG_ADCL			0x24









#endif
