/*
 * main.c
 *
 *  Created on: Jun 13, 2025
 *      Author: Hossam
 */

#include "fifo.h"

int main() {

	FIFO_Init(&students_queue, new_student, buffer_length);

    int choice;
    DPRINTF("Welcome to the Student Management System\n\n");

    do {

        DPRINTF("1. Add Student Manually\n");
        DPRINTF("2. Add Student from File\n");
        DPRINTF("3. Find Student by Roll\n");
        DPRINTF("4. Find Student by First Name\n");
        DPRINTF("5. Find Student by Course ID\n");
        DPRINTF("6. Get Total Number of Students\n");
        DPRINTF("7. Delete Student by Roll\n");
        DPRINTF("8. Update Student by Roll\n");
        DPRINTF("9. Show All Students\n");
        DPRINTF("10. Exit\n");
        DPRINTF("Enter your choice number: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student_manually();
                break;
            case 2:
                add_student_file();
                break;
            case 3:
                find_rn();
                break;
            case 4:
                find_fn();
                break;
            case 5:
                find_c();
                break;
            case 6:
                tot_s();
                break;
            case 7:
                del_s();
                break;
            case 8:
                up_s();
                break;
            case 9:
                show_s();
                break;
            case 10:
                DPRINTF("Exiting...\n");
                break;
            default:
                DPRINTF("Invalid choice. Try again.\n");
                break;
        }

    } while (choice != 10);

    return 0;
}

