/*
 * main.c
 *
 *  Created on: Dec 31, 2019
 *      Author: Sleem
 */
#include "LCD/LCD.h"
#include "KEYPAD.h"

int main ()
{
u8 pressed=0  ;
LCD_init();
Keypad_init();

LCD_Send_String("WELCOME SLEEM");
_delay_ms(1000);
LCD_Send_Command(LCD_CLEAR_SCREEN);

while (1)
{
pressed = Keypad_getkey();
switch (pressed)
{
case 'A': break;
case '?': LCD_Send_Command(LCD_CLEAR_SCREEN);break ;
default :{
LCD_Send_Character(pressed);
}

}


}
return 0 ;
}
