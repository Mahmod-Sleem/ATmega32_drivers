/*
* external_interrupt.c
*
* Created: 7/8/2018 5:01:14 PM
*  Author: ebrahim
*/

#include <avr/interrupt.h>
#include "EXTI.h"
// SOLID DATA



static void (*Call_backFromExtISR[3]) (void); // arry of pointers to funcation 


ISR(INT0_vect)//interrupt service routine when there is a change in logic level
{
	Call_backFromExtISR[0]();
}

ISR(INT1_vect)//interrupt service routine when there is a change in logic level
{
	Call_backFromExtISR[1]();
}

ISR(INT2_vect)//interrupt service routine when there is a change in logic level
{
	Call_backFromExtISR[2]();
}


void EXTI_Init(EXTI_FLAG INT_PINx,INT_SENCE_CONTROL Sence_Mode,void (*NotifyWhenISR)())
{
	switch (INT_PINx)
	{
		case EXT_INT0 :
		{
			GPIO_u8_WritePinDir(PRTD,PIN2,LOW);
			GPIO_u8_WritePinVal(MCUCR,ISC00,LOW) ;
			GPIO_u8_WritePinVal(MCUCR,ISC01,LOW) ;
			MCUCR |= Sence_Mode << ISC00; // adjust Sence mode
			Call_backFromExtISR[0]=NotifyWhenISR;
			break;
		}
		case EXT_INT1 :
		{
			GPIO_u8_WritePinDir(PRTD,PIN3,LOW);
			GPIO_u8_WritePinVal(MCUCR,ISC10,LOW) ;
			GPIO_u8_WritePinVal(MCUCR,ISC11,LOW) ;
			MCUCR |= Sence_Mode << ISC10;
			Call_backFromExtISR[1]=NotifyWhenISR;
			break;
		}
		case EXT_INT2 :
		{
			GPIO_u8_WritePinDir(PRTB,PIN2,LOW);
			if(Sence_Mode==INT_FALLING_EDGE)
			{
				CLR_BIT(MCUCSR,ISC2);

			}
			else if(Sence_Mode==INT_RISING_EDGE)
			{
				SET_BIT(MCUCSR,ISC2);
			}

			Call_backFromExtISR[2]=NotifyWhenISR;
			break;
		}
	}	
}

