/*
 * linkedlist.h
 *
 *  Created on: Dec 7, 2024
 *      Author: Hossam
 *
 *      The goal is to make a generic customizable singly
 *      linkedlist APIs to be able to use it with any project
 *
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "stdlib.h"

// This macro to overcome the bug of printf in eclipse ide "remove if not needed"
#define DPRINTF(...) {fflush(stdout); fflush(stdout);\
						printf(__VA_ARGS__);\
						fflush(stdout); fflush(stdout);}

#define Node_at_end 		0
#define Node_at_beginning 	1
#define Node_after 			2

//=============================== User Configuration =======================================
struct Sdata
{
	int id;
	char name[40];
	float degree;
};

//every node contains effictive data & address of the next node
struct SNode
{
	//payload data
	struct Sdata MemberData;
	// pointer of the next student
	struct SNode* PNextNode;
};

//============================= APIs============================================

/*
 * Function: Linkedlist_Insert_Node
 * -------------------------------
 * Inserts a new node into the linked list at a specified position.
 *
 * Parameters:
 * - head_ref: Pointer to the head of the linked list.
 * - data: The data to be inserted into the new node.
 * - position: The position where the new node should be inserted.
 *   - Node_at_beginning: Insert at the beginning of the list.
 *   - Node_at_end: Insert at the end of the list.
 *   - Node_after: Insert after a specified node (prev_node must be non-NULL).
 * - prev_node: A pointer to the node after which the new node should be inserted.
 *
 * Restrictions:
 * - If the position is Node_after, the prev_node must not be NULL.
 * - If memory allocation for the new node fails, the function prints an error message and returns.
 */

void Linkedlist_Insert_Node(struct SNode** head_ref, struct Sdata data, int position, struct SNode* prev_node);
//-----------------------------------------------------------------------------------------------------------------

/*
 * Function: Linkedlist_PrintList
 * ------------------------------
 * Prints the contents of the linked list.
 *
 * Parameters:
 * - head_ref: Pointer to the head of the linked list.
 *
 * Restrictions:
 * - If the list is empty (head_ref is NULL), the function prints a message and returns.
 */

void Linkedlist_PrintList(struct SNode* head_ref);
//-----------------------------------------------------------------------------------------------------------------

/*
 * Function: Linkedlist_Delete_Node
 * --------------------------------
 * Deletes a node from the linked list based on a given key.
 *
 * Parameters:
 * - head_ref: Pointer to the head of the linked list.
 * - key: The ID of the node to be deleted (MemberData.id).
 *
 * Functionality:
 * - If the list is empty, the function prints an appropriate message and returns.
 * - If the node to be deleted is the head node, the head is updated to the next node.
 * - If the node to be deleted is elsewhere in the list, the function finds the node,
 *   updates the previous node's `PNextNode` pointer to skip over the deleted node, and frees the memory.
 * - If the key is not found in the list, the function prints an appropriate message.
 *
 * Restrictions:
 * - The 'head_ref' must not be NULL for meaningful operations. If NULL, it simply indicates the list is empty.
 */

void Linkedlist_Delete_Node(struct SNode** head_ref, int key);
//-----------------------------------------------------------------------------------------------------------------

/*
 * Function: Linkedlist_Delete_all_Nodes
 * -------------------------------------
 * Deletes all nodes in the linked list and frees their memory.
 *
 * Parameters:
 * - head_ref: Pointer to the head of the linked list.
 *
 * Functionality:
 * - Iteratively traverses the linked list.
 * - Frees the memory allocated for each node.
 * - Sets the head reference to NULL to indicate an empty list.
 *
 * Restrictions:
 * - The `head_ref` should point to a valid linked list or NULL.
 */
void Linkedlist_Delete_all_Nodes(struct SNode** head_ref);
//-----------------------------------------------------------------------------------------------------------------

/*
 * Function: Linkedlist_Get_Length
 * --------------------------------
 * Calculates and prints the length of the linked list.
 *
 * Parameters:
 * - head_ref: Pointer to the head of the linked list.
 *
 * Functionality:
 * - This function traverses the linked list starting from the head node.
 * - It counts the number of nodes in the list by incrementing a counter for each node encountered.
 * - Once traversal is complete, it prints the total count.
 * - If the linked list is empty (head_ref is NULL), it prints a message indicating the list is empty.
 *
 * Edge Cases:
 * - If the linked list is empty, the function prints "List is Empty" and does not proceed with counting.
 *
 * Restrictions:
 * - The head_ref pointer should not be NULL itself; it must either point to the first node or be an empty list indicator.
 */
void Linkedlist_Get_Length(struct SNode* head_ref);
//-----------------------------------------------------------------------------------------------------------------

/**
 * @brief Retrieves the nth node (1-based index) from the beginning of the linked list.
 *
 * @param head_ref Pointer to the head of the linked list.
 * @param index The position (1-based) of the node to retrieve.
 *
 * This function traverses the linked list starting from the head until it reaches
 * the desired node at the given index. If the index is out of range, it notifies
 * the user. Otherwise, it prints the details of the node.
 *
 * Steps:
 * 1. Check if the list is empty. If empty, print a message and exit.
 * 2. Use a traversal pointer to iterate through the list while maintaining a
 *    counter to track the position.
 * 3. Stop traversal when the desired index is reached or the end of the list.
 * 4. If the index is valid, print the node data; otherwise, indicate that the index
 *    is out of range.
 */
void Linkedlist_Get_Nth_Node(struct SNode** head_ref, int index);
//-----------------------------------------------------------------------------------------------------------------

/**
 * @brief Retrieves the nth node (1-based index) from the end of the linked list.
 *
 * @param head_ref Pointer to the head of the linked list.
 * @param index The position (1-based) of the node to retrieve from the end.
 *
 * This function uses two pointers to efficiently find the nth node from the end.
 * The first pointer (`temp`) is moved `index` steps ahead of the second pointer (`selected`).
 * Then, both pointers are moved one step at a time until the first pointer reaches
 * the end of the list. At this point, the second pointer points to the nth node
 * from the end.
 *
 * Steps:
 * 1. Check if the list is empty. If empty, print a message and exit.
 * 2. Initialize two pointers, `temp` and `selected`, both starting at the head.
 * 3. Move the `temp` pointer `index` steps ahead, ensuring that the index is not
 *    out of range. If out of range, notify the user and exit.
 * 4. Move both pointers one step at a time until `temp` reaches the end.
 * 5. At this point, `selected` points to the desired node. Print the node data.
 */
void Linkedlist_Get_Nth_Node_From_End(struct SNode** head_ref, int index);
//-----------------------------------------------------------------------------------------------------------------







#endif /* LINKEDLIST_H_ */
