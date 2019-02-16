#include "swap_integers.h"

void swap(int* a, int* b)
{
	const int temp = *a;
	*a = *b;
	*b = temp;
}