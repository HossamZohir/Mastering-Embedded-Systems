// @Hossam Zohir

#include "Platform_Types.h"  // Include platform-specific type definitions

// Define stack pointer initial value (in SRAM)
#define Stack_pointer_start   0x20001000

// Forward declarations of main and the top of the stack from the linker script
extern uint32 main(void);
extern uint32 _stack_top;

// Forward declaration of the Reset handler
void Reset_handler (void);

// Default handler: used for unimplemented or weakly defined interrupts
void Default_handler (void){
	Reset_handler();  // In case of unhandled interrupt, just restart the system
}

// Define weak aliases for exception handlers so they default to Default_handler
void NMI_handler (void) __attribute__((weak, alias("Default_handler")));
void Hard_fault_handler (void) __attribute__((weak, alias("Default_handler")));
void MMF_handler (void) __attribute__((weak, alias("Default_handler")));
void Bus_Fault_handler (void) __attribute__((weak, alias("Default_handler")));
void Usage_Fault_handler (void) __attribute__((weak, alias("Default_handler")));
void Reserved1 (void) __attribute__((weak, alias("Default_handler")));

// Interrupt vector table placed in a specific memory section ".vectors"
uint32 vectors[] __attribute__((section(".vectors"))) = {
	(uint32) &_stack_top,         // Initial stack pointer
	(uint32) &Reset_handler,      // Reset handler
	(uint32) &NMI_handler,        // NMI handler
	(uint32) &Hard_fault_handler, // Hard fault handler
	(uint32) &MMF_handler,        // Memory management fault handler
	(uint32) &Bus_Fault_handler,  // Bus fault handler
	(uint32) &Usage_Fault_handler,// Usage fault handler
	(uint32) &Reserved1           // Reserved
};

// Symbols representing memory section boundaries, from linker script
extern uint32 _E_text;   // End of text (Flash)
extern uint32 _S_data;   // Start of data section in RAM
extern uint32 _E_data;   // End of data section in RAM
extern uint32 _S_bss;    // Start of BSS section
extern uint32 _E_bss;    // End of BSS section

// Reset handler: executes after a reset
void Reset_handler (void){
	int i;

	// Copy initialized data from Flash to RAM
	uint16 Data_size = *(uint8*) &_E_data - *(uint8*) &_S_data;
	uint8* p_src = (uint8*) &_E_text;   // Source = end of text section (Flash)
	uint8* p_des = (uint8*) &_S_data;   // Destination = start of data (RAM)
	for (i = 0; i < Data_size; i++) {
		*((uint8*) p_des++) = *((uint8*) p_src++);
	}
	
	// Zero initialize the .bss section in RAM
	uint8 bss_size = *(uint8*) &_E_bss - *(uint8*) &_S_bss;
	p_des = (uint8*) &_S_bss;
	for (i = 0; i < bss_size; i++) {
		*((uint8*) p_des++) = (uint8) 0;
	}

	// Call the main application
	main();
}
