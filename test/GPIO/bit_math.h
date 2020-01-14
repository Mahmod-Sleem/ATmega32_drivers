/*
 * bit_math.h
 *
 *  Created on: Dec 30, 2019
 *      Author: Sleem
 */

#ifndef GPIO_BIT_MATH_H_
#define GPIO_BIT_MATH_H_
#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)


#endif /* GPIO_BIT_MATH_H_ */
