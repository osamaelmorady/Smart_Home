/*
 * TIM_Interface.h
 *
 *  Created on: Nov 8, 2020
 *      Author: Osama Elmorady
 */

#ifndef TIM2_INTERFACE_H_
#define TIM2_INTERFACE_H_


#include "LIB/ERROR_STATE.h"
#include "TIM2_Config.h"




ErrorState TIM2_VidInit(void) ;


ErrorState TIM2_VidEnable (void) ;



ErrorState TIM2_VidDisable (void) ;




ErrorState TIM2_VidSetCallBack(void (*PF)(void)) ;


void PWM2_SetDutyCycle(u8 Copy_U8Percent) ;















#endif /* TIM2_INTERFACE_H_ */
