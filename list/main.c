#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation.\n");
  //printf("We assume index starts from 0.\n\n");
	
  list_t *test_list = list_alloc();
  
  // Test cases for functions to add to a list.
  list_add_to_back(test_list, 5);
  printf("Add %d to the back: ", 5);
  list_print(test_list);
    
	list_add_to_back(test_list, 8);
  printf("Add %d to the back: ", 8);
  list_print(test_list);
  
  list_add_to_back(test_list, 10);
  printf("Add %d to the back: ", 10);
  list_print(test_list);
  
	list_add_to_front(test_list, 9);
  printf("Add %d to the front: ", 9);
  list_print(test_list);
    
	list_add_to_front(test_list, 3);
  printf("Add %d to the front: ", 3);
  list_print(test_list);
  
  list_add_to_front(test_list, 15);
  printf("Add %d to the front: ", 15);
  list_print(test_list);
    
	list_add_at_index(test_list, 2, 3);
  printf("Add %d at index %d: ", 2 , 3);
  list_print(test_list);
    
	// Test cases for functions to remove from a list.
  elem test_element_one = list_remove_from_back(test_list);
  printf("Removed %d from the back: ", test_element_one);
	list_print(test_list);
  
	elem test_element_two = list_remove_from_front(test_list);
  printf("\nRemoved %d from the front: ", test_element_two);
  list_print(test_list);
    
	elem test_element_three = list_remove_at_index(test_list, 2);
  printf("Removed %d from the index, %d: ", test_element_three, 2);
  list_print(test_list);

	// Test case for length of a list.
	int length_of_list = list_length(test_list);
	printf("\nLength of the list is: %d.\n", length_of_list);
	
	// Test cases for search functions of a list.
  elem test_element_four = 15;
	bool element_present = list_is_in(test_list, test_element_four);
	if (element_present){
		printf("%d is in the list.\n", test_element_four);
	} else {
		printf("%d is not in the list.\n", test_element_four);
	}
	
	int test_element_index_one = 4;
	elem test_element_five = list_get_elem_at(test_list, test_element_index_one);
	printf("Element at index %d is: %d. \n", test_element_index_one, test_element_five);
	
	elem test_element_six = 9;
	int test_element_index_two = list_get_index_of(test_list, test_element_six);
	printf("Element %d is at index: %d. \n", test_element_six, test_element_index_two);
	
	list_free(test_list);
	return 0;
}
