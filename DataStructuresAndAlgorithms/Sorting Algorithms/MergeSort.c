#include<stdio.h>
int A[50];
void Merge(int arr[], int start, int mid, int end)
{
	int i = start, j = mid + 1, k = start;
	
	
	while (i <= mid && j <= end)
	{
		if (arr[i] < arr[j])
			A[k] = arr[i++];
		else
			A[k] = arr[j++];
		
		k++;
	}

	while (i <= mid)
		A[k++] = arr[i++];

	while (j <= end)
		A[k++] = arr[j++];

	for (i = start; i < k; i++)
		arr[i] = A[i];
}

void MergeSort(int arr[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;

		MergeSort(arr, start, mid);
		MergeSort(arr, mid + 1, end);

		Merge(arr, start, mid, end);
	}
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

void IterativeMergeSort(int arr[], int start, int end)
{
	while (start < end)
	{
		int mid = (start + end) / 2;
		


	}
}

int main()
{
	printf("Merge Sorting\n");
	int arr[] = { 10, 18, 2, 4, 27, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, 0, size - 1);
	printf("After Sorting: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}