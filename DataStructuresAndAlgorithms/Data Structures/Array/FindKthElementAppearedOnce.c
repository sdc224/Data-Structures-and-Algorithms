// Write your question here

#include <stdio.h>
#include <stdlib.h>

// Write all your functions here

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

		free(arr);
	}

	return 0;
}