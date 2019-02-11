#include<stdio.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void Maxheap(int arr[], int n, int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	int maxValueNode = root;

	if (arr[left] > arr[maxValueNode])
		maxValueNode = left;
	if (arr[right] > arr[maxValueNode])
		maxValueNode = right;

	if (maxValueNode != root && maxValueNode < n)							//Only when root is not max
	{
		swap(&arr[maxValueNode], &arr[root]);
		Maxheap(arr, n, maxValueNode);
	}
}

void BuildHeap(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		Maxheap(arr, n, i);
	}
}

void HeapSort(int arr[], int n)
{
	BuildHeap(arr, n);
	//Heap Sort technique, swap last element of the array with the first element
	for (int i = n-1; i >= 0; i--)
	{
		swap(&arr[i], &arr[0]);
		Maxheap(arr, i, 0);													//For the remaining array
	}
}

int main()
{
	printf("Heap Sorting\n");
	int arr[] = { 10, 18, 2, 4, 27, 7, 15 };
	int size = (sizeof(arr) / sizeof(arr[0]));	
	HeapSort(arr, size);
	printf("After Sorting: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}