/*
 * US.c
 *
 *  Created on: Jan 16, 2025
 *      Author: Hossam
 */
#include "US.h"

int US_speed=0;
int US_distance=0;
int US_threshold=50;

//state pointer to function
void (*US_state)();

// Function prototypes
void US_init()
{
	printf("US init\n");
}


STATE_define(US_busy)
{
	//state name
	US_state_id= US_busy;


	//event check
	US_distance = US_Get_distance_random(45,55,1);

	printf("US_waiting state; distance=%d \n",US_distance);
	US_set_distance(US_distance);
	US_state = STATE(US_busy);
}


// Generate random number in range [l, r]
// Generate distance
int US_Get_distance_random(int l, int r, int count) {
    int result = 0;
    for (int i = 0; i < count; i++) {
        result = (rand() % (r - l + 1)) + l;
    }
    return result;
}
