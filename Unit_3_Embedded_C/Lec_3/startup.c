
#include "Platform_Types.h"

#define Stack_pointer_start   0x20001000

extern int main(void);

void Reset_handler (void){
	main();
}

void NMI_handler (void){
	Reset_handler();
}

void Hard_fault_handler (void){
	Reset_handler();
}

void MMF_handler (void){
	Reset_handler();
}

void Bus_Fault_handler (void){
	Reset_handler();
}

void Usage_Fault_handler (void){
	Reset_handler();
}

void Reserved1 (void){
	Reset_handler();
}

uint32 vectors[] __attribute__((section(".vectors"))) = {
	Stack_pointer_start,
	(uint32) &Reset_handler,
	(uint32) &NMI_handler,
	(uint32) &Hard_fault_handler,
	(uint32) &MMF_handler,
	(uint32) &Bus_Fault_handler,
	(uint32) &Usage_Fault_handler,
	(uint32) &Reserved1
};