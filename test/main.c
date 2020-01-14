/*
 * main.c
 *
 *  Created on: Dec 30, 2019
 *      Author: Sleem
 */
#include "keypad.h"
#include "LCD/LCD.h"

int main ()
{
LCD_init();
Keypad_init();

char pressed ;

while (1)
{
	LCD_Send_String("WELCOME SLEEM");
	LCD_GotoXY(1,0);
pressed = Keypad_getkey();
 LCD_Send_Character(pressed);
_delay_ms(500);


}



}

