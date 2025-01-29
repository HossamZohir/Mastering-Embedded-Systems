
#ifndef DC_H_
#define DC_H_

#include "state.h"

// define states
enum{
	DC_idle,
	DC_busy
}DC_state_id;

//declare states functions
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();

//state pointer to function
extern void (*DC_state)();

#endif /* DC_H_ */
