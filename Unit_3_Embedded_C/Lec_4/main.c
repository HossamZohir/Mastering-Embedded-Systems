#include "Platform_types.h"
#include "Bit_Math.h"

#define SYSCTL_RCGC2_R  		*(vuint32_t *)(0x400FE108)
#define GPIOF_DATA_R  			*(vuint32_t *)(0x400253FC)
#define GPIOF_DIR_R	  			*(vuint32_t *)(0x40025400)
#define GPIOF_DEN_R	  			*(vuint32_t *)(0x4002551C)

int main(void)
{	
	int i;
	// Initialize
	SET_BITS_REG(SYSCTL_RCGC2_R,0x00000020);
	for( i=0;i<200;i++);
	SET_BIT(GPIOF_DIR_R,3);
	SET_BIT(GPIOF_DEN_R,3);
	
	while(1)
	{
		int i;
		SET_BIT(GPIOF_DATA_R,3);
		for(i=0;i<20000;i++);
		CLR_BIT(GPIOF_DATA_R,3);
		for(i=0;i<20000;i++);
	}
	return 0 ;
}
