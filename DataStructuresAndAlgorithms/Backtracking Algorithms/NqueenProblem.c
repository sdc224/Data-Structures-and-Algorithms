#include <math.h>
#include <stdio.h>

//board[] is taken for storing the solutions, count for counting the solution
int board[20], count = 0;

/**
 * \brief Print Fuction for creating the Board
 * \param n No of rows or columns
 */
void print(const int n)
{
	printf("\n\nSolution %d:\n\n", ++count);

	for (int i = 1; i <= n; i++)
		printf("\t%d", i);

	for (int i = 1; i <= n; i++)
	{
		printf("\n\n%d", i);
		for (int j = 1; j <= n; j++)
		{
			if (board[i] == j)
				printf("\tQ");
			else
				printf("\t-");
		}
	}
}

int place(const int row, const int column)
{
	for (int i = 1; i <= row - 1; i++)
	{
		if (board[i] == column)
			return 0;
		if (abs(board[i] - column) == abs(i - row))
			return 0;
	}
	return 1;
}

void n_queen(const int row, const int n)
{
	for (int j = 1; j <= n; j++)
	{
		if (place(row, j))
		{
			board[row] = j;
			if (row == n)
				print(n);
			else
				n_queen(row + 1, n);
		}
	}
}

int main()
{
	n_queen(1, 8);
	return 0;
}