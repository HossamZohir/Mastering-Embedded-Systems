/*
 * main.c
 *  Created on: Nov 29, 2024
 *      Author: Hossam
 *
 *	" Test of lifo implementation "
 */

#include "lifo.h"

#define buffer1_length 5
LIFO_element_type buffer1[buffer1_length];


int main()
{
	uint32_t i , temp=0;

	LIFO_Buf_t UART_lifo;

	// initialize of UART
	if(LIFO_Init(&UART_lifo,buffer1,5) == LIFO_No_Error )
		printf("=== LIFO init Done ===\n");
	else
		printf("=== LIFO init failed ===\n");

	LIFO_Print(&UART_lifo);

	for(i=0;i<5;i++)
	{
		LIFO_Add_item(&UART_lifo,&i);
		printf("%d",i);
	}
	LIFO_Print(&UART_lifo);

	if (LIFO_Get_item(&UART_lifo, &temp) == LIFO_No_Error)
	        printf("Retrieved last item: %d\n", temp);
	    else
	        printf("Failed to retrieve item.\n");

	LIFO_Print(&UART_lifo);



	return 0;
}

