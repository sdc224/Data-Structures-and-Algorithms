/*
	Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

	Input:
	The first line contains an integer 'T' denoting the total number of test cases.
	Then T test-cases follow. Each test-cases contains two lines of input.
	The first line denotes the size of the array N.
	The second lines contains the elements of the array A separated by spaces.

	Output: 
	For each test-case, print the sorted array.

	Constraints: 
	1 <= T <= 500
	1 <= N <= 106
	0 <= Ai <= 2

	Example:
	Input :
	2
	5
	0 2 1 2 0
	3
	0 1 0

	Output:
	0 0 1 2 2
	0 0 1

	Explanation:
	Test-case 1: After segregating the 0s, 1s and 2s, we have 0 0 1 2 2 which shown in the output.
*/

#include <stdio.h>
#include <stdlib.h>

// Counting process
// Algorithm: Count no of zero, one and two, and then replace with the previous array
/*
 * Problems: 
 * 1) It requires two traversals of array.
 * 2) This solution may not work if values are a part of structure.
 *  For example, consider a situation where 0 represents 
 *  Computer Science Stream, 1 represents Electronics and 2 represents Mechanical.
 *   We have a list of student objects (or structures) and we want to sort them.
 *    We cannot use above sort as we simply put 0s, 1s and 2s one by one.
 */
void sort_0_1_2(int *arr, const int n)
{
	int no_of_zero = 0, no_of_one = 0, no_of_two = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
			no_of_zero++;
		else if (arr[i] == 1)
			no_of_one++;
		else if (arr[i] == 2)
			no_of_two++;
	}

	for (int i = 0; i < no_of_zero; i++)
		arr[i] = 0;

	for (int i = no_of_zero; i < no_of_zero + no_of_one; i++)
		arr[i] = 1;

	for (int i = no_of_zero + no_of_one; i < n; i++)
		arr[i] = 2;
}

void swap(int *a, int *b)
{
	const int temp = *a;
	*a = *b;
	*b = temp;
}

void sort_0_1_2_optimized(int *arr, const int n)
{
	int low = 0, mid = 0, high = n - 1;

	while (mid <= high)
	{
		switch (arr[mid])
		{
		case 0:
			swap(&arr[low], &arr[mid]);
			low++;
			mid++;
			break;

		case 1:
			mid++;
			break;

		case 2:
			swap(&arr[mid], &arr[high]);
			high--;
			mid++;
			break;

		default:
			break;
		}
	}
}

int main(void)
{
	int t;
	scanf_s("%d", &t);

	while (t--)
	{
		int n;
		scanf_s("%d", &n);

		int *arr = (int *)calloc(n, sizeof(int));

		for (int i = 0; i < n; i++)
			scanf_s("%d", &arr[i]);

		sort_0_1_2_optimized(arr, n);

		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);

		printf("\n");
	}
	
	return 0;
}
