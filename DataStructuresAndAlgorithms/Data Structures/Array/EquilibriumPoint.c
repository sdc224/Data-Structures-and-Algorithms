/*
	Given an array A of N positive numbers. 
	The task is to find the position where equilibrium first occurs in the array.
	Equilibrium position in an array is a position such that 
	the sum of elements	below it is equal to the sum of elements after it.

	Input:
	The first line of input contains an integer T, denoting the number of test cases.
	Then T test cases follow.
	First line of each test case contains an integer N denoting the size of the array.
	Then in the next line are N space separated values of the array A.

	Output:
	For each test case in a new line print the position at which the elements
	are at equilibrium if no equilibrium point exists print -1.

	Constraints:
	1 <= T <= 100
	1 <= N <= 106
	1 <= Ai <= 108

	Example:
	Input:
	2
	1
	1
	5
	1 3 5 2 2

	Output:
	1
	3

	Explanation:
	Test-case 1: Since its the only element hence its the only equilibrium point.
	Test-case 2: For second test case equilibrium point is at position 3 as elements below it (1+3) = elements after it (2+2).
*/

#include <stdio.h>
#include <stdlib.h>

// Algorithm 1
// Inefficient
// Time complexity 0(n ^ 2)
int find_equilibrium_point(const int *arr, const int n)
{
	int sum_of_left = 0, sum_of_right = 0;

	for (int i = 0; i < n; i++)
	{
		sum_of_left = 0;
		for (int j = 0; j < i; j++)
			sum_of_left += arr[j];

		sum_of_right = 0;
		for (int j = i + 1; j < n; j++)
			sum_of_right += arr[j];

		if (sum_of_left == sum_of_right)
			return i;
	}

	return -1;
}

int find_equilibrium_point_optimized(const int *arr, const int n)
{
	int sum_of_left = 0, sum = 0;

	for (int i = 0; i < n; i++)
		sum += arr[i];

	for (int i = 0; i < n; i++)
	{
		// Sum of right side
		sum -= arr[i];

		if (sum == sum_of_left)
			return i;

		sum_of_left += arr[i];
	}

	return -1;
}

int main(void)
{
	int t;
	scanf_s("%d", &t);

	while (t--)
	{
		int n, eq_point;
		scanf_s("%d", &n);

		int *arr = (int *)calloc(n, sizeof(int));

		for (int i = 0; i < n; i++)
			scanf_s("%d", &arr[i]);

		if ((eq_point = find_equilibrium_point_optimized(arr, n)) != -1)
			printf("Equilibrium point is at index %d\n", eq_point + 1);
		else
			printf("Equilibrium point not found\n");

		free(arr);
	}
}