/*
 * lifo.c
 *
 *  Created on: Nov 29, 2024
 *      Author: Hossam
 */

#include "lifo.h"

//=================================================================================================
LIFO_Status_t LIFO_Init(LIFO_Buf_t* LIFO_Buf, LIFO_element_type* buffer, LIFO_element_type length)
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

//=================================================================================================
LIFO_Status_t LIFO_Add_item(LIFO_Buf_t* LIFO_Buf, LIFO_element_type* item)
{
	// check if the LIFO is valid
	if (!LIFO_Buf->base || !LIFO_Buf->head)
		return LIFO_Null;

	// check if the LIFO is not full
	if (LIFO_Buf->count == LIFO_Buf->length)
		return LIFO_Full;

	// add the item then increment the head and the count
	*(LIFO_Buf->head) = *(item);
	LIFO_Buf->head++;
	LIFO_Buf->count++;

	return LIFO_No_Error;
}

//=================================================================================================
LIFO_Status_t LIFO_Get_item(LIFO_Buf_t* LIFO_Buf, LIFO_element_type* item)
{
	//check if the LIFO is valid
	if (!LIFO_Buf->base || !LIFO_Buf->head)
		return LIFO_Null;

	// check if the LIFO is not empty
	if (LIFO_Buf->count == 0)
		return LIFO_Empty;

	// Decrement the head then get the item and decrement the count
	LIFO_Buf->head--;
	*item = *(LIFO_Buf->head);
	LIFO_Buf->count--;

	return LIFO_No_Error;
}

//=================================================================================================
LIFO_Status_t LIFO_is_full(LIFO_Buf_t* LIFO_Buf)
{
	// check if the LIFO is valid
	if (!LIFO_Buf->base || !LIFO_Buf->head)
		return LIFO_Null;

	// check if the LIFO is not full
	if (LIFO_Buf->count == LIFO_Buf->length)
		return LIFO_Full;


	return LIFO_No_Error;
}

//=================================================================================================
void LIFO_Print(LIFO_Buf_t* LIFO_Buf)
{
	// Check if the LIFO is valid
	if (!LIFO_Buf->base || !LIFO_Buf->head)
	{
		printf("==== LIFO is Null ====\n");
		return;
	}

	// Check if the LIFO is empty
	if (LIFO_Buf->count == 0)
	{
		printf("==== LIFO is Empty ====\n");
		return;
	}

	// Print the buffer if valid and not empty
	LIFO_element_type* temp = LIFO_Buf->head - 1; // Start from the top of the stack
	printf("\n==== LIFO Print ====\n");
	for (int i = 0; i < LIFO_Buf->count; i++)
	{
		printf("\t %X \n", *temp);
		temp--; // Move to the previous element
	}
	printf("\n=======================================\n");
}
//=================================================================================================

