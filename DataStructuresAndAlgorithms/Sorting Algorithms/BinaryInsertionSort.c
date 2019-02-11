#include <stdio.h>

int binary_search(int a[], const int start, const int end, const int val)
{
	if (end <= start)
	{
		if (val > a[start])
			return start + 1;
		return start;
	}
	
	const int mid = (start + end) / 2;

	if (a[mid] == val)
		return mid + 1;
	if (a[mid] < val)
		return binary_search(a, mid + 1, end, val);
	return binary_search(a, start, mid - 1, val);
}

void insertion_sort(int a[], const int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		const int key = a[i];
		const int location = binary_search(a, 0, j, key);
		while (j >= location && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

int main()
{
	//int a[] = { 10, 12, 9, 6, 14 };
	int a[] = { 23, 12, 56, 44, 90 };
	const int size = sizeof(a) / sizeof(a[0]);

	insertion_sort(a, size);
	printf("\nArray after Sorting: ");
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	int search_index = binary_search(a, 0, size, 6);
	search_index == 0 ? printf("\nElement not found in the array.\n") : printf("\nElement is present in the array at %d position\n", search_index);
	return 0;
}
