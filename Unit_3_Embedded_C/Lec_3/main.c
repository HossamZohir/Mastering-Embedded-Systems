#include "Platform_types.h"
#include "Bit_Math.h"

#define RCC_BASE  			0x40021000
#define GPIOA_BASE  		0x40010800

#define RCC_APB2ENR  		*(vuint32_t *)(RCC_BASE + 0X18)
#define GPIOA_CRH  			*(vuint32_t *)(GPIOA_BASE + 0X04)
#define GPIOA_ODR	  		*(vuint32_t *)(GPIOA_BASE + 0X0C)

uint8 arr1[5]={1,3,6,5,7};
uint8 const arr2[5]={15,37,6,95,57};

int main(void)
{
	// Initialize
	SET_BIT(RCC_APB2ENR,2);
	CLR_REG(GPIOA_CRH);
	SET_BITS_REG(GPIOA_CRH,0x00200000);

	while(1)
	{
		int i;
		SET_BIT(GPIOA_ODR,13);
		for(i=0;i<5000;i++);
		CLR_BIT(GPIOA_ODR,13);
		for(i=0;i<5000;i++);
	}
	
}
