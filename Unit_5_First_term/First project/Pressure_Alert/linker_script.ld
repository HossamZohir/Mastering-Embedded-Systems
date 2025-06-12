/* @ Hossam Zohir */

MEMORY
{
	flash(RX)    : ORIGIN = 0x08000000, LENGTH = 128k   /* Flash memory: Read/Execute, 128KB at 0x08000000 */
	sram(RWX)    : ORIGIN = 0x20000000, LENGTH = 20k    /* SRAM memory: Read/Write/Execute, 20KB at 0x20000000 */
}

SECTIONS
{
	.text :                                        /* Code and read-only data section */
	{
		*(.vectors*)                              /* Vector table goes in the .text section (typically first) */
		*(.text*)                                 /* Code (.text) section */
		*(.rodata)                                /* Read-only data section (.rodata) */
		_E_text = . ;
	
	}> flash                                      /* Place all of these in flash memory */
	
	.data :                                       /* Initialized data section */
	{
		_S_data = . ;
		*(.data)                                  /* Initialized variables */
		_E_data = . ;
	
	}> sram AT> flash                             /* Initialized data is loaded into flash then copy in ram at run time*/
	
	.bss :                                        /* Uninitialized data section */
	{
		_S_bss = . ;
		*(.bss*)                                  /* Uninitialized variables */
		. = ALIGN(4);
		_E_bss = . ;
		
		. = ALIGN(4);
		. = . +0x1000;
		_stack_top = . ;
		
	}> sram                                       /* Place uninitialized data in SRAM */
}
