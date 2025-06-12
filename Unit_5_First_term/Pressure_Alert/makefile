# @Copyrights Hossam Zohir

# Toolchain prefix for ARM GCC
CC=arm-none-eabi-

# Compiler flags:
# -mcpu=cortex-m3 : target ARM Cortex-M3 CPU
# -mthumb         : generate Thumb instruction set
# -gdwarf-2       : generate DWARF-2 debug info
CFLAGS= -mcpu=cortex-m3 -mthumb  -gdwarf-2

# Include directories (currently only current directory)
INCS=-I .

# Libraries to link with 
LIBS=

# Source files: find all .c files in current directory
SRC = $(wildcard *.c)

# Object files from C sources
OBJ = $(SRC:.c=.o)

# Assembly source files: find all .s files
AS = $(wildcard *.s)

# Object files from assembly sources
ASOBJ = $(AS:.s=.o)

# Name of the final project binary (without extension)
Project_name = Pressure-Alert

# Default target: build the final binary file
all: $(Project_name).bin 
	@echo "==== Build is Done ===="

# Rule to compile assembly files to object files
%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

# Rule to compile C source files to object files
%.o: %.c
	$(CC)gcc.exe $(INCS) $(CFLAGS) -c $< -o $@

# Link object files into an ELF executable using linker script
$(Project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -Map=map_file.map -o $@ 

# Convert ELF file into a raw binary file
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

# Clean object files and temporary files
clean_all:
	rm -rf *.o *~
	@echo "==== Clean all Done ===="

# Clean only final output files
clean:
	rm -rf *.elf *.bin
	@echo "==== Clean Done ===="
