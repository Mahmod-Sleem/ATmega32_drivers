/*
 * main.c
 *
 *  Created on: Jan 6, 2020
 *      Author: Sleem
 */


#include <avr/interrupt.h>
#include "LCD/LCD.h"
#include <util/delay.h>
#include "EXTI.h"
void INT0_Handler();
void INT1_Handler();
u8 count0 , count1 ;
int main ()
{


EXTI_Init(EXT_INT0,INT_LOW_LEVEL,&INT0_Handler);
EXTI_Init(EXT_INT1,INT_ANY_LOGIC_CHANGE,&INT1_Handler);
//SET_BIT(GICR,INT0);
//SET_BIT(GICR,INT1);
GICR=0xc0;
LCD_init();
	    sei();     // Enable global interrupts by setting global interrupt enable bit in SREG


		LCD_Send_String("WELCOME Ya SLEEM BASHA");
		_delay_ms(500);
		LCD_Send_Command(LCD_CLEAR_SCREEN);
		LCD_Send_String("INT0:");

			LCD_GotoXY(1,0);
			LCD_Send_String("INT1:");


while(1)
{
	LCD_GotoXY(0,6);
	LCD_display_number(count0);
	LCD_GotoXY(1,6);
	LCD_display_number(count1);
	//LCD_Send_Command(LCD_CLEAR_SCREEN);
}


}

void INT0_Handler()
{
count0++;

}

void INT1_Handler()
{
count1++;

}
