/*
 * ATmega32_SFRegisters.h
 *
 *  Created on: Dec 30, 2019
 *      Author: Sleem
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

#include "bit_math.h"
#include "types.h"

#define AVR_PORTA  ((volatile unsigned char* const)0X3B)
#define AVR_DDRA   ((volatile unsigned char* const)0X3A)
#define AVR_PINA   ((volatile unsigned char* const)0X39)
#define AVR_PORTB  ((volatile unsigned char* const)0X38)
#define AVR_DDRB   ((volatile unsigned char* const)0X37)
#define AVR_PINB   ((volatile unsigned char* const)0X36)
#define AVR_PORTC  ((volatile unsigned char* const)0X35)
#define AVR_DDRC   ((volatile unsigned char* const)0X34)
#define AVR_PINC   ((volatile unsigned char* const)0X33)
#define AVR_PORTD  ((volatile unsigned char* const)0X32)
#define AVR_DDRD   ((volatile unsigned char* const)0X31)
#define AVR_PIND   ((volatile unsigned char* const)0X30)

#define INPUT_PORT 0x00  // to set entire port as Input
#define OUTPUT_PORT 0xFF // to set entire port as output

#define Init_direction_default INPUT_PORT
#define no_of_pins_on_port  8
#define HIGH 1
#define LOW 0
#define INPUT 0
#define OUTPUT 1

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIM6 6
#define PIN7 7

#define PRTA 0
#define PRTB 1
#define PRTC 2
#define PRTD 3







 void GPIO_voidInit(void);   /* set all ports ass input direction */
//===================PIN==========================
                   //Data
 extern u8 GPIO_u8_ReadPinVal(u8 Port_Name,u8 PinIdx, u8* PtrToVal);/* Read Pin Value */
 extern u8 GPIO_u8_WritePinVal(u8 Port_Name,u8 PinIdx ,u8 PinVal); /* Write Pin Value */

                  //Direction
 extern u8 GPIO_u8_WritePinDir(u8 Port_Name,u8 PinIdx , u8 PinDir); /* Write Pin Direction */
 extern u8 GPIO_u8_ReadPinDir(u8 Port_Name,u8 PinIdx , u8* PtrToDir ); /*Read Pin Direction */

//===================PORT==========================
                  //Data
 extern u8 GPIO_u8_ReadPortVal(u8 Port_Name, u8* PtrToVal); /* Read Port Value */
 extern u8 GPIO_u8_WritePortVal(u8 Port_Name ,u8 PortVal );/* Write Port Value */

               //Direction
 extern u8 GPIO_u8_WritePortDir( u8 Port_Name ,u8 PortDir); /* Write Port Direction */
 extern u8 GPIO_u8_ReadPortDir(u8 Port_Name ,u8* Ptr2ToDir);/* Read Port Direction */


#endif /* GPIO_GPIO_H_ */