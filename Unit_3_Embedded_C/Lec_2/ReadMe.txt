
*Lab 1: Baremetal UART Communication*

Overview
This project demonstrates a baremetal software setup for UART communication. The software sends the message:
```
learn-in-depth:<your_Name>
```
over UART. This project is built entirely from scratch without using an IDE, including custom startup code, linker script, and Makefile. The program is run using **QEMU**, an open-source machine emulator, specifically emulating the **ARM926EJ VersatilePB**.

Project Structure
```
├── src/
│   ├── app.c           # Main application file
│   ├── uart.c           # UART initialization and communication functions
│   ├── startup.s        # Startup assembly code
│   └── Makefile         # Makefile to build the project
├── include/
│   ├── uart.h           # UART function prototypes
│   └── linker.ld        # Linker script
└── README.md            # Project documentation
```

Files Description

1. src/app.c: Contains the main function to initialize UART and send the message.
2. src/uart.c & include/uart.h: Defines the functions for UART initialization, configuration, and data transmission.
3. src/startup.s: Provides the low-level initialization, setting up the stack pointer, and calling the main function.
4. include/linker.ld: The linker script defines the memory layout for the ARM926EJ, specifying sections like `.text`, `.data`, `.bss`, and `.rodata`.
5. src/Makefile: Automates the process of compiling and linking the project.

Prerequisites

- ARM GCC Compiler: Ensure that the ARM GCC toolchain is installed (`arm-none-eabi-gcc`, `arm-none-eabi-objcopy`, etc.).
- QEMU: Install QEMU to emulate the ARM926EJ VersatilePB hardware and run the compiled program.

How to Build and Run

Step 1: Build the Project
Run the following command to compile and link the project:
```bash
make
```

Step 2: Run Using QEMU
To run the compiled binary on QEMU:
```bash
qemu-system-arm -M versatilepb -nographic -kernel build/output.bin
```
The `-nographic` flag enables UART output on the console, allowing you to see the transmitted message.

Step 3: Clean the Build
To remove all build files, use:
```bash
make clean
```

Code Explanation

UART Configuration
The UART is configured to communicate with a standard baud rate, data frame, and no parity. This allows the ARM926EJ to send the string `"learn-in-depth:<your_Name>"`.

Memory Layout
The memory layout is defined in `linker.ld`. The key sections include:
- .text: Contains the application code.
- .data: Contains initialized data.
- .bss: Contains uninitialized data.
- .rodata: Contains read-only data, such as string literals.

Example Output
Upon running the program on QEMU, the following message will be displayed in the terminal:
```
learn-in-depth:<your_Name>
```

Additional Notes
- Adjust UART pin configurations in the source code based on the hardware emulation settings.
- Modify the linker script if using different memory constraints in the ARM926EJ VersatilePB.

License
This project is for educational purposes and can be freely modified.

---
