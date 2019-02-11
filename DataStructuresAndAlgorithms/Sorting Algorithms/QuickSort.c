#include<stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
	const int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * \brief 
 * \param arr 
 * \param start 
 * \param end 
 * \return 
 */
int Partition(int arr[], const int start, const int end)
{
	const int pivot = arr[start];
	int i = start, j = end;
	while (i <= j)
	{		
		do
			i++;
		while (arr[i] <= pivot);
		
		do
			j--;
		while (arr[j] >= pivot);
		
		if (i < j)
			swap(&arr[i], &arr[j]);
		else
		{
			swap(&arr[start], &arr[j]);
			return j;
		}
	}
	return 0;
}

/**
 * \brief 
 * \param arr 
 * \param start 
 * \param end 
 * \return 
 */
int partition(int arr[], const int start, const int end)		//Logic - Pivot at last, i, j both are in first
{													
	int pivot = arr[end];										//if arr[i]<=pivot then swap arr[i] with arr[j]
	int j = start - 1;

	for (int i = start; i < end; i++)
	{
		
		if (arr[i] <= pivot)
		{
			j++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[j + 1], &arr[end]);
	return (j + 1);
}

/**
 * \brief 
 * \param arr 
 * \param start 
 * \param end 
 */
void QuickSort(int arr[], const int start, const int end)
{
	if (start < end)
	{
		const int pivot_index = partition(arr, start, end);
		QuickSort(arr, start, pivot_index - 1);
		QuickSort(arr, pivot_index + 1, end);
	}
}

void randomised_quick_sort(int arr[], const int start, const int end)
{
	if (start < end)
	{
		const int i = rand() % (end - start + 1) + start;
		swap(&arr[i], &arr[end]);

		const int pivot_index = partition(arr, start, end);
		randomised_quick_sort(arr, start, pivot_index - 1);
		randomised_quick_sort(arr, pivot_index + 1, end);
	}
}

int main()
{
	printf("Quick Sorting\n");
	int arr[] = { 10, 18, 2, 4, 27, 7, 15 };
	//int arr[] = { 1, 2, 3, 4, 5, 6 };

	const int size = (sizeof(arr) / sizeof(arr[0]));
	randomised_quick_sort(arr, 0, size - 1);
	printf("After Sorting: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}