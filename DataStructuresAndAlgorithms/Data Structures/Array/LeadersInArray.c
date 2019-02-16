/*
	Given an array of positive integers. Your task is to find the leaders in the array.
	Note: An element of array is leader if it is greater than or equal to all the elements to its right side.
	Also, the rightmost element is always a leader. 

	Input:
	The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
	The first line of each test case contains a single integer N denoting the size of array.
	The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

	Output:
	Print all the leaders.

	Constraints:
	1 <= T <= 100
	1 <= N <= 107
	0 <= Ai <= 1018

	Example:
	Input:
	3
	6
	16 17 4 3 5 2
	5
	1 2 3 4 0
	5
	7 4 5 7 3
	Output:
	17 5 2
	4 0
	7 7 3

	Explanation:
	Test-case 3: All elements on the right of 7 (at index 0) are smaller than or equal to 7.
	Also, all the elements of right side of 7 (at index 3) are smaller than 7.
	And, the last element 3 is itself a leader since no elements are on its right.
*/

#include <stdio.h>
#include <stdlib.h>

// Logic
// Find max from the right side of the array and print
void print_leaders(const int *arr, const int n)
{
	int max_from_right = arr[n - 1];
	printf("%d, ", max_from_right);

	for (int i = n - 2; i >= 0; --i)
	{
		if (max_from_right <= arr[i])
		{
			max_from_right = arr[i];
			printf("%d, ", max_from_right);
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

		printf("Leaders of the array: {");
		print_leaders(arr, n);
		printf("\b\b}\n");

		free(arr);
	}

	return 0;
}