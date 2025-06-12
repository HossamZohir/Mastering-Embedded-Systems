/*
 * AL.h
 *
 *  Created on: Feb 15, 2025
 *      Author: Hossam
 */

#ifndef DRIVER_AL_H_
#define DRIVER_AL_H_

#include "state.h"

//define states
enum{
	AL_waiting,
	AL_working

}AL_state_id;

//declare states functions
STATE_define(AL_waiting);
STATE_define(AL_working);

//state pointer to function
extern void (*AL_state)();

#endif /* DRIVER_AL_H_ */
