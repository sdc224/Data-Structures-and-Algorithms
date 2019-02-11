#include<stdio.h>

int true = 1, false = 0;
int answer[50], weight[50], sum, n;

//Utility Function
int find_to_add(const int i, const int wt, const int total)
{
	return wt + total >= sum && (wt == sum || wt + weight[i + 1] <= sum);
}

//Utility Function for sorting(Bubble)
void sorting()
{
	int swapped = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
			if (weight[j] > weight[j + 1])
			{
				const int temp = weight[j];
				weight[j] = weight[j + 1];
				weight[j + 1] = temp;
				swapped = 1;
			}
		if (swapped == 0)
			break;
	}
}

void sumset(const int i, const int wt, const int total)
{
	if (find_to_add(i, wt, total))
	{
		if (wt == sum)
		{
			printf("\n{\t");
			for (int j = 0; j <= i; j++)
				if (answer[j])
					printf("%d\t", weight[j]);
			printf("}\n");
		}
		else
		{
			answer[i + 1] = true;
			sumset(i + 1, wt + weight[i + 1], total - weight[i + 1]);
			answer[i + 1] = false;
			sumset(i + 1, wt, total - weight[i + 1]);
		}
	}
}

int main()
{
	int i, n, total = 0;
	printf("\n Enter how many numbers:\n");
	scanf_s("%d", &n);
	printf("\n Enter %d numbers to th set:\n", n);
	for (i = 0; i<n; i++) {
		scanf_s("%d", &weight[i]);
		total += weight[i];
	}
	printf("\n Input the sum value to create sub set:\n");
	scanf_s("%d", &sum);

	//Sorting Part
	/*sorting();
	printf("\n The given %d numbers in ascending order:\n", n);
	for (i = 0; i<n; i++)
		printf("%d \t", w[i]);*/

	if (total<sum)
		printf("\n Subset construction is not possible");
	else
	{
		for (i = 0; i<n; i++)
			answer[i] = 0;
		printf("\n The solution using backtracking is:\n");
		sumset(-1, 0, total);
	}
}