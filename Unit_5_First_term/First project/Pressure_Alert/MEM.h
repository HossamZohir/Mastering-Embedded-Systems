/*
 * MEM.h
 *
 *  Created on: Feb 15, 2025
 *      Author: Hossam
 */

#ifndef DRIVER_MEM_H_
#define DRIVER_MEM_H_

#include "state.h"
#include "time.h"

// Struct to store pressure and timestamp
typedef struct {
    int pressure;
    time_t timestamp;
} PressureData;

#define MAX_ENTRIES 100  // Maximum number of stored values
PressureData dataLog[MAX_ENTRIES];  // Array to store readings

void Store_Pressure_Value(int Pval);
void Print_Stored_Values();

//define states
enum{
	MEM_waiting,
	MEM_storing

}MEM_state_id;

//declare states functions
STATE_define(MEM_waiting);
STATE_define(MEM_storing);

//state pointer to function
extern void (*MEM_state)();

#endif /* DRIVER_MEM_H_ */
