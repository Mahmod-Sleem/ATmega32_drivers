/*
 * LCD.c
 *
 *  Created on: Dec 30, 2019
 *      Author: Sleem
 */

#include "LCD.h"
#include <string.h>





void LCD_init(void)
{
	_delay_ms(20);
		DataDir_LCD_control |= (1<<EN | 1<<RW | 1<<RS) ;
		LCD_control &= ~(1<<EN | 1<<RW | 1<<RS) ;
		DataDir_LCD_port = 0xff ;
		_delay_ms(15);// after power up you should wait 15ms to enter in intialization mode

		LCD_Send_Command(LCD_CLEAR_SCREEN);

	#ifdef EIGHT_BIT_MODE
		LCD_Send_Command(LCD_FUNCTION_8BIT_2LINES);

	#endif
	#ifdef FOUR_BIT_MODE
		LCD_Send_Command(0x02);

		LCD_Send_Command(LCD_FUNCTION_4BIT_2LINES);

	#endif

		LCD_Send_Command(LCD_ENTRY_MODE);
		LCD_Send_Command(LCD_BEGIN_AT_FIRST_RAW);
		LCD_Send_Command(LCD_DISP_ON);
}



void LCD_GotoXY(u8 line, u8 position )
{

	if(line==LCD_FIRST_ROW)
	{
		if (position < 16 && position >=0)
			LCD_Send_Command(LCD_BEGIN_AT_FIRST_RAW+position);
	}
	else if (line==LCD_SECOND_ROW)
	{
		if (position < 16 && position >=0)
			LCD_Send_Command(LCD_BEGIN_AT_SECOND_RAW + position);
	}
}


void LCD_Send_Command(u8 command)
{
// note that in main function you should make delay not less than 100us to let lcd cofigure the command
	// for RETURN_HOME and CLERA_SCREAN command you should wait 2ms
#ifdef EIGHT_BIT_MODE

	GPIO_u8_WritePinVal(LCD_control_PORT,RS,LOW);
	GPIO_u8_WritePinVal(LCD_control_PORT,RW,LOW); // write pin RW ,RS as LOW value
	GPIO_u8_WritePortVal(LCD_DATA_port,command)  ; // write data  port value

	//LCD_port = command  ;
	//LCD_control &= ~ ((1<<RW)|(1<<RS));
	LCD_ENABLE_DATA ();
#endif
#ifdef FOUR_BIT_MODE


	//LCD_port = command & 0xF0;
	GPIO_u8_WritePinVal(LCD_control_PORT,RS,LOW);
	GPIO_u8_WritePinVal(LCD_control_PORT,RW,LOW);// write pin value rw , rs as low value
	LCD_port = (LCD_port & 0x0F) | (command & 0xF0);
	LCD_ENABLE_DATA ();  // delay

	//LCD_port = ROTATE_LEFT(command,4);
	GPIO_u8_WritePinVal(LCD_control_PORT,RS,LOW);
	GPIO_u8_WritePinVal(LCD_control_PORT,RW,LOW);// write pin value rw , rs as low value
	LCD_port = (LCD_port & 0x0F) | (command << 4);
	LCD_ENABLE_DATA ();

#endif

}

void LCD_Send_Character(u8 character)
{
	// to send data to lcd you should set RS and clear RW then put your data on data pins
	// send high to low pulse on  E to enable the internal latch of lcd

#ifdef EIGHT_BIT_MODE
	GPIO_u8_WritePinVal(LCD_control_PORT,RS,HIGH); //turn RS ON for Data mode.
	GPIO_u8_WritePinVal(LCD_control_PORT,RW,LOW);
	GPIO_u8_WritePortVal(LCD_DATA_port,character);
	LCD_ENABLE_DATA ();
#endif

#ifdef FOUR_BIT_MODE

	    GPIO_u8_WritePinVal(LCD_control_PORT,RS,HIGH); //turn RS ON for Data mode.
		GPIO_u8_WritePinVal(LCD_control_PORT,RW,LOW);
		 LCD_port = (LCD_port & 0x0F) | (character & 0xF0);
		LCD_ENABLE_DATA ();


		GPIO_u8_WritePinVal(LCD_control_PORT,RS,HIGH); //turn RS ON for Data mode.
		GPIO_u8_WritePinVal(LCD_control_PORT,RW,LOW);
		LCD_port = (LCD_port & 0x0F) | (character << 4);
		LCD_ENABLE_DATA ();
#endif
}


void LCD_Send_String(u8 *StringOfCharacters)
{

	int count=0 ;//to count how much char on the line (it should be 16 char only)
	while(*StringOfCharacters > 0)
	{
		count++;
		LCD_Send_Character(*StringOfCharacters++);
		if (count == 16  ) // go to the second line
		{
			LCD_GotoXY(1,0); //line 1 position zero
		}
		else if (count == 32 || count==33) // clear screen and show again
		{
			LCD_Send_Command(LCD_CLEAR_SCREEN);
			LCD_GotoXY(0,0); //line 0 position zero
			count = 0 ;
		}
	}
}


void LCD_ENABLE_DATA ()
{
	GPIO_u8_WritePinVal(LCD_control_PORT,EN,HIGH);

	_delay_ms (50) ;
	GPIO_u8_WritePinVal(LCD_control_PORT,EN,LOW);
	_delay_ms (1) ;

}


void LCD_display_number (u8 Number )
{

	u8  str[7];

	//sprintf(str,"%d",Number);	// Adjust the formatting to your liking.
    itoa(Number,str,10);
	LCD_Send_String (str) ;

}

void LCD_display_real_number (f64  Number )
{

	u8  str[16];


	u8 *tmpSign = (Number < 0) ? "-" : "";
	f32 tmpVal = (Number < 0) ? -Number : Number;

	u8 tmpInt1 = tmpVal;                  // Get the integer (678).
	f32 tmpFrac = tmpVal - tmpInt1;      // Get fraction (0.0123).
	u8 tmpInt2 = tmpFrac * 10000;
	// Turn into integer (123).

	//extern char *dtostre(double __val, char *__s, unsigned char __prec,
	//dtostre( Number,str,3);

	// Print as parts, note that you need 0-padding for fractional bit.
	sprintf (str, "%s%d.%01d", tmpSign, tmpInt1, tmpInt2);
	LCD_Send_String (str) ;

}

// how to send code or data using single port ie. PORTA
//

