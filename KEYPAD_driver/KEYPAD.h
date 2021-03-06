/*
 * KEYPAD.h
 *
 *  Created on: Dec 31, 2019
 *      Author: Sleem
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include <avr/io.h>
#include <util/delay.h>
#include "GPIO/GPIO.h"

//Keypad Information
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define KEYPAD_PORT PRTD
#define keypadPORT *AVR_PORTD
#define keypadPIN *AVR_PIND
#define keypadDDR *AVR_DDRD


//Keypad functions and global variables



void  Keypad_init();
u8 Keypad_getkey();

#endif /* KEYPAD_H_ */
