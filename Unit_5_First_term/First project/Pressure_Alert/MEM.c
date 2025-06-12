/*
 * MEM.c
 *
 *  Created on: Feb 15, 2025
 *      Author: Hossam
 */

#include "MEM.h"

int currentIndex = 0;  // Tracks stored entries

// Function to store pressure and timestamp
void Store_Pressure_Value(int Pval) {
   /* if (currentIndex < MAX_ENTRIES) {
        dataLog[currentIndex].pressure = Pval;
        dataLog[currentIndex].timestamp = time(NULL);
        currentIndex++;
    }*/
}

// Function to print stored values
void Print_Stored_Values() {
	int i;
    for (i = 0; i < currentIndex; i++) {
        //printf("Pressure: %d, Time: %s", dataLog[i].pressure, ctime(&dataLog[i].timestamp));
    }
}


//state pointer to function
void (*MEM_state)();


STATE_define(MEM_waiting)
{
	//state name
	MEM_state_id= MEM_waiting;
	//state action
	//DPRINTF("Memory Waiting State\n");
}

STATE_define(MEM_storing)
{
	//state name
	MEM_state_id= MEM_storing;
	//state action
	//DPRINTF("Memory Storing State\n");

	//Store_Pressure_Value(Pval);
	Print_Stored_Values();

}
