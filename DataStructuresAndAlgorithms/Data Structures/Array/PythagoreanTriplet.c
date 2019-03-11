/*
	Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.

	Input:
	The first line contains T, denoting the number of test-cases.
	Then follows description of test-cases.
	Each case begins with a single positive integer N denoting the size of array.
	The second line contains the N space separated positive integers denoting the elements of array A.

	Output:
	For each test-case, print "Yes" or  "No" whether it is Pythagorean Triplet or not (without quotes).

	Constraints:
	1 <= T <= 100
	1 <= N <= 107
	1 <= A[i] <= 1000

	Example:
	Input:
	1
	5
	3 2 4 6 5

	Output:
	Yes

	Explanation:
	Test-case 1: a=3, b=4, and c=5 forms a pythagorean triplet, so we print "Yes"
 */

#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

// Time Complexity: O(n2)
int is_pythagorean_triplet(int *arr, const int n)
{
	// Square of all elements
	for (int i = 0; i < n; i++)
		arr[i] *= arr[i];

	// Sort all the elements in increasing order
	quick_sort(arr, n);

	// Fixing last element as 'a'
	for (int i = n - 1; i >= 2; i--)
	{		
		int left = 0;
		int right = i - 1;

		// trying to find b and c from elements before a, as the array is sorted
		while (left < right)
		{
			if (arr[left] + arr[right] == arr[i])
				return 1;

			arr[left] + arr[right] < arr[i] ? left++ : right--;
		}
	}

	return 0;
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

		if (is_pythagorean_triplet(arr, n))
			printf("Yes\n");
		else
			printf("No\n");

		free(arr);
	}

	return 0;
}