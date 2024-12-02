/*
 * lifo.c
 *
 *  Created on: Nov 29, 2024
 *      Author: Hossam
 */

#include "lifo.h"

LIFO_Status LIFO_Add_item(LIFO_Buf_t* LIFO_Buf, unsigned int item)
{
	//check if the LIFO is valid
	if (!LIFO_Buf->base || !LIFO_Buf->head)
			return LIFO_Null;

	//check if the LIFO is not full
	if (LIFO_Buf->count == LIFO_Buf->length)
			return LIFO_Full;

	// add the item then increment the head and the count
	*(LIFO_Buf->head) = item;
	LIFO_Buf->head++;
	LIFO_Buf->count++;

	return LIFO_No_Error;
}

LIFO_Status LIFO_Get_item(LIFO_Buf_t* LIFO_Buf, unsigned int* item)
{
	//check if the LIFO is valid
	if (!LIFO_Buf->base || !LIFO_Buf->head)
			return LIFO_Null;

	//check if the LIFO is not empty
	if (LIFO_Buf->count == 0)
			return LIFO_Empty;

	//decrement the head then get the item and decrement the count
	LIFO_Buf->head--;
	 *item = *(LIFO_Buf->head);
	LIFO_Buf->count--;

	return LIFO_No_Error;
}

LIFO_Status LIFO_Init(LIFO_Buf_t* LIFO_Buf, unsigned int buffer,unsigned int length)
{
	//check if the Buffer used is valid
	if (buffer == NULL)
		return LIFO_Null;

	//assign the length,count,base and head location at the top of the buffer
	LIFO_Buf->length = length;
	LIFO_Buf->count = 0;
	LIFO_Buf->base = buffer;
	LIFO_Buf->head = buffer;

	return LIFO_No_Error;
}
