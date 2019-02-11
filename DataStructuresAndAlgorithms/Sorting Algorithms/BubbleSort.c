#include<stdio.h>

void swap(int *a, int *b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int arr[], int n) 
{
	int i, swapped = 0;
	
	for (int j = 0; j < n - 1; j++)
	{
		for (i = 0; i < n - j - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
				swapped = 1;
			}
		}

		if (swapped == 0)
			break;
	}
	
}

void BubbleSortRecursive(int arr[], int n)
{
	if (n == 1)
		return;
	else
	{
		// For getting the maximum element to the last in the sub array
		// First Run
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] > arr[i + 1])
				swap(&arr[i], &arr[i + 1]);
		}
		BubbleSortRecursive(arr, n - 1);
	}
}

int main()
{
	printf("Bubble Sorting\n");
	int arr[] = { 10, 18, 2, 4, 27, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, size);
	//BubbleSortRecursive(arr, size);
	printf("After Sorting: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}