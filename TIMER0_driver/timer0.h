/*
 * timer0.h
 *
 *  Created on: Jan 1, 2020
 *      Author: Sleem
 */

#ifndef TIMER0_H_
#define TIMER0_H_



enum WAVE_FORM_GEN  // timer  output compare  match interrupt enable TIMSK
{
	CTC,  //clear time on compare
	NORMAL // timeroverflow
};

enum TOVFIE0   // timer ofver flow interrupt enable
{
	TOIE0_ENABLE,
	TOIE0_DISABLE
};

enum OCMIE0 // output compare match interrupt enable
{
	OCIE0_ENABLE,
	OCIE0_DISABLE
};

enum TIMER0_PRESCALLER
{
	NO_CLK_SRC =0,
	NO_PRESCAL =1,
	PRESCALLING_8CLK =2 ,
	PRESCALLING_64CLK=3,
	PRESCALLING_256CLK=4,
	PRESCALLING_1024CLK=5,
	EXT_PRESCALLING_FALLING =6,
	EXT_PRESCALLING_RISING =7
};

struct STIMER0_SETTING
{
	enum TIMER0_PRESCALLER TIMER0_PRESCALLER ;
	enum OCMIE0  TIMER0_OCIE ;
	enum TOVFIE0 TIMER0_OVFI;
	enum WAVE_FORM_GEN TIMER0_MODE ;
};

 void TIMER0_Init (struct STIMER0_SETTING configuration ) ;
 void TIMER0_ReadCounterValue (u8 *NUMBER_OfTicks  );
 void TIMER0_SetCompareValue (u8 value );
 void TIMER0_SetOvfNumber (u8 number) ;
 void TIMER0_GetOvfNumber (u8* number );
 void TIMER0_GetTicks_FromSW (u8* number_ticks);
 void TIMER0_OVF_ISR (void (*ptr_to_timer0_ovf_handler_function) (void));
 void TIMER0_CTC_ISR(void (*ptr_to_timer0_CTC_handler_function) (void));

#endif /* TIMER0_H_ */


/*
 * timer terminology
 * timer clock = system clock / prescaller  ( timer clock defined as frequancy )
 * timer tick time : the time needed to increment tje timer register by one
 * timer tick time = prescaller /system clock (timer tick time defined ad cycles)
 * timer over folw = the time needed by the timer to count from 0 to 255 incase of our timer reslution equal to 8 bit
 * timer over flow = timer tick * 2^resolution (8 bit in timer 0 and 16 bit in timer2 )
 *
 * claculatino trmenilolgy
 * number of counts =  (desier time /overflow ) * timer count
 * preload value = timer count - number of counts needed
 * TCNT0 : intialize your tcnt0 by your preload or set its value directly
 *    i
 *
 *
 *    in case of the desired time is greater than our overflow with integer values
 *    number overflow = desired time / overflow time
 *
 *
 *
 *    incase of the desired time is geater than our overflow time with floating number
 *
 *    use the integer part to fetch number of over flow
 *    and intialize the floating part by preload value
 *
 *
 *
 * */
