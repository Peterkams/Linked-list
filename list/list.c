// list/list.c
// 
// Implementation for linked list.
//
// Peter Kamlewechi

#include <stdio.h>

#include "list.h"

list_t *list_alloc() {
  list_t *linked_list;
  linked_list = malloc(sizeof(list_t));
	linked_list->head = NULL;
    return linked_list;
}

void list_free(list_t *l) {
  //struct node* temp;
  /*node_t temp;
  
  while(l->head != NULL)
  {
    temp = l->head;
    l->head = node_t->next;
    free(tmp);
  }*/
  if (!l) {
    return;
  }
  free (l);
}

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

void list_add_to_front(list_t *l, elem value) {
	node_t *new_node;
	new_node->value = value;
        new_node->next = l->head;
        l->head = new_node;
}

void list_add_at_index(list_t *l, elem value, int index) {
	node_t *newnode;
	newnode = malloc(sizeof(node_t));
        newnode->value = value;
        node_t *temp = l->head;
        int counter = 0;
        while(temp->next != NULL)
	{
        	if (counter+1 == index)
		{
                	newnode->next = temp->next;
            		temp->next = newnode;
            		break;
        	}
		counter++;
                temp = temp->next;
        } 
}

elem list_remove_from_back(list_t *l) {
	node_t *previous_node = l->head;
	node_t *current_node = prev_node->next;
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

elem list_remove_from_front(list_t *l) {
	elem value = 0;
    	node_t *current = l->head;
    	value = current->value;
    	l->head = current->next;
    	list_t *remove;
    	remove->head = current;
    	list_free(remove);
    	return value;
}

elem list_remove_at_index(list_t *l, int index) {
	int counter = 0;
    	node_t *prev_node = l->head;
	node_t *current_node = prev_node->next;
    	while (current_node->next != NULL && count < (index - 1))
	{
        	counter++;
		prev_node = current_node;
        	current_node = current_node->next;
    	}
    	node_t *temp = current_node;
    	prev_node->next = current_node->next;
    	elem value = temp->value;
    	free(temp);
    	return value;
}

bool list_is_in(list_t *l, elem value) {
	bool element_present;
    	node_t *current_node = l->head;
    	while (current_node->next != NULL && !exist)
    	{
		if (current_node->value == value){
			element_present = true;
		}
        	current_node = current_node->next;
    	}
    	return element_present; 
}

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
