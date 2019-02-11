/*
	Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number.

	Input:
	The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
	Each test case consists of two lines. The first line of each test case is N and S, where N is the size of array and S is the sum.
	The second line of each test case contains N space separated integers denoting the array elements.

	Output:
	For each test-case, in a new line, print the starting and ending positions(1 indexing) of first such occuring sub-array
	from the left if sum equals to sub-array, else print -1.

	Constraints:
	1 <= T <= 100
	1 <= N <= 107
	1 <= Ai <= 1010

	Example:
	Input:
	2
	5 12
	1 2 3 7 5
	10 15
	1 2 3 4 5 6 7 8 9 10
	Output:
	2 4
	1 5

	Explanation : 
	Test-case 1: sum of elements from 2nd position to 4th position is 12
	Test-case 2: sum of elements from 1st position to 5th position is 15
 */

#include <stdio.h>
#include <stdlib.h>

int sub_array_with_sum(const int arr[], const int n, const int sum)
{
	int current_sum = arr[0], start = 0;

	for (int i = 1; i <= n; i++)
	{
		while (current_sum > sum && start < i - 1)
		{
			current_sum -= arr[start];
			start++;
		}

		if (current_sum == sum)
		{
			printf("Sum found from index %d to %d\n", start + 1, i);		// index are start and i - 1
			return 1;
		}

		if (i < n)
			current_sum += arr[i];
	}

	printf("Sum is not found in any of the sub-arrays\n");
	return 0;
}

int main(void)
{
	int t;
	scanf_s("%d", &t);

	while (t--)
	{
		int n, s;
		scanf_s("%d%d", &n, &s);

		int *arr = (int *)malloc(n * sizeof(int));

		for (int i = 0; i < n; i++)
			scanf_s("%d", &arr[i]);

		sub_array_with_sum(arr, n, s);

		free(arr);
	}
	
	return 0;
}
