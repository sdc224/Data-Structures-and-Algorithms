/*
	Given an array A and an integer K. Find the maximum for each and every contiguous sub-array of size K.

	Input:
	The first line of input contains an integer T denoting the number of test cases.
	The first line of each test case contains a single integer N denoting the size of array and the size of sub-array K. 
	The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

	Output:
	Print the maximum for every sub-array of size k.

	Constraints:
	1 ≤ T ≤ 200
	1 ≤ N ≤ 107
	1 ≤ K ≤ N
	0 ≤ A[i] <= 107

	Example:
	Input:
	2
	9 3
	1 2 3 1 4 5 2 3 6
	10 4
	8 5 10 7 9 4 15 12 90 13

	Output:
	3 3 4 5 5 5 6
	10 10 10 15 15 90 90

	Explanation:
	Test-case 1: Starting from first sub-array of size k = 3,
	we have 3 as maximum. Moving the window forward, 
	maximum element are as 3, 4, 5, 5, 5 and 6.
*/

#include <stdio.h>
#include <stdlib.h>

// Algorithm : Simple
// Time complexity: O(n ^ 2)
void print_max_of_sub_array_of_size_k(const int *arr, const int n, int k)
{
	for (int i = 0; i <= n - k; i++)
	{
		int max = arr[i];

		for (int j = i + 1; j < i + k; j++)
		{
			if (arr[j] > max)
				max = arr[j];
		}

		printf("%d ", max);
	}
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

		printf("Max of sub array of size %d is....\n", k);
		print_max_of_sub_array_of_size_k(arr, n, k);
		printf("\n");

		free(arr);
	}

	return 0;
}