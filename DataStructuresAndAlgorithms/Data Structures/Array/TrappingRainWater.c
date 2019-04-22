// Write your question here
/*
Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.
Examples:

Input: arr[]   = {2, 0, 2}
Output: 2
Structure is like below
| |
|_|
We can trap 2 units of water in the middle gap.

Input: arr[]   = {3, 0, 0, 2, 0, 4}
Output: 10
Structure is like below
     |
|    |
|  | |
|__|_| 
We can trap "3*2 units" of water between 3 an 2,
"1 unit" on top of bar 2 and "3 units" between 2 
and 4.  See below diagram also.

Input: arr[] = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Output: 6
       | 
   |   || |
_|_||_||||||
Trap "1 unit" between first 1 and 2, "4 units" between
first 2 and 3 and "1 unit" between second last 1 and last 2 
 */

#include <stdio.h>
#include <stdlib.h>

// Write all your functions here
// Algorithm : 
/*
An element of array can store water if there are higher bars on left and right.
We can find amount of water to be stored in every element
by finding the heights of bars on left and right sides.
The idea is to compute amount of water that can be stored in every element of array.
For example, consider the array {3, 0, 0, 2, 0, 4},
we can store two units of water at indexes 1 and 2, and one unit of water at index 2.

A Simple Solution is to traverse every array element and find the highest bars on left and right sides.
Take the smaller of two heights.
The difference between smaller height and height of current element is
the amount of water that can be stored in this array element.
Time complexity of this solution is O(n2).

An Efficient Solution is to pre-compute highest bar on left and right of every bar in O(n) time.
Then use these pre-computed values to find the amount of water in every array element.
 */
int trapping_rain_water(const int arr[], const int n)
{
	int collected_water = 0;
	
	int *left = (int *)calloc(n, sizeof(int));
	int *right = (int *)calloc(n, sizeof(int));

	left[0] = arr[0];
	for (int i = 1; i < n; i++)
		left[i] = max(left[i - 1], arr[i]);

	right[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
		right[i] = max(right[i + 1], arr[i]);

	for (int i = 0; i < n; i++)
		collected_water += min(left[i], right[i]) - arr[i];

	free(left);
	free(right);

	return collected_water;
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

		printf("Maximum water that can be retained is: %d\n", trapping_rain_water(arr, n));

		free(arr);
	}

	return 0;
}