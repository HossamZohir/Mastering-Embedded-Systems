/*
 * SYS.h
 *
 *  Created on: Feb 15, 2025
 *      Author: Hossam
 */

#ifndef DRIVER_SYS_H_
#define DRIVER_SYS_H_

#include "state.h"

extern int Pval ;


//define states
enum{

	SYS_waiting,
	SYS_algorithm

}SYS_state_id;


//declare states functions
STATE_define(SYS_waiting);
STATE_define(SYS_algorithm);

//state pointer to function
extern void (*SYS_state)();


#endif /* DRIVER_SYS_H_ */
