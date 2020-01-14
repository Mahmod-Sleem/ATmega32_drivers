/*
 * GPIO.c
 *
 *  Created on: Dec 30, 2019
 *      Author: Sleem
 */

#include "GPIO.h"

AccessLOC  GPIO_ports[] = {AVR_PORTA,AVR_PORTB,AVR_PORTC,AVR_PORTD};
AccessLOC  GPIO_dirs[] = {AVR_DDRA,AVR_DDRB,AVR_DDRC,AVR_DDRD};
AccessLOC  GPIO_pins[] = {AVR_PINA,AVR_PINB,AVR_PINC,AVR_PIND};

 void GPIO_voidInit(void)
{
	/* DDR initialization  */
	*GPIO_dirs[PRTA] = Init_direction_default; // pointer to arrary of Data direction location
	*GPIO_dirs[PRTB] = Init_direction_default;
	*GPIO_dirs[PRTC] = Init_direction_default;
	*GPIO_dirs[PRTD] = Init_direction_default;

}


u8 GPIO_u8_ReadPinVal(u8 Port_Name,u8 PinIdx, u8* PtrToVal)
{
	u8 API_Status ;

	if(PinIdx > no_of_pins_on_port - 1)
	{
		API_Status = Error; // there is error
	}
	else
	{

		*PtrToVal = GET_BIT(*GPIO_pins [Port_Name],PinIdx)  ;
		API_Status = NO_error; // successful process
	}

	return API_Status ;

}


u8 GPIO_u8_WritePinVal(u8 Port_Name,u8 PinIdx , u8 PinVal)
{
	u8 API_Status ;

	if(PinIdx > no_of_pins_on_port - 1)
	{
		API_Status = Error;
	}
	else
	{
		switch(PinVal)
		{
		case HIGH:
			 SET_BIT(*GPIO_ports[Port_Name] , PinIdx) ;
			API_Status = NO_error;
			break;
		case LOW:
			CLR_BIT(*GPIO_ports[Port_Name] , PinIdx) ;
			API_Status = NO_error;
			break;
		default:
			API_Status = Error;
			break;

		}
	}

	return API_Status ;

}


u8 GPIO_u8_WritePinDir(u8 Port_Name,u8 PinIdx , u8 PinDir)
{
	u8 API_Status ;

	if(PinIdx > no_of_pins_on_port - 1)
	{
		API_Status = Error;
	}
	else
	{
		switch(PinDir)
		{
		case HIGH:
			SET_BIT(*GPIO_dirs[Port_Name] , PinIdx);
			API_Status = NO_error;
			break;
		case LOW:
			CLR_BIT(*GPIO_dirs[Port_Name] , PinIdx);
			API_Status = NO_error;
			break;
		default:
			API_Status = Error;
			break;

		}
	}

	return API_Status ;

}


u8 GPIO_u8_ReadPinDir(u8 Port_Name,u8 PinIdx , u8* PtrToDir )
{

	u8 API_Status ;

	if(PinIdx > no_of_pins_on_port - 1)
	{
		API_Status = Error;
	}
	else
	{
		*PtrToDir = GET_BIT(*GPIO_dirs [Port_Name],PinIdx)  ;
		API_Status = NO_error;
	}

	return API_Status ;
}


u8 GPIO_u8_ReadPortVal(u8 Port_Name, u8* PtrToVal)
{

	*PtrToVal =  *GPIO_pins [Port_Name ] ;
	return NO_error ;
}


u8 GPIO_u8_WritePortVal(u8 Port_Name ,u8 PortVal )
{
	*GPIO_ports[Port_Name] = PortVal ;
	return NO_error ;
}


u8 GPIO_u8_WritePortDir( u8 Port_Name ,u8 PortDir)
{
	  *GPIO_dirs [Port_Name] = PortDir;

	return NO_error ;

}


u8 GPIO_u8_ReadPortDir(u8 Port_Name, u8* Ptr2ToDir)
{
	*Ptr2ToDir =  *GPIO_dirs[Port_Name];
	return NO_error ;
}
