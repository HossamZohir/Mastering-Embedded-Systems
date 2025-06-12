/*
 * SYS.c
 *
 *  Created on: Feb 15, 2025
 *      Author: Hossam
 */

#include "SYS.h"

int P_Threshold = 20 ;       // system threshold 20 bar "pressure"
int LedTimer = 60000;
int alarm_triggered = 0;    // flag to avoid repeating LED cycle

//state pointer to function
void (*SYS_state)();

// states
STATE_define(SYS_waiting)
{
	//state name
	SYS_state_id= SYS_waiting;
	//state action
	//DPRINTF("System Waiting State\n");
	SYS_state = STATE(SYS_algorithm);
}

STATE_define(SYS_algorithm)
{
	//state name
	SYS_state_id= SYS_algorithm;
	
	//state action
	if(Pval>=P_Threshold)
	{
		if(!alarm_triggered)
		{
		//call the store function
		Store_Pressure_Value(Pval);
		//set the alarm
		Set_Alarm_actuator(0);
		// make the delay
		Delay(LedTimer);
		
		//reset the alarm
		Set_Alarm_actuator(1);
		
		alarm_triggered = 1;         // Prevent retriggering
        }
	}
	else
	{
		//reset the alarm
		Set_Alarm_actuator(1);
		//back to waiting state
		alarm_triggered = 0;    // Reset flag when pressure goes low
	}
	
	// back to waiting
	SYS_state = STATE(SYS_waiting);
}


