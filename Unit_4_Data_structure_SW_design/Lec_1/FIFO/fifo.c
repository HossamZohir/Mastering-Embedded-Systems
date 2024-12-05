/*
 * fifo.c
 *
 *  Created on: Dec 3, 2024
 *      Author: Hossam
 */
#include "fifo.h"

//=================================================================================================
FIFO_Status_t FIFO_Init(FIFO_Buf_t* FIFO_Buf, FIFO_element_type* buffer, FIFO_element_type length )
{
	//check if the Buffer used is valid
	if (buffer == NULL)
		return FIFO_Null;

	//assign the length,count,base and head location at the top of the buffer
	FIFO_Buf->length = length;
	FIFO_Buf->count = 0;
	FIFO_Buf->base = buffer;
	FIFO_Buf->head = FIFO_Buf->base;
	FIFO_Buf->tail = FIFO_Buf->base;

	return FIFO_No_Error;
}

//=================================================================================================
FIFO_Status_t FIFO_is_full(FIFO_Buf_t* FIFO_Buf)
{
	//check if the FIFO is valid
	if (!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
		return FIFO_Null;

	// check if the FIFO is full or not
	if (FIFO_Buf->count == FIFO_Buf->length)
		return FIFO_Full;

	return FIFO_No_Error;
}

//=================================================================================================
FIFO_Status_t FIFO_Enqueue(FIFO_Buf_t* FIFO_Buf, FIFO_element_type* item)
{
	//check if the FIFO is valid
	if (!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
		return FIFO_Null;

	// check if the FIFO is full or not
	if (FIFO_Buf->count == FIFO_Buf->length)
		return FIFO_Full;


	// Enqueue the item and increment the count
	*(FIFO_Buf->head) = *(item);
	FIFO_Buf->count++;

	// Wrap around "HEAD" "CIRCULAR FIFO" (DRAW)
	// if (FIFO_Buf->head == (FIFO_Buf->base + (FIFO_Buf->length * sizeof(FIFO_element_type))))
	if (FIFO_Buf->head == (FIFO_Buf->base + FIFO_Buf->length))
		FIFO_Buf->head = FIFO_Buf->base;
	else
		FIFO_Buf->head++;

	return FIFO_No_Error;
}

//=================================================================================================
FIFO_Status_t FIFO_Dequeue(FIFO_Buf_t* FIFO_Buf, FIFO_element_type* item)
{
	//check if the FIFO is valid
	if (!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
		return FIFO_Null;

	// check if the FIFO is empty or not
	if (FIFO_Buf->count == 0)
		return FIFO_Empty;

	// dequeue the item and decrement the count
	*(item) = *(FIFO_Buf->tail);
	FIFO_Buf->count--;

	// Wrap around "tail" "CIRCULAR FIFO" (DRAW)
	// if (FIFO_Buf->tail == (FIFO_Buf->base + (FIFO_Buf->length * sizeof(FIFO_element_type))))
	if (FIFO_Buf->tail == (FIFO_Buf->base + FIFO_Buf->length))
		FIFO_Buf->tail = FIFO_Buf->base;
	else
		FIFO_Buf->tail++;

	return FIFO_No_Error;
}

//=================================================================================================
void FIFO_Print(FIFO_Buf_t* FIFO_Buf)
{
	//check if the FIFO is valid
	if (!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
	{
		printf("==== FIFO is Null ====\n");
		return;
	}

	//check if the FIFO is empty or not
	if (FIFO_Buf->count == 0)
	{
		printf("==== FIFO is Empty ====\n");
		return;
	}

	// make the print if valid and not empty
	FIFO_element_type* temp;
	int i;
	temp = FIFO_Buf->tail ;

	printf("\n==== FIFO Print ====\n");
	for (i=0;i<FIFO_Buf->count;i++)
	{
		printf("\t %X \n",*temp);
		temp++;

		// Wrap around if needed
		if (temp == (FIFO_Buf->base + FIFO_Buf->length))
			temp = FIFO_Buf->base;
	}

	printf("\n=======================================\n");
}
