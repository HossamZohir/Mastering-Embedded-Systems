/*
 * DC.c
 *
 *  Created on: Jan 16, 2025
 *      Author: Hossam
 */
#include "DC.h"

int DC_speed=0;

//state pointer to function
void (*DC_state)();

void DC_init()
{
	printf("DC init\n");
}

void DC_motor(int s)
{
	DC_speed = s;
	DC_state = STATE(DC_idle);
	printf("DC..........speed %d .......> DC \n",DC_speed);

}


STATE_define(DC_idle)
{
	//state name
	DC_state_id= DC_idle;
	//state action
	printf("DC_idle state;  speed=%d\n",DC_speed);
}

STATE_define(DC_busy)
{
	//state name
	DC_state_id= DC_busy;
	//state action
	DC_speed=30;
	//MOTOR SPEED

	printf("DC_busy state;  speed=%d\n",DC_speed);
	DC_state = STATE(DC_idle);

}

