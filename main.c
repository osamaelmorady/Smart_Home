/*
 * MAIN.C
 *
 *  Created on: Oct 22, 2020
 *      Author: Osama Elmorady
 */


#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO/DIO_Interface.h"
#include "LCD/LCD_Interface.h"
#include "KEYPAD_Interface.h"
#include "ADC/ADC_Interface.h"
#include "TIM0/TIM0_Interface.h"
#include "TIM2/TIM2_Interface.h"

#include <util/delay.h>

#define SIZE   6
#define Not_Pressed  '\0'


void clear_line(u8 num) ;
void free_name(u8 name[SIZE]) ;
u8 name_check(u8 name[SIZE]) ;
u8 pass_check(u8 password[SIZE]) ;




u8 username[SIZE]="15018"  ;
u8 userpassword[SIZE] = "13+89" ;
u8 user[SIZE]={} ;
u8 pass[SIZE]={} ;


u8 key = Not_Pressed ;
u8 trials=3 ;





int main(void)
{

KEYPAD_VidInit() ;
LCD_VidInit() ;

ADC_EnuInit() ;
ADC_EnuEnable() ;
ADC_EnuAutoTriggering(1) ;
ADC_EnuSelectChannel(PIN0) ;


TIM0_VidInit() ;
TIM2_VidInit() ;


// FAN Control
DIO_EnuSetPinDir(PIN0,INPUT) ;

// FAN
DIO_EnuSetPinDir(PIN11,OUTPUT) ;
DIO_EnuSetPinVal(PIN11,LOW) ;
// LIGHT
DIO_EnuSetPinDir(PIN31,OUTPUT) ;
DIO_EnuSetPinVal(PIN31,LOW) ;

// BUZZER
DIO_EnuSetPinDir(PIN30,OUTPUT) ;


u8 char_num=0 ;u8 k=0 ;
while(1)
{

	LCD_VidSetPosition(0,0) ;
	LCD_VidWriteString("Enter Username :") ;

	key=Not_Pressed;
	KEYPAD_U8GetKey(&key) ;
	if (key==Not_Pressed) { continue ; }

	else
	{

	   if( (key>='0' && key <='9') || (key=='+') || (key=='-')  || (key=='/')|| (key=='*') )
	   	{   LCD_VidSetPosition(1,2+k) ;
	   		user[char_num]=key ;
	   		LCD_VidSendData(key) ;
	   		char_num++;
	   		k++ ;
	   	}

		if (key=='E')
		{
			if (name_check(user) )
			{
				free_name(user) ;
				k=0 ;
				char_num=0 ;
				LCD_VidSendCommand(0x01) ;

				while(trials!=0)
				{
					u8 return_key=0 ;
					LCD_VidSetPosition(0,0) ;
					LCD_VidWriteString("Enter Password") ;

					key=Not_Pressed;
					KEYPAD_U8GetKey(&key) ;

					if( (key>='0' && key <='9') || (key=='+') || (key=='-') || (key=='/')|| (key=='*'))
						   	{   LCD_VidSetPosition(1,2+k) ;
						   		pass[char_num]=key ;
						   		LCD_VidSendData('*') ;
						   		char_num++;
						   		k++ ;
						   	}

					if (key=='E')
							{
								if(pass_check(pass))
									{
										free_name(pass) ;
										LCD_VidSendCommand(0x01) ;
										u16 fan_pos = 0 ;
										u8 light_inten = 0 ;

										while(1)
										{

											LCD_VidSetPosition(0,0) ;
											LCD_VidWriteString("Light  0,+,-") ;
											LCD_VidSetPosition(1,0) ;
											LCD_VidWriteString("Fan    Pot") ;
											key=Not_Pressed;
											KEYPAD_U8GetKey(&key) ;
											return_key=0 ;

											ADC_EnuStartConversion() ;
											ADC_EnuPolling() ;
											ADC_EnuRead(&fan_pos) ;

											fan_pos=(fan_pos*100)/1023 ;
											PWM0_SetDutyCycle(fan_pos) ;

											switch(key)
											{
											case '0' :	PWM2_SetDutyCycle(0);light_inten=0 ; 	break ;
											case '+' :	PWM2_SetDutyCycle(light_inten+=10) ;	break ;
											case '-' :	PWM2_SetDutyCycle(light_inten-=10) ;	break ;
											case 'C' :	return_key=1	;				        break ;
											default :break ;
											}

											if(return_key) {break ;}

										}
									}
								else
									{
										free_name(pass) ;
										k=0;
										char_num=0;
										LCD_VidSendCommand(0x01) ;
										LCD_VidSetPosition(0,0) ;
										LCD_VidWriteString("Wrong Password") ;
										_delay_ms(200) ;
										LCD_VidSendCommand(0x01) ;
										trials-=1 ;
											if (trials==0)
											{
												//BUZZER

												DIO_EnuSetPinVal(PIN30,HIGH) ;
												_delay_ms(500) ;

											}
									}
							}
					else if(key=='C' && k>0 )
							{
								pass[char_num]='\0' ;
								char_num-=1 ;
								k-=1 ;
								LCD_VidSetPosition(1,2+k) ;
								LCD_VidSendData(' ') ;

							}

					if(return_key) {LCD_VidSendCommand(0x01) ;   break ;}
				}
			}
			else
			{
				free_name(user) ;
				k=0 ;
				char_num=0 ;
				LCD_VidSendCommand(0x01) ;
				LCD_VidSetPosition(0,0) ;
				LCD_VidWriteString("Wrong username") ;
				_delay_ms(200) ;
			}
		}
		else if(key=='C' && k>0 )
		{
			user[char_num]='\0' ;
			char_num-=1 ;
			k-=1 ;
			LCD_VidSetPosition(1,2+k) ;
			LCD_VidSendData(' ') ;

		}


	}


}

return 0;
}




void clear_line(u8 num)
{
	if( num==0 || num==1 )
	{	LCD_VidSetPosition(num,0) ;
		LCD_VidWriteString("                                ") ;
	}
}


void free_name(u8 name[SIZE])
{
	for (u8 i=0;i<=SIZE;i++)
	{
		name[i]='\0' ;
	}

}



u8 name_check(u8 name[SIZE])
{
	u8 flag=0 ;
	for (u8 i=0;username[i]!='\0';i++)
	{
		if (name[i]!=username[i])
		{
			flag=0 ;
			break ;
		}
		else
		{
			flag=1 ;
		}

	}

	return flag ;

}



u8 pass_check(u8 password[SIZE])
{

	u8 flag=0 ;
		for (u8 i=0;userpassword[i]!='\0';i++)
		{
			if (password[i]!=userpassword[i])
			{
				flag=0 ;
				break ;
			}
			else
			{
				flag=1 ;
			}

		}

		return flag ;

}

