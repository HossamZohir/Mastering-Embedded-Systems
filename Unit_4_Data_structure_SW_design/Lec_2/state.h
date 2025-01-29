/*
 * state.h
 *
 *  Created on: Jan 16, 2025
 *      Author: Hossam
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"

//automatic state function generated

#define STATE_define(_stateFunc_) 		void ST_##_stateFunc_()
#define STATE(_stateFunc_) 				ST_##_stateFunc_


// states connections "mapping"
void US_set_distance(int d);
void DC_motor(int s);


#endif /* STATE_H_ */
