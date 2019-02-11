// Search an element in sorted but rotated array in Binary Search
// It means time complexity should be O(nlogn)
// For e.g. an array might be {3,4,5,1,2}
// Then the rotation point(pivot) of the array should be 3
// Means index of 1

#include <stdio.h>

int search(int array[], const int start, const int end, const int key)
{
	if (start > end)
		return -1;

	const int mid = (start + end) / 2;

	if (array[mid] == key)
		return mid;

	if (array[start] <= array[mid])
	{
		if (key >= array[start] && key <= array[mid])
			return search(array, start, mid - 1, key);

		return search(array, mid + 1, end, key);
	}

	if (key >= array[mid] && key <= array[end])
		return search(array, mid + 1, end, key);

	return search(array, start, mid - 1, key);
}

int main(void)
{
	int array[] = { 3, 4, 5, 1, 2 };
	const int n = sizeof array / sizeof array[0];

	const int key = 4;

	const int index = search(array, 0, n - 1, key);

	if (index != -1)
		printf("Element %d is found at index %d\n", key, index);
	else
		printf("Element %d is not found\n", key);

	return 0;
}