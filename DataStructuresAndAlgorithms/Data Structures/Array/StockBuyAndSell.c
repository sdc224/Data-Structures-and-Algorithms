/*
	The cost of stock on each day is given in an array A[] of size N.
	Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

	Input: 
	First line contains number of test cases T.
	First line of each test case contains an integer value N denoting the number of days,
	followed by an array of stock prices of N days. 

	Output:
	For each test-case, output all the days with profit in a single line.
	And if there is no profit then print "No Profit".

	Constraints:
	1 <= T <= 100
	2 <= N <= 103
	0 <= Ai <= 104

	Example
	Input:
	2
	7
	100 180 260 310 40 535 695
	10
	23 13 25 29 33 19 34 45 65 67

	Output:
	(0 3) (4 6)
	(1 4) (5 9)

	Explanation:
	Test-case 1: We can buy stock on day 0, and sell it on 3rd day, which will give us maximum profit.

	Note: Output format is as follows - (buy_day sell_day) (buy_day sell_day)
	For each input, output should be in a single line.
 */

#include <stdio.h>
#include <stdlib.h>

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

		int buy_day = -1, sell_day = 0;

		// Time Complexity - Omega(n)
		// O(n^2)

		for (int i = 0; i < n - 1; i = sell_day)
		{			
			if (arr[i + 1] > arr[i])
			{
				buy_day = i;
				sell_day = i + 1;				

				int j = i + 1;

				while (j != n - 1)
				{
					if (arr[j + 1] < arr[j])
						break;

					sell_day++;
					j++;
				}

				if (buy_day != sell_day || buy_day != -1)
				{
					printf("(%d %d) ", buy_day, sell_day);
				}
			}

			sell_day++;
		}

		if (buy_day == -1)
		{
			printf("No Profit");
		}

		printf("\n");

		free(arr);
	}

	return 0;
}