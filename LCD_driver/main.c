/*
 * main.c
 *
 *  Created on: Dec 30, 2019
 *      Author: Sleem
 */
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include "LCD.h"

int main (void )
{

	LCD_init() ;
    int i=1;

	while (1)
	{

		LCD_Send_String("MOHMAD SLEEM BY7YKOM");

		LCD_GotoXY(1,0);
		_delay_ms(1000) ;
		LCD_Send_Command(LCD_CLEAR_SCREEN);
		LCD_Send_Command(LCD_BEGIN_AT_SECOND_RAW);
		LCD_Send_String("MAHMOD SAFER :");
		_delay_ms(1000) ;
		LCD_Send_Command(LCD_CLEAR_SCREEN);
		while (i<33){
LCD_display_real_number(i+.5);
_delay_ms(500);
		i++;
		}
	}
}
