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

// This macro to overcome the bug of printf in eclipse ide "remove if not needed"
#define DPRINTF(...) {fflush(stdout); fflush(stdout);\
						printf(__VA_ARGS__);\
						fflush(stdout); fflush(stdout);}

//automatic state function generated

#define STATE_define(_stateFunc_) 		void ST_##_stateFunc_()
#define STATE(_stateFunc_) 				ST_##_stateFunc_


// states connections "mapping"
//int getPressureVal();
//void Set_Alarm_actuator(int i);
//void Store_Pressure_Value(int PVal);


#endif /* STATE_H_ */
