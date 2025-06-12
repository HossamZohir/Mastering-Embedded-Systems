/*
 * PS.h
 *
 *  Created on: Feb 15, 2025
 *      Author: Hossam
 */

#ifndef PS_H_
#define PS_H_

#include "state.h"

//define states
enum{

	PS_reading,
	PS_waiting

}PS_state_id;

//state pointer to function
extern void (*PS_state)();

//initialization function
void PS_init();

//declare states functions
STATE_define(PS_reading);
STATE_define(PS_waiting);


#endif /* DRIVER_PS_H_ */
