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
    while(current_node != NULL){
        length++;
        current_node = current_node->next;
    }
    return length; 
}

void list_add_to_back(list_t *l, elem value) {}
void list_add_to_front(list_t *l, elem value) {}
void list_add_at_index(list_t *l, elem value, int index) {}

elem list_remove_from_back(list_t *l) { return -1; }
elem list_remove_from_front(list_t *l) { return -1; }
elem list_remove_at_index(list_t *l, int index) { return -1; }

bool list_is_in(list_t *l, elem value) { return false; }
elem list_get_elem_at(list_t *l, int index) { return -1; }
int list_get_index_of(list_t *l, elem value) { return -1; }
