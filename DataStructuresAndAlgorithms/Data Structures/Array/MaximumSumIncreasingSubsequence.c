/*
	Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.

	Input:
	The first line of input contains an integer T denoting the number of test cases.
	The first line of each test case is N(the size of array).
	The second line of each test case contains array elements.

	Output:
	For each test case print the required answer in new line.

	Constraints:
	1 ≤ T ≤ 100
	1 ≤ N ≤ 106
	1 ≤ Ai ≤ 106

	Example:
	Input:
	2
	7
	1 101 2 3 100 4 5
	4
	10 5 4 3

	Output:
	106
	10

	Explanation:
	Test-case 1: All the increasing sub sequences are : (1,101); (1,2,3,100); (1,2,3,4,5).
	Out of these (1, 2, 3, 100) has maximum sum,i.e., 106.
*/

#include <stdio.h>
#include <stdlib.h>

// Algorithm: Dynamic Programming
int find_max_sum_increasing_subsequence(const int *arr, const int n)
{
	int *t = (int *)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
		t[i] = arr[i];

	int max = t[0];

	for (int i = 1; i < n; i++)
	{		
		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i])
				t[i] = max(t[i], arr[i] + t[j]);

		max = max(max, t[i]);
	}

	free(t);
	return max;
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

		printf("Maximum sum increasing sub-sequence is: %d\n", find_max_sum_increasing_subsequence(arr, n));

		free(arr);
	}
}