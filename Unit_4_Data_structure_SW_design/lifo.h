/*
 * lifo.h
 *
 *  Created on: Nov 29, 2024
 *      Author: Hossam
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdlib.h"

/***************************  type definitions  ***********************************/

typedef struct {
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int* head;
}LIFO_Buf_t;

typedef enum {
	LIFO_No_Error,
	LIFO_Full,
	LIFO_Empty,
	LIFO_Null
}LIFO_Status;



/***************************    APIs   *****************************************/

/******************************************************************************
 * @brief  Adds an item to the LIFO (Last In, First Out) buffer.
 *
 * This function pushes a new item onto the LIFO buffer, storing it at the
 * current `head` position and updating the buffer's `head` pointer and `count`.
 * It ensures the buffer is valid and not full before adding the item.
 *
 * @param[in,out] LIFO_Buf   Pointer to the LIFO buffer structure.
 * @param[in]     item       The item to be added to the LIFO buffer.
 *
 * @return LIFO_Status
 *         - LIFO_No_Error: Item successfully added to the buffer.
 *         - LIFO_Null: Error, invalid or uninitialized LIFO buffer.
 *         - LIFO_Full: Error, the LIFO buffer is full.
 *
 * @note
 *  - The LIFO buffer must be properly initialized using `LIFO_Init` before
 *    calling this function.
 *  - The `item` to be added should fit within the data type used by the LIFO buffer.
 *  - If the buffer is full, no new item will be added, and the function will
 *    return `LIFO_Full`.
 *
 * Usage Example:
 * @code
 * LIFO_Buf_t myLIFO;
 * unsigned int myBuffer[10];
 *
 * LIFO_Init(&myLIFO, myBuffer, 10);
 *
 * if (LIFO_Add_item(&myLIFO, 5) == LIFO_No_Error) {
 *     // Successfully added item to the LIFO buffer
 *     printf("Item added to the buffer.\n");
 * }
 * @endcode
 ******************************************************************************/
LIFO_Status LIFO_Add_item(LIFO_Buf_t* LIFO_Buf, unsigned int item);


/******************************************************************************
 * @brief  Retrieves the last item from the LIFO (Last In, First Out) buffer.
 *
 * This function removes and retrieves the most recently added item from the LIFO
 * buffer. It ensures the buffer is valid and not empty before performing the
 * operation. The `head` pointer is decremented to "pop" the item, and the count
 * is adjusted accordingly.
 *
 * @param[in,out] LIFO_Buf   Pointer to the LIFO buffer structure.
 * @param[out]    item       Pointer to store the retrieved item.
 *
 * @return LIFO_Status
 *         - LIFO_No_Error: Item successfully retrieved.
 *         - LIFO_Null: Error, invalid or uninitialized LIFO buffer.
 *         - LIFO_Empty: Error, the LIFO buffer is empty.
 *
 * @note
 *  - Ensure the LIFO buffer is properly initialized using `LIFO_Init` before
 *    calling this function.
 *  - The `item` pointer must not be NULL; otherwise, the retrieved value cannot
 *    be stored.
 *  - External modification of the buffer during operation may lead to undefined
 *    behavior.
 *
 * Usage Example:
 * @code
 * LIFO_Buf_t myLIFO;
 * unsigned int myBuffer[10];
 * unsigned int retrievedItem;
 *
 * LIFO_Init(&myLIFO, myBuffer, 10);
 * LIFO_Push(&myLIFO, 5);
 *
 * if (LIFO_Get_item(&myLIFO, &retrievedItem) == LIFO_No_Error) {
 *     // Successfully retrieved item from the LIFO
 *     printf("Retrieved item: %d\n", retrievedItem);
 * }
 * @endcode
 ******************************************************************************/
LIFO_Status LIFO_Get_item(LIFO_Buf_t* LIFO_Buf, unsigned int* item);


/******************************************************************************
 * @brief  Initializes a LIFO (Last In, First Out) buffer.
 *
 * This function sets up a LIFO buffer structure by initializing its base
 * pointer, head pointer, buffer length, and element count. It ensures the
 * buffer is ready for subsequent LIFO operations such as pushing and popping
 * data in a stack-like manner.
 *
 * @param[in,out] LIFO_Buf   Pointer to the LIFO buffer structure to initialize.
 * @param[in]     buffer     Base address of the pre-allocated memory buffer.
 * @param[in]     length     Number of elements the buffer can hold.
 *
 * @return LIFO_Status
 *         - LIFO_No_Error: Initialization successful.
 *         - LIFO_Null: Error, provided buffer is NULL.
 *
 * @note
 *  - The `buffer` must point to a valid, pre-allocated memory area.
 *  - The `length` parameter defines the capacity of the LIFO buffer.
 *  - This function does not validate whether the provided memory matches the
 *    specified length. Ensure that `length` is accurate to avoid memory issues.
 *  - The buffer memory should remain unmodified externally while the LIFO
 *    structure is in use to avoid data corruption.
 *
 * Usage Example:
 * @code
 * #define BUFFER_SIZE 10
 * unsigned int myBuffer[BUFFER_SIZE];
 * LIFO_Buf_t myLIFO;
 *
 * if (LIFO_Init(&myLIFO, myBuffer, BUFFER_SIZE) == LIFO_No_Error) {
 *     // Successfully initialized. LIFO is ready to use.
 *     LIFO_Push(&myLIFO, 5); // Example operation
 * }
 * @endcode
 ******************************************************************************/
LIFO_Status LIFO_Init(LIFO_Buf_t* LIFO_Buf,unsigned int buffer ,unsigned int length);

#endif /* LIFO_H_ */
