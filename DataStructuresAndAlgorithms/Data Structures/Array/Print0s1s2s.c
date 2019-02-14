/*
	Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

	Input:
	The first line contains an integer 'T' denoting the total number of test cases.
	Then T test-cases follow. Each test-cases contains two lines of input.
	The first line denotes the size of the array N.
	The second lines contains the elements of the array A separated by spaces.

	Output: 
	For each test-case, print the sorted array.

	Constraints: 
	1 <= T <= 500
	1 <= N <= 106
	0 <= Ai <= 2

	Example:
	Input :
	2
	5
	0 2 1 2 0
	3
	0 1 0

	Output:
	0 0 1 2 2
	0 0 1

	Explanation:
	Test-case 1: After segregating the 0s, 1s and 2s, we have 0 0 1 2 2 which shown in the output.
*/

#include <stdio.h>
#include <stdlib.h>

void sort_0_1_2(int *arr, const int n)
{
	int no_of_zero = 0, no_of_one = 0, no_of_two = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
			no_of_zero++;

		if (arr[i] == 1)
			no_of_one++;

		if (arr[i] == 2)
			no_of_two++;
	}

	for (int i = 0; i < no_of_zero; i++)
		arr[i] = 0;

	for (int i = no_of_zero; i < no_of_one; i++)
		arr[i] = 1;

	for (int i = no_of_one; i < no_of_two; i++)
		arr[i] = 2;
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

		sort_0_1_2(arr, n);

		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);

		printf("\n");

		free(arr);
	}
	
	return 0;
}
