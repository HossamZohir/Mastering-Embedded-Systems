/*
 * lifo.h
 *
 *  Created on: Nov 29, 2024
 *      Author: Hossam
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdint.h"

// User Configuration=============================================

/*select the element type like  ( uint8_t, uint16_t, uint32_t,....) */
#define LIFO_element_type uint32_t
//-----------------------------------
//create a static buffer 1 "example"
#define buffer1_length 5
LIFO_element_type buffer1[buffer1_length];
//------------------------------------

//create a static buffer 2 "example"
#define buffer2_length 5
LIFO_element_type buffer2[buffer2_length];
//------------------------------------

//==================================================================
// LIFO Data Types==================================================
typedef struct {
	LIFO_element_type length;
	LIFO_element_type count;
	LIFO_element_type* base;
	LIFO_element_type* head;
}LIFO_Buf_t;

typedef enum {
	LIFO_No_Error,
	LIFO_Full,
	LIFO_Empty,
	LIFO_Null
}LIFO_Status_t;


/***************************    APIs   *****************************************/
/**
 * @brief Initialize the LIFO buffer.
 *
 * This function initializes the LIFO buffer by setting its base, head, length, and count.
 *
 * @param LIFO_Buf Pointer to the LIFO buffer structure.
 * @param buffer   Pointer to the buffer array.
 * @param length   Maximum number of elements the LIFO can hold.
 *
 * @return LIFO_No_Error if initialization is successful.
 * @return LIFO_Null if the buffer is invalid (NULL).
 *
 * @note The buffer array must be valid (non-NULL) before calling this function.
 */

LIFO_Status_t LIFO_Init(LIFO_Buf_t* LIFO_Buf, LIFO_element_type* buffer , LIFO_element_type length);

//=================================================================================================
/**
 * @brief Add an item to the LIFO buffer.
 *
 * This function adds a new item to the LIFO buffer, updating the head pointer and count.
 *
 * @param LIFO_Buf Pointer to the LIFO buffer structure.
 * @param item     Pointer to the item to be added.
 *
 * @return LIFO_No_Error if the item is added successfully.
 * @return LIFO_Null if the LIFO buffer or its members are invalid (NULL).
 * @return LIFO_Full if the LIFO buffer is full.
 *
 * @note The LIFO buffer must be valid and not full before calling this function.
 */

LIFO_Status_t LIFO_Add_item(LIFO_Buf_t* LIFO_Buf, LIFO_element_type* item);

//=================================================================================================
/**
 * @brief Retrieve an item from the LIFO buffer.
 *
 * This function removes the most recently added item from the LIFO buffer and returns it.
 *
 * @param LIFO_Buf Pointer to the LIFO buffer structure.
 * @param item     Pointer to store the retrieved item.
 *
 * @return LIFO_No_Error if the item is retrieved successfully.
 * @return LIFO_Null if the LIFO buffer or its members are invalid (NULL).
 * @return LIFO_Empty if the LIFO buffer is empty.
 *
 * @note The LIFO buffer must be valid and not empty before calling this function.
 */

LIFO_Status_t LIFO_Get_item(LIFO_Buf_t* LIFO_Buf, LIFO_element_type* item);

//=================================================================================================
/**
 * @brief Check if the LIFO buffer is full.
 *
 * This function checks whether the LIFO buffer has reached its maximum capacity.
 *
 * @param LIFO_Buf Pointer to the LIFO buffer structure.
 *
 * @return LIFO_No_Error if the LIFO buffer is not full.
 * @return LIFO_Null if the LIFO buffer or its members are invalid (NULL).
 * @return LIFO_Full if the LIFO buffer is full.
 *
 * @note The LIFO buffer must be valid before calling this function.
 */

LIFO_Status_t LIFO_is_full(LIFO_Buf_t* LIFO_Buf);

//=================================================================================================
/**
 * @brief Print the contents of the LIFO buffer.
 *
 * This function prints the contents of the LIFO buffer from top to bottom.
 *
 * @param LIFO_Buf Pointer to the LIFO buffer structure.
 *
 * @note If the LIFO buffer is invalid or empty, a corresponding message is printed.
 * @note The function assumes the buffer contains hexadecimal values for printing.
 */
void LIFO_Print(LIFO_Buf_t* LIFO_Buf);

//=================================================================================================

#endif /* LIFO_H_ */
