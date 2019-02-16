/*
	Given an array A of N positive integers. Print the maximum sum increasing subsequence of the given array.

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
	{1, 2, 3, 100}
	{10}

	Explanation:
	Test-case 1: All the increasing sub sequences are : (1,101); (1,2,3,100); (1,2,3,4,5).
	Out of these (1, 2, 3, 100) has maximum sum,i.e., 106.
*/

#include <stdio.h>
#include <stdlib.h>

void print_array_recursive(const int *arr, const int *index, int k, int status)
{
	if (status == 1)
		return;

	if (k == 0)
		status++;

	print_array_recursive(arr, index, index[k], status);

	printf("%d, ", arr[k]);
}

// Algorithm: Dynamic Programming
void print_max_sum_increasing_subsequence(const int *arr, const int n)
{
	int k = 0;
	int *t = (int *)calloc(n, sizeof(int));
	int *index = (int *)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		t[i] = arr[i];
		index[i] = 0;
	}

	int max = t[0];

	for (int i = 1; i < n; i++)
	{		
		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i])
			{
				if (t[i] < arr[i] + t[j])
				{
					t[i] = arr[i] + t[j];
					index[i] = j;
				}
			}

		if (max < t[i])
		{
			max = t[i];
			k = i;
		}
	}
	
	printf("{");
	print_array_recursive(arr, index, k, 0);
	printf("\b\b}\n");

	free(t);
	free(index);
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

		printf("Maximum sum increasing sub-sequence is...\n");
		print_max_sum_increasing_subsequence(arr, n);

		free(arr);
	}
}