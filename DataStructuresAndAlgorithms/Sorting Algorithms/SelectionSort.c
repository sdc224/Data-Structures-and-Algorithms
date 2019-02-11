#include<stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort(int arr[], int n) 
{
	int min_pos;
	for (int i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (int j = i+1; j < n; j++)
		{
			if (arr[j] < arr[min_pos])
			{
				min_pos = j;
			}
		}
		swap(&arr[i], &arr[min_pos]);
	}
}

//Utility Function for Selection Sort Recursive for Getting the minimum element's position
int MinPos(int arr[], int first, int end)
{
	if (first == end)
		return first;

	int min_pos = MinPos(arr, first + 1, end);											//Recursively find minimum of other elements

	if (arr[first] < arr[min_pos])
		return first;
	else
		return min_pos;
}

void RecursiveSelectionSort(int arr[], int starting_index, int n)
{
	if (starting_index == n)
		return;

	int min_pos = MinPos(arr, starting_index, n - 1);

	if (min_pos != starting_index)
		swap(&arr[starting_index], &arr[min_pos]);

	RecursiveSelectionSort(arr, starting_index + 1, n);
}

int main()
{
	printf("Selection Sorting\n");
	int arr[] = { 10, 18, 2, 4, 27, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//SelectionSort(arr, size);
	RecursiveSelectionSort(arr, 0, size);
	printf("After Sorting: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}