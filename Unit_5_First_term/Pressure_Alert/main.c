#include <stdint.h>
#include <stdio.h>


#include "driver.h"
#include "AL.h"
#include "PS.h"
#include "SYS.h"
#include "MEM.h"


int main (){
	// init all the drivers
	GPIO_INITIALIZATION();
	PS_init();

	// set states pointers for each block
	SYS_state = STATE(SYS_algorithm);
	AL_state = STATE(AL_waiting);
	MEM_state = STATE(MEM_waiting);


	while (1)
	{
			PS_state();
			SYS_state();
			AL_state();
			MEM_state();
	}

	return 0;
}
