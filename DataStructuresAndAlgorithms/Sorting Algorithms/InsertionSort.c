#include<stdio.h>

void InsertionSort(int arr[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
}

void RecursiveInsertionSort(int arr[], int n)
{
	if (n <= 1)
		return;
	
	RecursiveInsertionSort(arr, n - 1);									//Recursively Sort n - 1 elements

	int key = arr[n - 1];
	int j = n - 2;
	while (j >= 0 && arr[j] > key)
	{
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = key;
}

int main()
{
	printf("Insertion Sorting\n");
	int arr[] = { 10, 18, 2, 4, 27, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	RecursiveInsertionSort(arr, size);
	printf("After Sorting: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}