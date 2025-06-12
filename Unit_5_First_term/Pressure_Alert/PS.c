/*
 * PS.c
 *
 *  Created on: Feb 15, 2025
 *      Author: Hossam
 */
#include "PS.h"

int Pval = 0;
int ReadTimer = 5000;

//state pointer to function
void (*PS_state)();

void PS_init()
{
		//state action
		// initialization of the sensor
		PS_state = STATE(PS_waiting);
}


// Defining states
STATE_define(PS_waiting)
{
	//state name
	PS_state_id= PS_waiting;
	
	//state action
	Delay(ReadTimer);   // wait reading time
	
	PS_state = STATE(PS_reading); // return to reading
}


STATE_define(PS_reading)
{
		//state name
		PS_state_id= PS_reading;
		
		//state action
		Pval = getPressureVal();  // get the pressure value

		PS_state = STATE(PS_waiting);  // go to waiting
}




