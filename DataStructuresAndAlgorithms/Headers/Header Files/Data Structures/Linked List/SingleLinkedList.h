#pragma once
#include <stddef.h>

/**
 * \brief Structure of Node of Single Linked List
 */
typedef struct single_link_node
{
    int data;
    struct single_link_node *next;
}node;

inline int is_empty(node *start)
{
	if (start == NULL)
		return 0;
	return 1;
}

// region Printing and Length

extern void print_list(node *start);

extern int length_list(node *start);

// endregion

// region Insertion

extern node new_single_link_node(int data);

extern void insert_at_beginning(node **start, int data);

extern void insert_at_end(node **start, int data);

extern void insert_at_location(node *start, int data, int location);

extern void insert_before_value(node *start, int data, int value);

extern void insert_after_value(node *start, int data, int value);

// endregion

// region Deletion

extern int deletion_at_beginning(node **start);

extern int deletion_at_end(node **start);

extern int delete_at_location(node *start, int location);

extern int delete_value(node *start, int value);

extern void delete_list(node **start);

// endregion

// region Searching and Sorting

extern node search_node(int value);

extern void sort_single_linked_list(node *start);

// endregion

// region Reverse

extern void reverse_iterative(node **start);

extern void reverse_recursive(node *start);

// endregion

// region Other Functions

extern void detect_loop(node *start);

extern void node_swap(node **start, int x, int y);

// endregion