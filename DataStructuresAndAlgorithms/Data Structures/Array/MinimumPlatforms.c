/*
	Given arrival and departure times of all trains that reach a railway station.
	Your task is to find the minimum number of platforms required for the railway station so that no train waits.
	Note: Consider that all the trains arrive on the same day and leave on the same day.
	Also, arrival and departure times must not be same for a train.

	Input:
	The first line of input contains T, the number of test cases.
	For each test case, first line will contain an integer N, the number of trains.
	Next two lines will consist of N space separated time intervals denoting arrival and departure times respectively.
	Note: Time intervals are in the 24-hour format(hh:mm), preceding zeros are insignificant. 200 means 2:00.
	Consider the example for better understanding of input.

	Output:
	For each test case, print the minimum number of platforms required for the trains to arrive and depart safely.

	Constraints:
	1 <= T <= 100
	1 <= N <= 1000
	1 <= A[i] < D[i] <= 2359

	Example:
	Input:
	1
	6 
	900  940 950  1100 1500 1800
	910 1200 1120 1130 1900 2000

	Output:
	3

	Explanation:
	Test-case 1: Minimum 3 platforms are required to safely arrive and depart all trains.
*/

#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

// Algorithm: Merge process of merge-sort
int get_minimum_platforms(int *arrival, int *departure, const int n)
{
	quick_sort(arrival, n);
	quick_sort(departure, n);

	int i = 1, j = 0, no_of_platforms = 1, result = 1;

	while (i < n && j < n)
	{
		if (arrival[i] <= departure[j])
		{
			no_of_platforms++;
			i++;

			if (result < no_of_platforms)
				result = no_of_platforms;
		}
		else
		{
			no_of_platforms--;
			j++;
		}
	}

	return result;
}

int main(void)
{
	int t;
	scanf_s("%d", &t);

	while (t--)
	{
		int n;
		scanf_s("%d", &n);

		int *arrival = (int *)calloc(n, sizeof(int));
		int *departure = (int *)calloc(n, sizeof(int));

		for (int i = 0; i < n; i++)
			scanf_s("%d", &arrival[i]);

		for (int i = 0; i < n; i++)
			scanf_s("%d", &departure[i]);

		printf("Minimum no of platforms required: %d\n", get_minimum_platforms(arrival, departure, n));

		free(departure);
		free(arrival);
	}

	return 0;
}