/*
 * main.c
 *
 *  Created on: Jan 16, 2025
 *      Author: Hossam
 */

#include "CA.h"
#include "US.h"
#include "DC.h"

void setup()
{
	// init all the drivers
	// init IRQ
	// init HAL drivers
	// init block
	US_init();
	DC_init();

	// set states pointers for each block
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);


}

void main()
{
	volatile int i;
	setup();
	while(1)
	{
		//call the state for each block
		US_state();
		CA_state();
		DC_state();

		for(i=0;i<=20000;i++);

	}
}
