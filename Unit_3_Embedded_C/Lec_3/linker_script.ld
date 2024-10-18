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
	}> flash                                      /* Place all of these in flash memory */
	
	.data :                                       /* Initialized data section */
	{
		*(.data)                                  /* Initialized variables */
	}> flash                                      /* Initialized data is loaded into flash*/
	
	.bss :                                        /* Uninitialized data section */
	{
		*(.bss)                                   /* Uninitialized variables */
	}> sram                                       /* Place uninitialized data in SRAM */
}
