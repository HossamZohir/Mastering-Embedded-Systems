#include "Platform_Types.h"
#define Stack_pointer_start   0x20001000
extern uint32 main(void);
extern uint32 _stack_top ;
void Reset_handler (void);

void Default_handler (void){
	Reset_handler();
}

void NMI_handler (void)__attribute__((weak,alias ("Default_handler")));;
void Hard_fault_handler (void)__attribute__((weak,alias ("Default_handler")));;
void MMF_handler (void)__attribute__((weak,alias ("Default_handler")));;
void Bus_Fault_handler (void)__attribute__((weak,alias ("Default_handler")));;
void Usage_Fault_handler (void)__attribute__((weak,alias ("Default_handler")));;
void Reserved1 (void)__attribute__((weak,alias ("Default_handler")));;

uint32 vectors[] __attribute__((section(".vectors"))) = {
	
	(uint32) &_stack_top,
	(uint32) &Reset_handler,
	(uint32) &NMI_handler,
	(uint32) &Hard_fault_handler,
	(uint32) &MMF_handler,
	(uint32) &Bus_Fault_handler,
	(uint32) &Usage_Fault_handler,
	(uint32) &Reserved1
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

