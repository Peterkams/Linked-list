// list/list.c
// 
// Implementation for linked list.
//
// Peter Kamlewechi

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// Function for allocating to a list.
list_t *list_alloc() {
  	list_t *linked_list;
  	linked_list = malloc(sizeof(list_t));
	linked_list->head = NULL;
    	return linked_list;
}

// Function for freeing a list.
void list_free(list_t *l) {
	if (l == NULL)
    	{
        	return;
    	}
    	node_t *current_node = l->head;
    	node_t *next_node = NULL;
    	while (current_node != NULL)
    	{
        	next_node = current_node->next;
        	free(current_node);
        	current_node = next_node;
    	}
    	l->head = NULL;
	free(l);
}

// Function to print a list in a format.
void list_print(list_t *l) {
	node_t *current_node = l->head;
	node_t *next_node = NULL;
	while (current_node->next != NULL)
	{
		printf("%d -> ", current_node->value);
		next_node = current_node->next;
		current_node = next_node;
	}
	printf("%d", current_node->value);
	printf("\n");
}

// Returns the length of the given lsit.
int list_length(list_t *l) {
    	int length;
    	node_t *current_node = l->head;
    	while(current_node != NULL)
	{
        	length++;
        	current_node = current_node->next;
   	}
    	return length; 
}

// The below methods are for adding an element to a list.

// Function to add an element to the back of a list.
void list_add_to_back(list_t *l, elem value) {
        node_t *new_node = malloc(sizeof(node_t));
        new_node->value = value;
        new_node->next = NULL;
        node_t *current_node = l->head;
	
        while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}
        current_node->next = new_node;
}

// Function to add an element to the front of a list.
void list_add_to_front(list_t *l, elem value) {
    	node_t *new_node = malloc(sizeof(node_t));
    	new_node->value = value;
    	new_node->next = l->head;
	l->head = new_node;
}

// Function to add an element at a particular index in the list.
void list_add_at_index(list_t *l, elem value, int index) {	
	int count = 1;
    	node_t *new_node = malloc(sizeof(node_t));
    	new_node->value = value;
    	new_node->next = NULL;
    	node_t * current_node = l->head;
    	node_t* next_node = NULL;
    	while (current_node != NULL && count < (index))
    	{
        	count++;
        	next_node = current_node->next;
        	current_node = next_node;
   	}
   	next_node = current_node->next;
    	current_node->next = new_node;
    	new_node->next = next_node;
}

// The below methods are for removing an element to a list.

// Function to remove an element from the back of a list.
elem list_remove_from_back(list_t *l) {
	node_t *previous_node = l->head;
	node_t *current_node = previous_node->next;
    	while (current_node->next != NULL)
    	{
		previous_node = current_node;
        	current_node = current_node->next;
    	}
	previous_node->next = NULL;
        elem value = current_node->value;
    	free(current_node);
    	return value; 
}

// Function to remove an element from the front of a list.
elem list_remove_from_front(list_t *l) {
	node_t *current_node = l->head;
    	l->head = current_node->next;
    	elem value = current_node->value;
    	free(current_node);
    	return value;
}

// Function to remove an element at a particular index of a list.
elem list_remove_at_index(list_t *l, int index) {
	int counter = 0;
    	node_t *previous_node = l->head;
	node_t *current_node = previous_node->next;
    	while (current_node->next != NULL && counter < (index - 1))
	{
        	counter++;
		previous_node = current_node;
        	current_node = current_node->next;
    	}
    	node_t *temp = current_node;
    	previous_node->next = current_node->next;
    	elem value = temp->value;
    	free(temp);
    	return value;
}

// Function to check if a given element is present in a list.
bool list_is_in(list_t *l, elem value) {
	bool element_present;
    	node_t *current_node = l->head;
    	while (current_node->next != NULL && !element_present)
    	{
		if (current_node->value == value){
			element_present = true;
		}
        	current_node = current_node->next;
    	}
    	return element_present; 
}


// Function to return the element at a particular index.
elem list_get_elem_at(list_t *l, int index) {
	int counter = 0;
	elem value = 0;
	node_t *current_node = l->head;
    	while (current_node->next != NULL && counter < (index))
    	{
		counter++;
        	current_node = current_node->next;
    	}
	if (current_node != NULL){
		value = current_node->value;
	}
	return value; 
}

// Function to return the index in which the element is present.
int list_get_index_of(list_t *l, elem value) {
	int counter = 0;
	node_t *current_node = l->head;
    	while (current_node->next != NULL)
    	{
		if (current_node->value == value){
			return counter;
		} else {
			counter++;
			current_node = current_node->next;
		}
    	}
	return counter; 
}
