/*
	Given an array arr and a number K where K is smaller than size of array,
	the task is to find the K’th smallest element in the given array.
	It is given that all array elements are distinct.

	Expected Time Complexity: O(n)

	Input:
	The first line of input contains an integer T, denoting the number of test-cases.
	Then T test cases follow. Each test case consists of three lines.
	First line of each test-case contains an integer N denoting size of the array.
	Second line contains N space separated integer denoting elements of the array.
	Third line of the test case contains an integer K.

	Output:
	Corresponding to each test case, print the desired output in a new line.

	Constraints:
	1 <= T <= 106
	1 <= N <= 100
	1 <= arr[i] <= 103
	1 <= K <= N

	Example:
	Input:
	2
	6
	7 10 4 3 20 15
	3
	5
	7 10 4 20 15
	4

	Output:
	7
	15

	Explanation:
	Test-case 1: 3rd smallest element in the given array is 7.
*/

#include <stdio.h>
#include <stdlib.h>
#include "swap_integers.h"

int partition1(int *arr, const int start, const int end)
{	
	const int pivot = arr[start];

	int i = start + 1, j = end;

	while (i <= j)
	{
		while (arr[i] < pivot && i < end)
			i++;

		while (arr[j] > pivot && j > start)
			j--;

		if (i < j)
		{
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
		else
			break;
	}

	arr[start] = arr[j];
	arr[j] = pivot;
	return j;
}

int find_kth_smallest_using_quick_sort(int *arr, const int start, const int end, int k)
{
	if (start < end)
	{
		const int pivot = partition1(arr, start, end);

		if (pivot == k - 1)
			return pivot;
		if (pivot > k - 1)
			return find_kth_smallest_using_quick_sort(arr, start, pivot, k);
		return find_kth_smallest_using_quick_sort(arr, pivot + 1, end, k);
	}

	return -1;
}

int kth_smallest_element(int *arr, const int n, const int k)
{
	return find_kth_smallest_using_quick_sort(arr, 0, n - 1, k);
}

int main(void)
{
	int t;
	scanf_s("%d", &t);

	while (t--)
	{
		int n, k, ans;
		scanf_s("%d", &n);
		scanf_s("%d", &k);

		int *arr = (int *)calloc(n, sizeof(int));

		for (int i = 0; i < n; i++)
			scanf_s("%d", &arr[i]);

		if ((ans = kth_smallest_element(arr, n, k)) != -1)
			printf("Kth smallest element is: %d\n", arr[ans]);
		else
			printf("Kth smallest element is not found.\n");

		free(arr);
	}

	return 0;
}