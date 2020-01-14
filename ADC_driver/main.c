/*
 * main.c
 *
 *  Created on: Jan 7, 2020
 *      Author: Sleem
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "ADC.h"
#include "GPIO/GPIO.h"
#include "LCD/LCD.h"

u16 val ;

void ADC_HANDLER(u16 val)
	{
	LCD_display_number((ADC_Read(ADC0)/5));

	}


int main(void)
	{
	LCD_init();
	ADC_Init(AFRE,ADC0,CLK_ADC_DIV_128,FREE_RUNNING_MODE);
		sei();
    LCD_Send_String("FINAL WELCOME  ");
    _delay_ms(1000);
    LCD_Send_Command(LCD_CLEAR_SCREEN);

		while (1)
		{
			ADC_Interrupt_Enable(ADC_HANDLER,ADC0);
			_delay_ms(1000);
			LCD_Send_Command(LCD_CLEAR_SCREEN);

		}
	}



