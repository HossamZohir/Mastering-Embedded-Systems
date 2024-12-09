/*
 * main.c
 *
 *  Created on: Dec 7, 2024
 *      Author: Hossam
 *
 *      This is a test for linkedlist APIs
 */
#include "linkedlist.h"

int main() {
    struct SNode* head = NULL;
    int choice;

    do {
        DPRINTF("\nChoose an operation:\n");
        DPRINTF("1. Insert Node\n");
        DPRINTF("2. Print List\n");
        DPRINTF("3. Delete Node\n");
        DPRINTF("4. Delete All Nodes\n");
        DPRINTF("5. Get Length of List\n");
        DPRINTF("6. Get Node by Index\n");
        DPRINTF("7. Get Nth Node from End\n");
        DPRINTF("0. Exit\n");
        DPRINTF("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Sdata data;
                int position;
                struct SNode* prev_node = NULL;

                DPRINTF("Enter ID: ");
                scanf("%d", &data.id);
                DPRINTF("Enter Name: ");
                scanf("%s", data.name);
                DPRINTF("Enter Degree: ");
                scanf("%f", &data.degree);

                DPRINTF("Enter position (0: Beginning, 1: End, 2: After a node): ");
                scanf("%d", &position);

                if (position == Node_after) {
                    int prev_id;
                    DPRINTF("Enter the ID of the previous node: ");
                    scanf("%d", &prev_id);

                    struct SNode* temp = head;
                    while (temp != NULL && temp->MemberData.id != prev_id) {
                        temp = temp->PNextNode;
                    }
                    if (temp == NULL) {
                        DPRINTF("Previous node with ID %d not found.\n", prev_id);
                        break;
                    }
                    prev_node = temp;
                }

                Linkedlist_Insert_Node(&head, data, position, prev_node);
                break;
            }

            case 2:
                Linkedlist_PrintList(head);
                break;

            case 3: {
                int key;
                DPRINTF("Enter the ID of the node to delete: ");
                scanf("%d", &key);
                Linkedlist_Delete_Node(&head, key);
                break;
            }

            case 4:
                Linkedlist_Delete_all_Nodes(&head);
                break;

            case 5:
                Linkedlist_Get_Length(head);
                break;

            case 6: {
                int index;
                DPRINTF("Enter the index of the node to retrieve: ");
                scanf("%d", &index);
                Linkedlist_Get_Nth_Node(&head, index);
                break;
            }

            case 7: {
                int index;
                DPRINTF("Enter the index from the end of the node to retrieve: ");
                scanf("%d", &index);
                Linkedlist_Get_Nth_Node_From_End(&head, index);
                break;
            }

            case 0:
                DPRINTF("Exiting program.\n");
                break;

            default:
                DPRINTF("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    // Free all nodes before exiting
    Linkedlist_Delete_all_Nodes(&head);
    return 0;
}
