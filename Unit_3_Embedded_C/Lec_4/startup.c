#include "Platform_Types.h"

void Reset_handler (void);
extern uint32 main(void);

void Default_handler (void){
	Reset_handler();
}

void NMI_handler (void)__attribute__((weak,alias ("Default_handler")));;
void Hard_fault_handler (void)__attribute__((weak,alias ("Default_handler")));;

// reserve stack size
static uint32 stack_top[256];   // make the stack array to get the address of the array as the stack top address

void ( * const g_p_fn_Vectors[])()  __attribute__((section(".vectors"))) = {
	
	(void (*)()) ((uint32) stack_top + sizeof(stack_top)),
	&Reset_handler,
	&NMI_handler,
	&Hard_fault_handler,
	
};

// symbols of the start and end of memories sections "address"
extern uint32 _E_text ;
extern uint32 _S_data ;
extern uint32 _E_data ;
extern uint32 _S_bss ;
extern uint32 _E_bss ;

void Reset_handler (void){
	int i;
	// copy data section from rom to ram
	uint16 Data_size = *(uint8*) & _E_data - *(uint8*) & _S_data ;
	// make the src and des pointers make them char to copy byte by byte
	uint8* p_src = (uint8*) & _E_text;
	uint8* p_des = (uint8*) & _S_data;
	// loop to copy 
	for(i =0; i<Data_size;i++){
		*((uint8* )p_des++)=*((uint8* )p_src++);
	}
	
	//initialization of .bss section to zero
	uint8 bss_size = *(uint8*) & _E_bss - *(uint8*) & _S_bss ;
	// des to make it zero
	p_des=(uint8*) & _S_bss;
	// loop to make it zero
	for(i =0; i<bss_size;i++){
		*((uint8* )p_des++)= (uint8)0;
	}
	
	// jump to main
	main();
}

