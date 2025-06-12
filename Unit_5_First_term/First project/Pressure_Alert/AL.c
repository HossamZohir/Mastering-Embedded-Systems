/*
 * AL.c
 *
 *  Created on: Feb 15, 2025
 *      Author: Hossam
 */

#include "AL.h"


//state pointer to function
void (*AL_state)();


STATE_define(AL_waiting)
{
	//state name
	AL_state_id= AL_waiting;
	//state action
	//DPRINTF("Alarm LED Waiting State\n");
	//reset the actuator
	//Set_Alarm_actuator(1); 
}

STATE_define(AL_working)
{
	//state name
	AL_state_id= AL_working;
	//state action
	//DPRINTF("Alarm LED Working State\n");
	//set the alarm
	//Set_Alarm_actuator(1);
	//make the delay
	//Delay(LedTimer);
}


