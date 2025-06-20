/*
 * fifo.h
 *
 *  Created on: Dec 3, 2024
 *      Author: Hossam
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"

// This macro to overcome the bug of printf in eclipse ide "remove if not needed"
#define DPRINTF(...) {fflush(stdout); fflush(stdout);\
						printf(__VA_ARGS__);\
						fflush(stdout); fflush(stdout);}

// User Configuration=============================================
// student structure
typedef struct sinfo {
	char fname[50];
	char lname[50];
	int roll_num;
	float GPA;
	int cid[10];
} student_t;
//-----------------------------------

/*select the element type like  ( uint8_t, uint16_t, uint32_t,....) */
#define FIFO_element_type student_t
#define buffer_length 55
FIFO_element_type new_student [buffer_length];
//-----------------------------------

//create a static buffer 1 "example"


//------------------------------------
//create a static buffer 2 "example"
//#define buffer2_length 5
//FIFO_element_type buffer2[buffer2_length];
//------------------------------------
//==================================================================
// FIFO Data Types==================================================

typedef struct {
	uint32_t length;
	uint32_t count;
	FIFO_element_type* base;
	FIFO_element_type* head;
	FIFO_element_type* tail;
}FIFO_Buf_t;

FIFO_Buf_t students_queue;

typedef enum {
	FIFO_No_Error,
	FIFO_Full,
	FIFO_Empty,
	FIFO_Null
}FIFO_Status_t;
//====================================================================

//=================================================================================================
/**
 * @brief Initializes the FIFO buffer with the provided memory.
 *
 * @param FIFO_Buf Pointer to the FIFO buffer structure.
 * @param buffer Pointer to the memory allocated for the FIFO storage.
 * @param length The maximum number of elements the FIFO can hold.
 *
 * @return FIFO_Status_t
 *         - FIFO_No_Error: Initialization successful.
 *         - FIFO_Null: Provided buffer is NULL.
 *
 * @note The provided `buffer` must point to a valid memory area and should
 *       have space for at least `length` elements of type `FIFO_element_type`.
 */
FIFO_Status_t FIFO_Init(FIFO_Buf_t* FIFO_Buf, FIFO_element_type* buffer, uint32_t length);

//=================================================================================================
/**
 * @brief Adds an item to the FIFO buffer.
 *
 * @param FIFO_Buf Pointer to the FIFO buffer structure.
 * @param item Pointer to the item to be added to the FIFO.
 *
 * @return FIFO_Status_t
 *         - FIFO_No_Error: Enqueue successful.
 *         - FIFO_Null: FIFO is not initialized or invalid.
 *         - FIFO_Full: FIFO is full, and no new items can be added.
 *
 * @note The FIFO buffer must be initialized before calling this function.
 */
FIFO_Status_t FIFO_Enqueue(FIFO_Buf_t* FIFO_Buf, FIFO_element_type* item);

//=================================================================================================
/**
 * @brief Removes an item from the FIFO buffer.
 *
 * @param FIFO_Buf Pointer to the FIFO buffer structure.
 * @param item Pointer to a variable where the dequeued item will be stored.
 *
 * @return FIFO_Status_t
 *         - FIFO_No_Error: Dequeue successful.
 *         - FIFO_Null: FIFO is not initialized or invalid.
 *         - FIFO_Empty: FIFO is empty, and no items can be dequeued.
 *
 * @note The FIFO buffer must be initialized and non-empty before calling this function.
 */
FIFO_Status_t FIFO_Dequeue(FIFO_Buf_t* FIFO_Buf, FIFO_element_type* item);

//=================================================================================================
/**
 * @brief Checks if the FIFO buffer is full.
 *
 * @param FIFO_Buf Pointer to the FIFO buffer structure.
 *
 * @return FIFO_Status_t
 *         - FIFO_No_Error: FIFO is not full.
 *         - FIFO_Null: FIFO is not initialized or invalid.
 *         - FIFO_Full: FIFO is full.
 *
 * @note The FIFO buffer must be initialized before calling this function.
 */
FIFO_Status_t FIFO_is_full(FIFO_Buf_t* FIFO_Buf);

//=================================================================================================
/**
 * @brief Prints the current contents of the FIFO buffer.
 *
 * @param FIFO_Buf Pointer to the FIFO buffer structure.
 *
 * @return void
 *
 * @note The FIFO buffer must be initialized before calling this function.
 *       If the FIFO is empty, a message will be printed.
 *       If the FIFO is null or invalid, an error message will be printed.
 */
void FIFO_Print(FIFO_Buf_t* FIFO_Buf);
//=================================================================================================

void add_student_file();
// add student manually
void add_student_manually();
// find the student by roll number
void find_rn();
// find student with first name
void find_fn();
// find student with course id
void find_c();
// find total number of students
void tot_s();
// delete student by roll number
void del_s();
// update student by roll number
void up_s();
// show all information
void show_s();

#endif /* FIFO_H_ */
