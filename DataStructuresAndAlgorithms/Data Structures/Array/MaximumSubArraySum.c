/*
	Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

	Input:
	The first line of input contains an integer T denoting the number of test cases.
	The description of T test cases follows.
	The first line of each test case contains a single integer N denoting the size of array.
	The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

	Output:
	Print the maximum sum of the contiguous sub-array in a separate line for each test case.

	Constraints:
	1 ≤ T ≤ 100
	1 ≤ N ≤ 106
	-107 ≤ A[i] <= 107

	Example:
	Input
	2
	5
	1 2 3 -2 5
	4
	-1 -2 -3 -4
	Output
	9
	-1

	Explanation:
	Test-case 1: Max sub-array sum is 6 of elements (1, 2, 3) which is a contiguous sub-array.
*/

#include <stdio.h>
#include <stdlib.h>

// This logic works only for non negative input
int max_sub_array_sum(const int arr[], const int n)
{
	int sum = arr[0], start = 0;
	int current_sum = arr[0];

	for (int i = 1; i <= n; i++)
	{		
		if (current_sum > sum)
			sum = current_sum;

		while (current_sum < sum && start < i - 1)
		{
			current_sum -= arr[start];
			start++;
		}

		if (i < n)
			current_sum += arr[i];
	}
		
	return sum;
}

int main(void)
{
	int t;
	scanf_s("%d", &t);

	while (t--)
	{
		int n;
		scanf_s("%d", &n);

		int *arr = (int *)malloc(n * sizeof(int));

		for (int i = 0; i < n; i++)
			scanf_s("%d", &arr[i]);

		printf("Max Sub array sum = %d\n", max_sub_array_sum(arr, n));

		free(arr);
	}
	
	return 0;
}