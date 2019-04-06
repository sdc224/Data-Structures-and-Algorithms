#include "Data Structures/Linked List/SingleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(node *start)
{
	node *current = start;

	while (current != NULL)
	{
		printf("%d --> ", current->data);

		if (current -> next == NULL)
			printf("NULL");
		
		current = current->next;
	}

	printf("\n");
}

int length_list(node *start)
{
	node *current = start;
	int count = 0;

	while (current != NULL)
	{
		count++;

		current = current->next;
	}

	return count;
}

node* new_single_link_node(const int data)
{
	node *n = (node *)malloc(sizeof(node));
	n->data = data;
	n->next = NULL;
	return n;
}

void insert_at_beginning(node **start, const int data)
{
	node *n = new_single_link_node(data);
	n->next = *start;
	*start = n;
}

void insert_at_end(node **start, const int data)
{
	node *n = new_single_link_node(data);

	if (*start == NULL)
	{
		*start = n;
		return;
	}

	node *current = *start;

	while (current->next != NULL)
		current = current->next;

	current->next = n;
}
