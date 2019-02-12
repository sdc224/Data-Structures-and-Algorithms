#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;

	printf("Enter no of elements: ");
	scanf_s("%d", &n);

	int *arr = (int *)calloc(n, sizeof(int));

	printf("Enter elements: ");
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);

	printf("\nSub-arrays are...\n");
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			for (int k = i; k <= j; k++)
				printf("%d ", arr[k]);

			printf("\n");			
		}

	free(arr);
}
