# 🚨 Pressure Alert Embedded System

This repository contains a complete embedded C project simulating a **Pressure Monitoring and Alarm System**. The system is designed using modular architecture with state machines and demonstrates driver-level coding, state transitions, memory management, and simulation.

---

## 📋 Features

* Pressure sensing and threshold checking
* Alarm LED actuator control
* Memory module to store triggered pressure values
* State machine-based module architecture
* Simulation and delay handling
* Embedded C implementation with manual Makefile
* Startup and linker scripts included

---

## 📁 Project Structure

```plaintext
Pressure_Alert/
├── AL.c / AL.h           # Alarm LED Module
├── MEM.c / MEM.h         # Memory storage module
├── PS.c / PS.h           # Pressure Sensor simulation module
├── SYS.c / SYS.h         # System controller with main state machine
├── driver.c / driver.h   # HAL driver for GPIO abstraction
├── main.c                # Entry point, initializes and runs system
├── Platform_Types.h      # Data type abstraction
├── state.h               # Macros and typedefs for state machines
├── startup.c             # Startup file (assembly/C for bare-metal init)
├── linker_script.ld      # Linker configuration
├── makefile              # Manual makefile to build the project
├── map_file.map          # Generated map file for SW analysis
└── Pressure-Alert.elf    # Compiled output
```

---

## 🧠 System Overview

### 📂 Requirements Diagram

✔️ Done — defines pressure threshold & alarm triggering logic.

### 📊 System Analysis

* **Use Case Diagram** – shows interaction between user/system and sensors.
* **Activity Diagram** – outlines sensor reading → comparison → alert generation.
* **Sequence Diagram** – interaction between modules: PS → SYS → AL → MEM.

### 🧹 System Design

Each module is implemented as a **state machine**, with `.c` and `.h` files.

---

## 🗋 Module State Machines

Each `.c` and `.h` file has a corresponding **state machine diagram** in the report.

* `SYS.c`: Main controller — handles logic.
* `PS.c`: Alternates between `PS_waiting` and `PS_reading`.
* `AL.c`: Controls the LED alarm.
* `MEM.c`: Stores pressure values that trigger alarms.

---

## 🧪 Simulation Results

Simulation was run using \[your tool here], with delays and threshold pressure conditions validated:

* Alarm triggers for 60 seconds if pressure exceeds 20 bar.
* LED stays ON and does not blink due to proper delay logic.
* State transitions occur correctly.

---

## 🧰 Build Instructions

```bash
make
```

To clean the build:

```bash
make clean
```

---

## 📌 SW Analysis

Generated `.map` and `.elf.asm` files included:

* `map_file.map`: memory sections and symbol table.
* `Pressure-Alert.elf.asm`: disassembled binary for debugging and analysis.

---

## 📆 Report

📄 See `Pressure_Alert_Report.pdf` for:

* Diagrams
* State machine illustrations
* Simulation screenshots
* Software analysis tables

---

## 🔧 Tools Used

* STM32 GCC toolchain (or any ARM toolchain)
* Make
* Any embedded simulation or real hardware test (e.g., STM32CubeIDE / Keil)
* Draw\.io for diagrams

---

## 👤 Author

**Hossam Zohir**

---

## 📬 Contact

If you have questions, feel free to open an issue or reach out via [GitHub Discussions](https://github.com/HossamZohir/Mastering-Embedded-Systems/discussions).

