/*
 * BIT_MATH.h
 *
 *  Created on: Nov 5, 2020
 *      Author: Osama Elmorady
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_



/* To Set a bit in a register  */
#define  SET_BIT(REG,PIN_NUMBER)  REG=REG|(1<<PIN_NUMBER)


/* To Clear a bit in a register  */
#define  CLR_BIT(REG,PIN_NUMBER)  REG=REG&(~(1<<PIN_NUMBER))


/* To Toggle a bit in a register  */
#define TOGGLE_BIT(REG,PIN_NUMBER)  REG=REG^(1<<PIN_NUMBER)



/* To Get a bit From a register  */
#define GET_BIT(REG,PIN_NUMBER)  (REG>>PIN_NUMBER)&1






#endif /* BIT_MATH_H_ */
