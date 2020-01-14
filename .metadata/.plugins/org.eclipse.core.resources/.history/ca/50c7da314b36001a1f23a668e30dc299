/*
 * USART.c
 *
 *  Created on: Jan 13, 2020
 *      Author: Sleem
 */
#include <avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>
#include "GPIO/GPIO.h"
#include "USART.h"
static void(*PtrToTxFucn)(void);
static void(*PtrToRxFucn)(void);
USART_CONFIG GlobalUsartConfig ;

//*******************
/*
typedef struct uSART_CONFIG
{
	USART_Mode_Select ModeSelect ;
	USART_TX TxMode ;
	USART_RX RxMode ;
	USART_CHAR_SIZE DataBits ;
	USART_PARITY ParityStatus ;
	USART_STOP_BIT StopBitStatus ;
	USART_TX_INTERRUPT TxStatus ;
	USART_RX_INTERRUPT RxStatus ;

}USART_CONFIG;*/

//***********************

void USART_Init (USART_CONFIG UsartConfig )
{

	u16 UBRR_value ;
	GlobalUsartConfig = UsartConfig;

	//*********** adjust BUAD RATE by getting UBBR value *************
	if (GlobalUsartConfig.ModeSelect==USART_ASynchronous)
	{
		if (GlobalUsartConfig.SPEED_MODE == USART_NORMAL_SPEED)
		{
			UBRR_value = (u16)((F_CPU/(16*USART_BUADRATE))-1) ;
			// UMSEL at UCSRC
						UCSRC |= (1<<URSEL) | GlobalUsartConfig.ModeSelect;
		}
		else if (GlobalUsartConfig.SPEED_MODE == USART_DOUBLE_SPEED)
		{

			UBRR_value = (u16)((F_CPU/(8*USART_BUADRATE))-1) ;
			SET_BIT(UCSRA,U2X);
		}
	}
	else if (GlobalUsartConfig.ModeSelect==USART_Synchronous)
	{
		UBRR_value = (u16)((F_CPU/(2*USART_BUADRATE))-1) ;
					UCSRC |= (1<<URSEL) | (1<<UMSEL);
	}
	UBRRL = UBRR_value ;
	UBRRH = (UBRR_value>>8);


/***************************TRANSMITTER STATUS ****************/

	if (GlobalUsartConfig.TxMode==USART_TX_ENABLE)
		{SET_BIT(UCSRB,TXEN);}
	if (GlobalUsartConfig.TxMode==USART_TX_DISABLE)
		{CLR_BIT(UCSRB,TXEN);}

/***************************RECEIVER STATUS ****************/

		if (GlobalUsartConfig.RxMode==USART_RX_ENABLE)
			{SET_BIT(UCSRB,RXEN);}
		if (GlobalUsartConfig.RxMode==USART_RX_DISABLE)
			{CLR_BIT(UCSRB,RXEN);}

/*                SIT CHARCTER SIZE            */
		// UCSRC UCSZ1 , UCSZ0  && UCSRB UCSZ2
		if ( GlobalUsartConfig.DataBits != USART_9BIT_CHAR )
		 {
			    SET_BIT(UCSRC,URSEL);
				UCSRC |= (GlobalUsartConfig.DataBits<< UCSZ0);
		 }
		if ( GlobalUsartConfig.DataBits != USART_9BIT_CHAR )
		 {
				SET_BIT(UCSRB,UCSZ2);
				UCSRC |= ((1<<URSEL)|(GlobalUsartConfig.DataBits<< UCSZ0));
		 }

		    /**************** Set Parity Bit***************/
		    // UCSRC UPM1 , UPM0
			UCSRC |= (1<<URSEL) | (GlobalUsartConfig.ParityStatus<<UPM0);
			/**************** Set Stop Bit***************/
			//UCSRC USBS
			UCSRC |= (1<<URSEL) | (GlobalUsartConfig.StopBitStatus<<USBS);
			/***************RECIEVER INT ENABLE**********/
			// UCSRB  RXCIE
			UCSRB |= (GlobalUsartConfig.RxStatus<<RXCIE);
			/***************TRANSMITER INT ENABLE**********/
			// UCSRB  TXCIE
			UCSRB |= (GlobalUsartConfig.TxStatus<<TXCIE);


}

// TRANSMITTER  FUNCTIONS
void USART_TRANSMIT_DATA(u8 data )
{
	while (!( UCSRA & (1 << UDRE)));

/***********if the data to be transmitted is 9 bits, write the MSB first*****************/
if ( GlobalUsartConfig.DataBits==USART_9BIT_CHAR)
{
	UCSRB |= ((data >> 8) & 1);
}
/* Put data into buffer, sends the data */
		UDR = (u8)data;
}

void USART_Tx_ENABLE(void)
{
	UCSRB |= 1<<TXEN;
}
void USART_Tx_DISABLE(void)
{
	UCSRB &= ~ (1<<TXEN) ;
}
void USART_TxInt_ENABLE(void)
{
	UCSRB |= 1<< TXCIE ;
}
void USART_TxINT_DISABLE(void)
{
	UCSRB &= ~ (1<<TXCIE);
}
void USART_INT_TX_Handler  (void(*PtrToFucn)(void))
{
	PtrToTxFucn=PtrToFucn;
}
ISR(USART_RXC_vect)
{
	(*PtrToTxFucn)();
}

// RECEIVER FUNCTIONS
u8 USART_RECEIVE_DATA(u8 *PtrToVal)
{
	u8 local_u8ParityError = 0;  // 0 means error
		*PtrToVal = 0;
		/* Wait for data to be received */

		while (Bit_Is_Clear(UCSRA,RXC));
		/****************Check if parity error is not ON********/
		;
		if(GET_BIT(UCSRA,PE) != 1)
		{
			/***********if the data to be recieved is 9 bits, get the MSB first*****************/
		if (GlobalUsartConfig.DataBits  ==	USART_9BIT_CHAR){*PtrToVal = (((UCSRB >> 1)& 1) << 8) ;}
			/* Get and return received data from buffer */
			*PtrToVal |= UDR;
			local_u8ParityError = 1; //no error
		}
		return local_u8ParityError;

}
void USART_Rx_ENABLE(void)
{
	UCSRB |= 1<< RXEN ;
}
void USART_Rx_DISABLE(void)
{
	UCSRB &=~(1<<RXEN);
}
void USART_RxInt_ENABLE(void)
{
	UCSRB |= 1<< RXCIE ;
}
void USART_RxINT_DISABLE(void)
{
	UCSRB &= ~(1<<RXCIE);
}
void USART_INT_RX_Handler  (void(*PtrTo_RxFucn)(void))
{
	PtrToRxFucn=PtrTo_RxFucn;
}

ISR(USART_TXC_vect)
{
	(*PtrToRxFucn)();
}
