/*
	Given an array A (distinct elements) of size N. 
	Rearrange the elements of array in zig-zag fashion.
	The converted array should be in form a < b > c < d > e < f.
	The relative order of elements is same in the output i.e you have to iterate on the original array only.

	Input:
	The first line of input contains an integer T denoting the number of test cases.
	T test-cases follow. Each test-case contains two lines of input.
	The first line contains a single integer N denoting the size of array.
	The second line contains N space-separated integers denoting the elements of the array.

	Output:
	For each test-case, print the array in Zig-Zag fashion.

	Constraints:
	1 <= T <= 100
	1 <= N <= 100
	0 <= Ai <= 10000

	Example:
	Input:
	2
	7
	4 3 7 8 6 2 1
	4
	1 4 3 2
	Output:
	3 7 4 8 2 6 1
	1 4 2 3
 */

#include <stdio.h>
#include <stdlib.h>
#include "swap_integers.h"

// One pass of bubble sort
// Time complexity = 0(n)
void convert_to_zigzag(int arr[], const int n)
{
	int status = 0;						// 0 for less than 
										// !0 for greater than

		for (int i = 0; i < n - 1; i++)
		{			
			if (!status)
			{
				if (arr[i] > arr[i + 1])
					swap(&arr[i], &arr[i + 1]);
			}
			else
			{
				if (arr[i] < arr[i + 1])
					swap(&arr[i], &arr[i + 1]);
			}

			status = !status;
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

		convert_to_zigzag(arr, n);

		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n");

		free(arr);
	}

	return 0;
}
