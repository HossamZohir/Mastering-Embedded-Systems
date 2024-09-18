.globl reset    

reset:
			ldr sp,  = stack_top     @init stack pointer
			bl		main
	
stop: 		b stop                @ as there is no end point in main no while(1)
	
