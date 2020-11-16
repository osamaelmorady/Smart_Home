/*
 * TIM_Interface.h
 *
 *  Created on: Nov 8, 2020
 *      Author: Osama Elmorady
 */

#ifndef TIM0_INTERFACE_H_
#define TIM0_INTERFACE_H_


#include "LIB/ERROR_STATE.h"
#include "TIM0_Config.h"




ErrorState TIM0_VidInit(void) ;


ErrorState TIM0_VidEnable (void) ;



ErrorState TIM0_VidDisable (void) ;




ErrorState TIM0_VidSetCallBack(void (*PF)(void)) ;


void PWM0_SetDutyCycle(u8 Copy_U8Percent) ;















#endif /* TIM0_INTERFACE_H_ */
