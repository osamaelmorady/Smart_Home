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

#define REG_ADCH		0x25
#define REG_ADCL		0x24







/****************************************/
/****  Define AVR Timer 0 Addresses  ****/
/****************************************/
#define REG_TCCR0		0x53
#define REG_TCNT0		0x52
#define REG_OCR0		0x5C


/****************************************/
/****  Define AVR Timer 2 Addresses  ****/
/****************************************/
#define REG_TCCR2		0x45
#define REG_TCNT2		0x44
#define REG_OCR2		0x43
#define REG_ASSR		0x42


/****************************************/
/****  Define AVR Timer 1 Addresses  ****/
/****************************************/
#define REG_TCCR1A		0x4F
#define REG_OCR1AH		0x4B
#define REG_OCR1AL		0x4A

#define REG_TCCR1B		0x4E
#define REG_OCR1BH		0x49
#define REG_OCR1BL		0x48

#define REG_TCNT1H		0x4D
#define REG_TCNT1L		0x4C

#define REG_ICR1H		0x47
#define REG_ICR1L		0x46




/**********************************************/
/****  Define AVR Timers Common Addresses  ****/
/**********************************************/
#define REG_TIMSK			0x59
#define REG_TIFR			0x58
#define REG_SFIOR			0x50




/*******************************************/
/****  Define AVR Interrupt  Addresses  ****/
/*******************************************/
#define REG_SREG			0x5F








/***************************************/
/****  Define AVR USART  Addresses  ****/
/***************************************/
#define REG_UDR		 0x2C
#define REG_UCSRA    0x2B
#define REG_UCSRB    0x2A
#define REG_UCSRC    0x40
#define REG_UBRRH    0x40
#define REG_UBRRL    0x29







/*************************************/
/****  Define AVR SPI  Addresses  ****/
/*************************************/
#define REG_SPCR 	0x2D
#define REG_SPSR	0x2E
#define REG_SPDR	0x2F





/*************************************/
/****  Define AVR I2C  Addresses  ****/
/*************************************/
#define REG_TWBR 	0x20
#define REG_TWSR	0x21
#define REG_TWAR	0x22
#define REG_TWDR	0x23
#define REG_TWCR	0x56







#endif
