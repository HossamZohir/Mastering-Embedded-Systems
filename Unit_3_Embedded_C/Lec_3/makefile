# @Copyrights Hossam Zohir

CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -mthumb  -gdwarf-2
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
Project_name = learn-in-depth-cortex-m3

all:$(Project_name).bin 
	@echo "==== Build is Done ===="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $<  -o $@
	
%.o: %.c
	$(CC)gcc.exe $(INCS) $(CFLAGS)  -c  $<  -o $@
	
$(Project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -Map=map_file.map -o  $@ 
	
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O  binary $< $@
	
clean_all:
	rm -rf *.o *~
	@echo "==== Clean all Done ===="
	
clean:
	rm -rf *.elf *.bin
	@echo "==== Clean Done ===="