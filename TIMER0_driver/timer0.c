/*
 * timer0.c
 *
 *  Created on: Jan 1, 2020
 *      Author: Sleem
 */

#include "avr/io.h"
#include "GPIO/GPIO.h"
#include "timer0.h"
#include <avr/interrupt.h>

struct STIMER0_SETTING TIMER0_configuration  ;
u8 TOV_number ;
static void (*ptr_to_timer0_ovf_handler) (void);
static void (*ptr_to_timer0_CTC_handler) (void) ;


extern void TIMER0_Init (struct STIMER0_SETTING configuration )
{
	        // adjust mode
	TIMER0_configuration = configuration  ;
	if (TIMER0_configuration.TIMER0_MODE == NORMAL)
	{
		TCCR0 &=~(1<<WGM00);
		TCCR0 &=~(1<<WGM01);

	}
	if (TIMER0_configuration.TIMER0_MODE == CTC)
		{
			TCCR0 &=~(1<<WGM00);
			TCCR0 |=(1<<WGM01);

		}
	// adjust prescaller
	TCCR0= TCCR0 | TIMER0_configuration.TIMER0_PRESCALLER;

	// timer0 enable disable

	if(TIMER0_configuration.TIMER0_OVFI== TOIE0_ENABLE)
	{

		TIMSK |= (1<<TOIE0);
	}
	if(TIMER0_configuration.TIMER0_OVFI== TOIE0_DISABLE)
		{

			TIMSK &= ~(1<<TOIE0);
		}
	// ocr0 enable disable

	if (TIMER0_configuration.TIMER0_OCIE==OCIE0_ENABLE)
	{
		OCR0 |= (1<<OCIE0);
	}
	if (TIMER0_configuration.TIMER0_OCIE==OCIE0_DISABLE)
		{
			OCR0 &= ~(1<<OCIE0);
		}

}
extern void TIMER0_ReadCounterValue (u8 *NUMBER_OfTicks  )
{
	*NUMBER_OfTicks = TCNT0 ;

}
extern void TIMER0_SetCompareValue (u8 value )
{
	TCNT0 = value ;

}
extern void TIMER0_SetOvfNumber (u8 number)
{
	TOV_number = number ;
}
extern void TIMER0_GetOvfNumber (u8* number )
{
	*number = TOV_number ;
}
extern void TIMER0_GetTicks_FromSW (u8* number_ticks)
{
	*number_ticks = 256*TOV_number+ TCNT0 ;
}
extern void TIMER0_OVF_ISR (void (*ptr_to_timer0_ovf_handler_function) (void))
{
	 ptr_to_timer0_ovf_handler =ptr_to_timer0_ovf_handler_function ;
}
extern void TIMER0_CTC_ISR(void (*ptr_to_timer0_CTC_handler_function) (void))
{
	ptr_to_timer0_CTC_handler = ptr_to_timer0_CTC_handler_function ;
}


