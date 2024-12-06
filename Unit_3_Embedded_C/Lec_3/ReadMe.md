Lab 2: Baremetal Software on ARM Cortex-M3 Microcontroller

Overview:

In this lab, we will learn to write baremetal software for the ARM Cortex-M3 32-bit microcontroller using the STM32F103C8T6 chip. The goal is to toggle an LED connected to GPIO port C13.

Requirements:

- STM32F103C8T6 microcontroller
- LED connected to GPIO port C13
- Proteus simulation software to visualize the results

GPIO Toggling:

To implement GPIO toggling on the STM32F103C8T6, we need to work with two peripherals:
1. RCC (Reset and Clock Control): This is necessary because the GPIO clock is disabled by default.
2. GPIOx (General Purpose Input/Output): This allows us to control the state of the GPIO pins.

Steps to Toggle LED:

1. Enable the clock for GPIO port C by configuring the RCC.
2. Set GPIO port C13 as an output pin.
3. Implement a loop to toggle the LED state.

Development Environment:

The Makefile, startup code, and linker script were created from scratch without using an IDE, allowing for greater control over the build process. This setup ensures that the project can be built and flashed to the microcontroller efficiently.

Simulation:

The results of the implementation were simulated using Proteus, demonstrating the successful toggling of the LED on GPIO port C13.

Conclusion:

This lab illustrates the basics of controlling GPIO pins on an STM32 microcontroller and highlights the importance of peripheral management, particularly clock control, in baremetal programming.

---

