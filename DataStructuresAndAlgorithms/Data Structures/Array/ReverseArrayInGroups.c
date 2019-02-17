/*
	Given an array of positive integers. Reverse every sub-array of K group elements.

	Input:
	The first line of input contains a single integer T denoting the number of test cases.
	Then T test cases follow. Each test case consist of two lines of input.
	The first line of each test case consists of an integer N(size of array)
	and an integer K separated by a space. 
	The second line of each test case contains N space separated integers denoting the array elements.

	Output:
	For test case, print the modified array.

	Constraints:
	1 ≤ T ≤ 200
	1 ≤ N ≤ 107
	1 ≤ A[i] ≤ 1018

	Example:
	Input
	1
	5 3
	1 2 3 4 5

	Output
	3 2 1 5 4
*/

#include <stdio.h>
#include <stdlib.h>
#include "swap_integers.h"

// Algorithm: Simple
// First, we have to reverse the nos till n is divisible by k
// After that, we have to separately reverse the remaining.
// Time complexity: O(n)
// Auxiliary Space: O(1)
void print_reverse_array_in_groups(int *arr, const int n, const int k)
{
	for (int i = 0; i < n; i += k)
	{
		int left = i;

		// Condition for checking whether k is outside of the bound of the array
		int right = min(i + k - 1, n - 1);

		while (left < right)
			swap(&arr[left++], &arr[right--]);
	}

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

int main(void)
{
	int t;
	scanf_s("%d", &t);

	while (t--)
	{
		int n, k;
		scanf_s("%d", &n);
		scanf_s("%d", &k);

		int *arr = (int *)calloc(n, sizeof(int));

		for (int i = 0; i < n; i++)
			scanf_s("%d", &arr[i]);

		printf("Array after reversing in groups of size %d is : ", k);
		print_reverse_array_in_groups(arr, n, k);
		printf("\n");

		free(arr);
	}

	return 0;
}