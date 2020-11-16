/*
 * ERROR_STATE.h
 *
 *  Created on: Nov 5, 2020
 *      Author: Osama Elmorady
 */

#ifndef ERROR_STATE_H_
#define ERROR_STATE_H_



typedef enum ERROR_STATE
{

	// Check for not met condition
	ES_NOK = 0 ,

	// Check for met condition
	ES_OK = 1 ,

	// Check for overflow condition
	ES_OV = 2 ,

	// Check for entered parameter is out of range condition
	ES_OUT_OF_RANGE = 3

} ErrorState ;





#endif /* ERROR_STATE_H_ */
