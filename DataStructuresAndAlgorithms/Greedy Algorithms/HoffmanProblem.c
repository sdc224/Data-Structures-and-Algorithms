#include<stdio.h>

typedef struct HoffmanCodes
{
	char item;
	int frequency;
	int variable_length_code;
}HoffmanCodes;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
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

void HoffmanCoding(int arr[], int n)
{

}

int main()
{
	HoffmanCodes first[6];
	int n = 6;
	long memoryForFixedLength = 0;
	printf("Enter Data\n");
	for (int i = 0; i < n; i++)
	{
		printf("Enter Item %d name and frequency: ", i + 1);
		scanf_s("%c %d", &first[i].item, &first[i].frequency);
		memoryForFixedLength += first[i].frequency;
	}
	int bit;
	if (n < 4)
		bit = 2;
	else if (n < 8)
		bit = 3;
	else if (n < 16)
		bit = 4;
	else
		bit = 5;
	memoryForFixedLength *= (bit * 1000);
	return 0;
}