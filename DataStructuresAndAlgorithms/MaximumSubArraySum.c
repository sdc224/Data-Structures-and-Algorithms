// Given an array of n numbers, the task is to calculate the maximum sub array sum
// i.e. the largest possible sum of a sequence of consecutive values in the array.
// The problem is interesting when there may be negative values in the array.
// We assume that an empty sub array is allowed, so the maximum sub array is always 0

#include <stdio.h>
#include <stdlib.h>

// Algorithm 1 : Go through all possible sub arrays, calculate the sum of values in each
//				 sub array and maintain the maximum sum.
// Time complexity O(n3)

int algorithm1(const int array[], const int n)
{
	int best = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int sum = 0;
			for (int k = i; k <= j; k++)
			{
				sum += array[k];
				best = max(best,sum);
			}
		}
	}

	return best;
}

// Algorithm 2: Calculating the sum at the same time when the right end of the sub array moves.
// Time Complexity O(n2)

int algorithm2(const int array[], const int n)
{
	int best = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += array[j];
			best = max(best, sum);
		}
	}
	return best;
}

// Algorithm 3: Calculating the maximum sub array sum for each ending position from left to right
// Time Complexity O(n)

int algorithm3(const int array[], const int n)
{
	int sum = 0, best = 0;

	for (int i = 0; i < n; i++)
	{
		sum = max(array[i], sum + array[i]);
		best = max(best, sum);
	}

	return best;
}

int main(void)
{
	int array[] = {-1, 2, 4, 3, -1, 6, 9};
	const int n = sizeof array / sizeof array[0];
	printf("The maximum sub array sum (at O(n3)) is: %d\n", algorithm1(array, n));
	printf("The maximum sub array sum (at O(n2)) is: %d\n", algorithm2(array, n));
	printf("The maximum sub array sum (at O(n)) is: %d\n", algorithm3(array, n));
	return 0;
}