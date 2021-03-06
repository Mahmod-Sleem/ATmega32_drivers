/*
 * external_interrupt.h
 *
 * Created: 7/8/2018 4:48:18 PM
 *  Author: ebrah
 */ 

#ifndef EXTI_H_
#define EXTI_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "GPIO/GPIO.h"

typedef enum
{
	INT_LOW_LEVEL,
	INT_ANY_LOGIC_CHANGE,
	INT_FALLING_EDGE,
	INT_RISING_EDGE
} INT_SENCE_CONTROL;

typedef enum
{
	EXT_INT0=6,
	EXT_INT1=7,
	EXT_INT2=5,
} EXTI_FLAG;



void EXTI_Init(EXTI_FLAG INT_PINx,INT_SENCE_CONTROL Sence_Mode,void (*NotifyWhenISR)());

#endif /* EXTI_H_ */
