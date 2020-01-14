/*
 * main.c
 *
 *  Created on: Jan 13, 2020
 *      Author: Sleem
 */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "USART.h"

void (*UART_handler)(void);
void UART_config(USART_CONFIG config);
USART_CONFIG config ;
int main ()
{

	UART_config(config);
	USART_Init(config);


}

void UART_config(USART_CONFIG config)
{

	    config.DataBits = USART_8BIT_CHAR ;
		config.ModeSelect=USART_ASynchronous ;
		config.ParityStatus=USART_PARITY_DISABLE;
		config.RxMode=USART_RX_ENABLE;
		config.RxStatus=USART_RX_INT_DISABLE;
		config.SPEED_MODE=USART_NORMAL_SPEED ;
		config.StopBitStatus=USART_1BIT_STOP;
		config.TxMode= USART_TX_ENABLE ;
		config.TxStatus= USART_TX_INT_DISABLE;

}
