/*
 * linkedlist.c
 *
 *  Created on: Dec 7, 2024
 *      Author: Hossam
 */
#include "linkedlist.h"

//===========================================================================================================

void Linkedlist_Insert_Node(struct SNode** head_ref, struct Sdata data, int position, struct SNode* prev_node)
{
	//allocate memory for the new node
	struct SNode* new_node = (struct SNode*) malloc(sizeof(struct SNode));

	// check if the memory is allocated or not
	if (new_node == NULL) {
		DPRINTF("=== Memory allocation failed. ===\n");
		return;
	}
	// assign the input data to the new node data section
	new_node->MemberData = data;
	// waiting to see if it is at beginning or end
	new_node->PNextNode = NULL;


	// based on choice "position flag"
	if (position == Node_at_beginning)
	{
		// update the pnextnode with the head ref
		//[new_node] --> [Node1] --> [Node2] --> NULL
		new_node->PNextNode = *head_ref;

		// (*head_ref) is updated to point to new_node
		// [head] --> [new_node] --> [Node1] --> [Node2] --> NULL
		*head_ref = new_node;
	}
	else if (position == Node_at_end) {
		// If the list is empty, new node becomes the head
		if (*head_ref == NULL) {
			*head_ref = new_node;
		} else {
			// make a temp to loop in list without changing head_ref
			struct SNode* temp = *head_ref;
			// Traverse to the last node
			while (temp->PNextNode != NULL) {

				temp = temp->PNextNode;
			}
			// Link the last node to the new node
			temp->PNextNode = new_node;
		}
	}
	else if (position == Node_after)
	{
		// Insert after a given node
		if (prev_node == NULL)
		{
			DPRINTF("=== The given previous node cannot be NULL. ===\n");
			free(new_node);
			return;
		}
		new_node->PNextNode = prev_node->PNextNode;
		prev_node->PNextNode = new_node;
	}
	else {
		DPRINTF("=== Invalid position specified.===\n");
		free(new_node);
	}
}

//=================================================================================================

void Linkedlist_PrintList(struct SNode* head_ref) {
	if (head_ref == NULL)
	{
		DPRINTF("=== List is Empty. ===\n");
		return;
	}
	struct SNode* temp = head_ref;
	while (temp != NULL) {
		DPRINTF("ID: %d, Name: %s, Degree: %0.2f\n", temp->MemberData.id, temp->MemberData.name, temp->MemberData.degree);
		temp = temp->PNextNode;
	}
}
//=================================================================================================

void Linkedlist_Delete_Node(struct SNode** head_ref, int key)
{
	// Check if the list is empty
	if (*head_ref == NULL) {
		DPRINTF("=== List is Empty. ===\n");
		return;
	}

	struct SNode* temp = *head_ref; // Pointer to traverse the list
	struct SNode* prev = NULL;     // Pointer to store the previous node

	// Case 1: If the node to be deleted is the head node
	if (temp != NULL && temp->MemberData.id == key) {
		// Update the head to point to the second node
		*head_ref = temp->PNextNode;
		free(temp); // Free the memory for the deleted node
		return;
	}

	// Case 2: Search for the node to be deleted in the list
	while (temp != NULL && temp->MemberData.id != key) {
		prev = temp;           // Update the previous node
		temp = temp->PNextNode; // Move to the next node
	}

	// If the key is not found in the list
	if (temp == NULL) {
		DPRINTF("=== Key is not in the list. ===\n");
		return;
	}

	// Case 3: Delete the node by updating the previous node's pointer
	prev->PNextNode = temp->PNextNode; // Bypass the node to be deleted
	free(temp);                        // Free the memory for the deleted node
}
//=================================================================================================

void Linkedlist_Delete_all_Nodes(struct SNode** head_ref)
{
	// Check if the list is empty
	if (*head_ref == NULL) {
		DPRINTF("=== List is Empty. ===\n");
		return;
	}

	struct SNode* temp = *head_ref; // Pointer to traverse the list
	struct SNode* next = NULL;     // Pointer to store the next node

	// loop in the nodes
	while (temp != NULL) {
		// as the temp points to the head make the next = pnext
		next = temp->PNextNode;
		// free the current node
		free(temp);
		// assign the temp with the next node
		temp = next;
	}

	// assign the head to null as all nodes deleted
	*head_ref = NULL;
}
//=================================================================================================

void Linkedlist_Get_Length(struct SNode* head_ref)
{
	// Check if the list is empty
	if (head_ref == NULL) {
		DPRINTF("=== List is Empty. ===\n");
		return;
	}
	int count = 0 ;
	struct SNode* temp = head_ref; // Pointer to traverse the list

	// loop in the nodes
	while (temp != NULL) {
		// as the temp points to the head make the next = pnext
		temp = temp->PNextNode;
		count ++;
	}
	DPRINTF("=== Length of this list is: %d ===\n",count);
}
//=================================================================================================

void Linkedlist_Get_Nth_Node(struct SNode** head_ref, int index)
{
	// Check if the list is empty
	if (*head_ref == NULL) {
		DPRINTF("=== List is Empty. ===\n");
		return;
	}

	struct SNode* temp = *head_ref; // Pointer to traverse the list
	int current_index = 1;          // Counter to track the position

	// Traverse the list until the desired index or end of the list
	while (temp != NULL && current_index < index) {
		temp = temp->PNextNode;
		current_index++;
	}

	// Check if we found the node at the given index
	if (temp == NULL) {
		DPRINTF("=== Index out of range. ===\n");
	} else {
		// Print or process the node data
		DPRINTF("Node at index %d:\n", index);
		DPRINTF("ID: %d, Name: %s, Degree: %0.2f\n", temp->MemberData.id, temp->MemberData.name, temp->MemberData.degree);
	}
}
//=================================================================================================

void Linkedlist_Get_Nth_Node_From_End(struct SNode** head_ref, int index) {
    // Check if the list is empty
    if (*head_ref == NULL) {
        DPRINTF("=== List is Empty. ===\n");
        return;
    }

    // Two pointers: 'temp' and 'main'
    struct SNode* temp = *head_ref; // Advance this pointer by 'index'
    struct SNode* selected = *head_ref; // This pointer will reach the desired node
    int count = 1;

    // Move 'temp' ahead of 'main' by 'index' steps
    while (count < index) {
        if (temp == NULL) {
            DPRINTF("=== Index %d is out of range. ===\n", index);
            return;
        }
        temp = temp->PNextNode;
        count++;
    }

    // Move both pointers one step at a time until 'temp' reaches the end
    while (temp != NULL) {
    	selected = selected->PNextNode;
        temp = temp->PNextNode;
    }

    // At this point, 'main' points to the nth node from the end
    DPRINTF("=== Node at index %d from the end ===\n", index);
    DPRINTF("ID: %d, Name: %s, Degree: %.2f\n",
    		selected->MemberData.id, selected->MemberData.name, selected->MemberData.degree);
}
