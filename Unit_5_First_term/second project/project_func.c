/*
 * project_func.c
 *
 *  Created on: Jun 14, 2025
 *      Author: Hossam
 */

#include "fifo.h"

// APIs
// add student from external file
void add_student_file() {
    FILE* fp = fopen("students.txt", "r");
    if (!fp) {
        DPRINTF("Error: Could not open file.\n");
        return;
    }

    while (!feof(fp)) {
        student_t temp;
        int read_count = fscanf(fp, "%s %s %d %f %d %d %d %d %d",
                                temp.fname, temp.lname, &temp.roll_num, &temp.GPA,
                                &temp.cid[0], &temp.cid[1], &temp.cid[2], &temp.cid[3], &temp.cid[4]);

        if (read_count != 9) {
            DPRINTF("Invalid or incomplete line in file. Skipping...\n");
            // Skip rest of the line if malformed
            while (fgetc(fp) != '\n' && !feof(fp));
            continue;
        }

        // Fill unused course slots with -1
        for (int i = 5; i < 10; i++)
            temp.cid[i] = -1;

        // Check for duplicate roll number
        int duplicate = 0;
        student_t* check = students_queue.base;
        for (int i = 0; i < students_queue.count; i++) {
            if (check->roll_num == temp.roll_num) {
                duplicate = 1;
                break;
            }
            check++;
        }

        if (duplicate) {
            DPRINTF("Duplicate roll number %d found. Skipping student.\n", temp.roll_num);
            continue;
        }

        // Check if FIFO is full
        if (FIFO_is_full(&students_queue) == FIFO_Full) {
            DPRINTF("Queue full. Cannot add more students.\n");
            break;
        }

        FIFO_Enqueue(&students_queue, &temp);
        DPRINTF("Student %s %s added successfully.\n", temp.fname, temp.lname);
    }

    fclose(fp);
}


// add student manually
void add_student_manually()
{

	// check if fifo is full or not
	if (FIFO_is_full(&students_queue) == FIFO_Full) {
	        DPRINTF("Cannot add student. Queue is full.\n");
	        return;
	    }


	    DPRINTF("Enter First Name: ");
	    scanf("%s", new_student->fname);

	    DPRINTF("Enter Last Name: ");
	    scanf("%s", new_student->lname);

	    // Input roll number and check for uniqueness
	    int duplicate = 0;
	    DPRINTF("Enter Roll Number: ");
	    scanf("%d", &new_student->roll_num);

	    student_t* temp = students_queue.base;
	    for (int i = 0; i < students_queue.count; i++) {
	        if (temp->roll_num == new_student->roll_num) {
	            duplicate = 1;
	            break;
	        }
	        temp++;
	    }

	    if (duplicate) {
	        DPRINTF("Error: Student with Roll Number %d already exists.\n", new_student->roll_num);
	        return;
	    }

	    DPRINTF("Enter GPA: ");
	    scanf("%f", &new_student->GPA);

	    DPRINTF("Enter 5 Course IDs:\n");
	    for (int i = 0; i < 5; i++) {
	        DPRINTF("Course ID %d: ", i + 1);
	        scanf("%d", &new_student->cid[i]);
	    }

	    // Fill remaining courses with -1 (not used)
	    for (int i = 5; i < 10; i++) {
	        new_student->cid[i] = -1;
	    }

	    FIFO_Status_t status = FIFO_Enqueue(&students_queue, new_student);
	    switch (status) {
	            case FIFO_No_Error:
	                DPRINTF("Student added successfully. [Status: FIFO_No_Error]\n");
	                break;
	            case FIFO_Full:
	                DPRINTF("Failed to add student. [Status: FIFO_Full] - Queue is full.\n");
	                break;
	            case FIFO_Null:
	                DPRINTF("Failed to add student. [Status: FIFO_Null] - Invalid FIFO buffer.\n");
	                break;
	            default:
	                DPRINTF("Failed to add student. [Status: Unknown Error]\n");
	                break;
	        }

}

// find student with first name
void find_fn() {
    char name[50];
    int found = 0;

    DPRINTF("Enter First Name to search: ");
    scanf("%s", name);

    student_t* temp = students_queue.base;
    for (int i = 0; i < students_queue.count; i++) {
        if (strcmp(temp->fname, name) == 0) {
            DPRINTF("Student Found:\n");
            DPRINTF("Name: %s %s\n", temp->fname, temp->lname);
            DPRINTF("Roll Number: %d\n", temp->roll_num);
            DPRINTF("GPA: %.2f\n", temp->GPA);
            DPRINTF("Courses: ");
            for (int j = 0; j < 10; j++) {
                if (temp->cid[j] != -1)
                    DPRINTF("%d ", temp->cid[j]);
            }
            DPRINTF("\n\n");
            found = 1;
        }
        temp++;
    }

    if (!found)
        DPRINTF("No student found with First Name '%s'.\n", name);
}


// find the student by roll number
void find_rn() {
    int roll;
    int found = 0;
    DPRINTF("Enter Roll Number to search: ");
    scanf("%d", &roll);

    student_t* temp = students_queue.base;
    for (int i = 0; i < students_queue.count; i++) {
        if (temp->roll_num == roll) {
            DPRINTF("Student Found:\n");
            DPRINTF("Name: %s %s\n", temp->fname, temp->lname);
            DPRINTF("Roll Number: %d\n", temp->roll_num);
            DPRINTF("GPA: %.2f\n", temp->GPA);
            DPRINTF("Courses: ");
            for (int j = 0; j < 10; j++) {
                if (temp->cid[j] != -1)
                    DPRINTF("%d ", temp->cid[j]);
            }
            DPRINTF("\n");
            found = 1;
            break;
        }
        temp++;
    }

    if (!found)
        DPRINTF("Student with Roll Number %d not found.\n", roll);
}


// find student with course id
void find_c() {
    int course_id;
    int found = 0;

    DPRINTF("Enter Course ID to search: ");
    scanf("%d", &course_id);

    student_t* temp = students_queue.base;
    for (int i = 0; i < students_queue.count; i++) {
        for (int j = 0; j < 10; j++) {
            if (temp->cid[j] == course_id) {
                DPRINTF("Student Found:\n");
                DPRINTF("Name: %s %s\n", temp->fname, temp->lname);
                DPRINTF("Roll Number: %d\n", temp->roll_num);
                DPRINTF("GPA: %.2f\n", temp->GPA);
                DPRINTF("Courses: ");
                for (int k = 0; k < 10; k++) {
                    if (temp->cid[k] != -1)
                        DPRINTF("%d ", temp->cid[k]);
                }
                DPRINTF("\n\n");
                found = 1;
                break;
            }
        }
        temp++;
    }

    if (!found)
        DPRINTF("No students enrolled in course ID %d.\n", course_id);
}


// find total number of students
void tot_s()
{
	 DPRINTF("Total number of students: %d\n", students_queue.count);
}

// delete student by roll number
void del_s() {
    int roll;
    int found = 0;
    DPRINTF("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    student_t* temp = students_queue.base;

    for (int i = 0; i < students_queue.count; i++) {
        if (temp[i].roll_num == roll) {
            found = 1;
            // Shift students left
            for (int j = i; j < students_queue.count - 1; j++) {
                temp[j] = temp[j + 1];
            }
            students_queue.count--; // Reduce total count
            DPRINTF("Student with Roll Number %d deleted successfully.\n", roll);
            break;
        }
    }

    if (!found) {
        DPRINTF("Student with Roll Number %d not found.\n", roll);
    }
}


// update student by roll number
void up_s() {
    int roll;
    int found = 0;
    DPRINTF("Enter Roll Number to update: ");
    scanf("%d", &roll);

    student_t* temp = students_queue.base;

    for (int i = 0; i < students_queue.count; i++) {
        if (temp[i].roll_num == roll) {
            found = 1;
            int choice;
            do {
                DPRINTF("\nSelect field to update:\n");
                DPRINTF("1. First Name\n");
                DPRINTF("2. Last Name\n");
                DPRINTF("3. GPA\n");
                DPRINTF("4. Course IDs\n");
                DPRINTF("5. Exit Update Menu\n");
                DPRINTF("Enter choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        DPRINTF("Enter New First Name: ");
                        scanf("%s", temp[i].fname);
                        DPRINTF("First Name updated.\n");
                        break;
                    case 2:
                        DPRINTF("Enter New Last Name: ");
                        scanf("%s", temp[i].lname);
                        DPRINTF("Last Name updated.\n");
                        break;
                    case 3:
                        DPRINTF("Enter New GPA: ");
                        scanf("%f", &temp[i].GPA);
                        DPRINTF("GPA updated.\n");
                        break;
                    case 4:
                        DPRINTF("Enter 5 New Course IDs:\n");
                        for (int j = 0; j < 5; j++) {
                            DPRINTF("Course ID %d: ", j + 1);
                            scanf("%d", &temp[i].cid[j]);
                        }
                        for (int j = 5; j < 10; j++) {
                            temp[i].cid[j] = -1;
                        }
                        DPRINTF("Course IDs updated.\n");
                        break;
                    case 5:
                        DPRINTF("Exiting update menu.\n");
                        break;
                    default:
                        DPRINTF("Invalid choice. Please try again.\n");
                }
            } while (choice != 5);

            break;
        }
    }

    if (!found) {
        DPRINTF("Student with Roll Number %d not found.\n", roll);
    }
}


// show all information
void show_s() {
    if (students_queue.count == 0) {
        DPRINTF("No students to display.\n");
        return;
    }

    student_t* temp = students_queue.base;
    for (int i = 0; i < students_queue.count; i++) {
        DPRINTF("Student %d:\n", i + 1);
        DPRINTF("  Name: %s %s\n", temp[i].fname, temp[i].lname);
        DPRINTF("  Roll Number: %d\n", temp[i].roll_num);
        DPRINTF("  GPA: %.2f\n", temp[i].GPA);
        DPRINTF("  Courses: ");
        for (int j = 0; j < 10; j++) {
            if (temp[i].cid[j] != -1)
                DPRINTF("%d ", temp[i].cid[j]);
        }
        DPRINTF("\n\n");
    }
}

