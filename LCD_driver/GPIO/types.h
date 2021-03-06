/*
 * types.h
 *
 *  Created on: Dec 30, 2019
 *      Author: Sleem
 */

#ifndef GPIO_TYPES_H_
#define GPIO_TYPES_H_
#define NO_error 1
#define Error 0


typedef unsigned char u8 ;
typedef signed char s8 ;
typedef unsigned short u16 ;
typedef signed short s16  ;
typedef unsigned int u32  ;
typedef signed int s32  ;
typedef unsigned long long u64  ;
typedef signed long  long s64 ;
typedef float f32 ;
typedef double f64  ;

// sepcial type for accessing location
typedef  volatile unsigned char* AccessLOC ;

#endif /* GPIO_TYPES_H_ */
