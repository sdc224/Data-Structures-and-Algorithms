/*
	Given an unsorted array of size N. 
	Find the first element in array such that
	all of its left elements are smaller and all right elements to it are greater than it.

	Note: Left and right side elements can be equal to required element.
	And extreme elements cannot be required element.

	Input:
	The first line of input contains an integer T denoting the number of test cases.
	Then T test cases follow. Each test case consists of two lines.
	First line of each test case contains an Integer N denoting size of array
	and the second line contains N space separated array elements.

	Output:
	For each test case, in a new line print the required element.
	If no such element present in array then print -1.

	Constraints:
	1 <= T <= 100
	3 <= N <= 106
	1 <= A[i] <= 106

	Example:
	Input:
	3
	4
	4 2 5 7
	3
	11 9 12
	6
	4 3 2 7 8 9

	Output:
	5
	-1
	7
	Explanation:
	Test-case 1 : Elements on left of 5 are smaller than 5 and on right of it are greater than 5.
 */

#include <stdio.h>
#include <stdlib.h>

// Algorithm :
// Time Complexity - O(n^2)
// Space Complexity - O(1)
int find_element(int arr[], const int n)
{
	for (int i = 1; i < n - 1; i++)
	{
		int j = i - 1;
		int k = i + 1;

		while (arr[j] <= arr[i] && arr[k] >= arr[i])
		{
			if (j == 0 && k == n - 1)
				return arr[i];

			if (j > 0)
				j--;

			if (k < n - 1)
				k++;
		}
	}

	// If not found
	return -1;
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

		printf("%d\n", find_element(arr, n));

		free(arr);
	}

	return 0;
}