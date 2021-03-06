/*
 * KEYPAD.c
 *
 *  Created on: Dec 31, 2019
 *      Author: Sleem
 */

#include "KEYPAD.h"

 u8 ARR_BUTTON[4][4]=
				   {
	                {'7','4','1','?'},
					{'8','5','2','0'},
					{'9','6','3','='},
					{'/','*','-','+'}
				   };



void  Keypad_init()
{
	//GPIO_u8_WritePortDir(KEYPAD_PORT,0xf0);
	keypadDDR = 0x0F;
	//the part of the keypad port where the rows are connected.
	keypadPORT = 0xFF;

}



u8 Keypad_getkey()
{
u8 val='A' ;
	  u8 col=0, row=0 ;
	for(col=0 ; col<4; col++)
	{

		GPIO_u8_WritePinVal(KEYPAD_PORT,col,LOW);//send a low to a particular row of the keypad

		for(row=4 ; row<8; row++)

		{
			if((GET_BIT(keypadPIN,row))==0)//check if key is pressed
			{
				while ((GET_BIT(keypadPIN,row))==0);
				val =  ARR_BUTTON[row-4][col];

		    }
	}
		GPIO_u8_WritePinVal(KEYPAD_PORT,col,HIGH);
}
return val ;
}


