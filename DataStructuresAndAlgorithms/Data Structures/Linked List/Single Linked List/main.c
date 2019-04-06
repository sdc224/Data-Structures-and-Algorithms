#include <Data Structures/Linked List/SingleLinkedList.h>
#include <stdio.h>

int main(void)
{
	node *start = NULL;

	insert_at_beginning(&start, 10);
	insert_at_beginning(&start, 20);
	insert_at_beginning(&start, 30);
	insert_at_beginning(&start, 40);
	insert_at_beginning(&start, 50);

	insert_at_end(&start, 60);
	insert_at_end(&start, 70);

	printf("Total no of nodes: %d\n", length_list(start));

	print_list(start);
}
