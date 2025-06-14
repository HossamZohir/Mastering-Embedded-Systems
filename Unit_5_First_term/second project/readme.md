# Student Management System in C

A simple Student Management System implemented in C using a **FIFO circular buffer** for managing student records. The system allows adding, updating, deleting, searching, and displaying students, either manually or via a file.

---

## 🧠 Features

- Add a student manually or from a file
- Ensure **unique roll numbers**
- Search student by:
  - Roll number
  - First name
  - Course ID
- Update student record by roll number
- Delete student record by roll number
- Count total students
- Display all student records
- FIFO queue implementation with capacity control

---

## 📁 File Structure

Student-Management-System/
│
├── fifo.c # FIFO implementation (enqueue, dequeue, init, is_full, etc.)
├── fifo.h # FIFO header file
├── project_func.c # All project functionalities (add, search, update, delete, etc.)
├── project_func.h # Function prototypes and structure definitions
├── main.c # Main driver program with the menu system
├── students.txt # Optional input file to load students
└── README.md # This file