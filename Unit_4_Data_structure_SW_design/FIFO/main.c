/*
 * main.c
 *
 *  Created on: Dec 3, 2024
 *      Author: Hossam
 *
 *     " test of fifo implementation "
 */
#include "fifo.h"

#define buffer1_length 5
FIFO_element_type buffer1[buffer1_length];

int main()
{
	FIFO_Buf_t UART_FIFO;
	uint32_t i , temp=0;
	FIFO_Init(&UART_FIFO, buffer1, buffer1_length);
	for(i=0;i<7;i++)
	{
		FIFO_Enqueue(&UART_FIFO, &i);
	}
	FIFO_Print(&UART_FIFO);

	FIFO_Dequeue(&UART_FIFO,&temp);
	FIFO_Print(&UART_FIFO);
	for(i=0;i<7;i++)
	{
		FIFO_Dequeue(&UART_FIFO,&temp);
	}

	FIFO_Print(&UART_FIFO);
	return 0;
}
