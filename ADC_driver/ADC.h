/*
 * adc.h
 *
 *  Created on: Jan 7, 2020
 *      Author: Sleem
 */

#ifndef ADC_H_
#define ADC_H_

#include "GPIO/GPIO.h"

 //ADC Multiplexer SelectionRegister � ADMUX
//    Bit 7:6 � REFS1:0: Reference Selection Bits
typedef enum {AFRE=0,
			AVCC=1 ,
		INTERNAL_VREF=3}vref_select ;


		//ADC Multiplexer SelectionRegister � ADMUX
	//Bits 4:0 � MUX4:0: Analog Channel and Gain Selection Bits
typedef enum {

	 ADC0=0,
	 ADC1=1,
	 ADC2=2,
	 ADC3 =3,
	 ADC4=4,
	 ADC5=5,
	 ADC6=6,
	 ADC7=7,
}Channel_Select ;

//ADC Multiplexer SelectionRegister � ADMUX
 //Bit 5 � ADLAR: ADC Left Adjust Result

//ADC Control and Status Register A � ADCSRA
//Bits 2:0 � ADPS2:0: ADC Prescaler Select Bits
typedef enum {
	    CLK_ADC_DIV_2=1,
		CLK_ADC_DIV_4 = 2,
		CLK_ADC_DIV_8 = 3,
		CLK_ADC_DIV_16 = 4,
		CLK_ADC_DIV_32 = 5,
		CLK_ADC_DIV_64 = 6,
		CLK_ADC_DIV_128 = 7,


}Prescaller_Select  ;

//Special FunctionIO Register � SFIOR
//Bit 7:5 � ADTS2:0: ADC Auto Trigger Source

typedef enum
{
	FREE_RUNNING_MODE = 0,
	ANALOG_COMPARTOR = 1,
	EXTERNAL_INITERRUPT0 = 2,
	COMPARE_MATCH_TIMER0 = 3,
	OVERFLOW_TIMER0 = 4,
	COMPARE_MATCH_TIMER1=5,
	OVERFLOW_TIMER1=6,
} Mode_Select;


void ADC_Init (vref_select u8_Vref,Channel_Select u8_Channle,Prescaller_Select u8_Prescaller, Mode_Select u8_mode );
u16 ADC_Read ( Channel_Select u8_Channle);
void ADC_Interrupt_Enable (void (*PtrToFun_CallBack)(u16 u16_value),Channel_Select u8_Channle );


#endif /* ADC_H_ */
