/*
	Given an array A of positive integers of size N,
	where each value represents number of chocolates in a packet.
	Each packet can have variable number of chocolates.
	There are M students, the task is to distribute chocolate packets such that :
	1. Each student gets one packet.
	2. The difference between the number of chocolates given to the students
	having packet with maximum chocolates and student having packet with minimum chocolates is minimum.

	Input:
	The first line of input contains an integer T, denoting the number of test cases.
	Then T test cases follow. Each test case consists of three lines.
	The first line of each test case contains an integer N denoting the number of packets.
	Then next line contains N space separated values of the array A denoting the values of each packet.
	The third line of each test case contains an integer m denoting the no of students.

	Output:
	For each test case in a new line print the minimum difference.

	Constraints:
	1 <= T <= 100
	1 <= N <= 107
	1 <= Ai <= 1018
	1 <= M <= N

	Example:
	Input:
	2
	8
	3 4 1 9 56 7 9 12
	5
	7
	7 3 2 4 9 12 56
	3

	Output:
	6
	2

	Explanation:
	Test-case 1: The minimum difference between maximum chocolates and minimum chocolates is 9-3=6
 */

#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

// Time Complexity - O(nlogn)
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

		int k;
		scanf_s("%d", &k);

		if (n < k)
		{
			printf("Students shouldn\'t be greater than packets!\n");
			return 0;
		}

		quick_sort(arr, n);

		int minimum_difference = INT_MAX;

		for (int i = 0; i < n - k; i++)
		{
			const int difference = arr[i + k - 1] - arr[i];

			if (minimum_difference > difference)
				minimum_difference = difference;
		}

		printf("%d\n", minimum_difference);

		free(arr);
	}

	return 0;
}