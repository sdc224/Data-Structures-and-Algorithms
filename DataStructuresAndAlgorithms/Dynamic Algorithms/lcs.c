#include<stdio.h>
#include<string.h>

int lengthOfLcs[50][50];
char print_lcs[50];

int maxInt(int a, int b)
{
	return a > b ? a : b;
}

void lcs(char *x, char *y, int m, int n)
{
	//Counting The length of LCS
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				lengthOfLcs[i][j] = 0;
			else if (x[i - 1] == y[j - 1])
				lengthOfLcs[i][j] = lengthOfLcs[i - 1][j - 1] + 1;
			else
				lengthOfLcs[i][j] = maxInt(lengthOfLcs[i - 1][j], lengthOfLcs[i][j - 1]);
		}
	}
	//To print LCS
	int pos_idx = lengthOfLcs[m][n];
	print_lcs[pos_idx] = '\0';									//String terminator

	int i = m, j = n;
	while (i > 0 && j > 0)
	{		
		if (x[i - 1] == y[j - 1])								//if character in first[] and second[] are same
		{
			print_lcs[pos_idx - 1] = x[i - 1];					//printing matched character
			i--;
			j--;
			pos_idx--;
		}
		else if (lengthOfLcs[i - 1][j] > lengthOfLcs[i][j - 1])	//Finding max of two for movement
			i--;
		else
			j--;
	}

	//print lcs
	printf("LCS is: %s\n", print_lcs);
}

int main()
{
	char x[50], y[50];

	printf("Enter first string: ");
	gets(x);

	printf("Enter second string: ");
	gets(y);

	int x_length = strlen(x);
	int y_length = strlen(y);

	lcs(y, x, y_length, x_length);

	return 0;
}