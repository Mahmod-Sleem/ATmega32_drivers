/*
 * LCD.h
 *
 *  Created on: Dec 30, 2019
 *      Author: Sleem
 */

#ifndef LCD_H_
#define LCD_H_


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include "../GPIO/GPIO.h"

#define LCD_DATA_port PRTA
#define LCD_port PORTA
#define DataDir_LCD_port DDRA
#define DATA_shift 0               //0:4bit data mode | 4:4bit data mode
#define LCD_control_PORT PRTB
#define LCD_control PORTB
#define DataDir_LCD_control DDRB
#define EN 3
#define RW 2
#define RS 1

//#define	EIGHT_BIT_MODE
#define FOUR_BIT_MODE

#define LCD_FIRST_ROW								0
#define LCD_SECOND_ROW								1

#define LCD_FUNCTION_8BIT_2LINES   					0x38
#define LCD_FUNCTION_4BIT_2LINES   					0x28

#define LCD_MOVE_DISP_RIGHT      0x1C
#define LCD_MOVE_DISP_LEFT       0x18
#define LCD_MOVE_CURSOR_RIGHT    0x14
#define LCD_MOVE_CURSOR_LEFT     0x10
#define LCD_DISP_OFF   		     0x08
#define LCD_DISP_ON_CURSOR       0x0E
#define LCD_DISP_ON_CURSOR_BLINK 0x0F
#define LCD_DISP_ON_BLINK        0x0D
#define LCD_DISP_ON   		     0x0C
#define LCD_ENTRY_DEC   		 0x04
#define LCD_ENTRY_DEC_SHIFT   	 0x05
#define LCD_ENTRY_INC_   	     0x06
#define LCD_ENTRY_INC_SHIFT      0x07
#define LCD_BEGIN_AT_FIRST_RAW	 0x80
#define LCD_BEGIN_AT_SECOND_RAW	 0xC0
#define LCD_CLEAR_SCREEN         0x01
#define LCD_ENTRY_MODE	         0x06
#define LCD_RETURN_HOME          0x02



void LCD_init(void);
void LCD_ENABLE_DATA ();
void LCD_Send_Command(unsigned char command);
void LCD_Send_Character(unsigned char character);
void LCD_Send_String(char *string);
void LCD_GotoXY(unsigned char line, unsigned char position );
void LCD_display_number (int Number );
void LCD_display_real_number (double  Number );


#endif /* LCD_H_ */
