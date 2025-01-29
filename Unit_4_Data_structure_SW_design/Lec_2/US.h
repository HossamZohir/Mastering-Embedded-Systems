/*
 * US.h
 *
 *  Created on: Jan 16, 2025
 *      Author: Hossam
 */

#ifndef US_H_
#define US_H_

#include "state.h"

// define states
enum{
	US_busy
}US_state_id;

//declare states functions
STATE_define(US_busy);

void US_init();


//state pointer to function
extern void (*US_state)();

#endif /* US_H_ */
