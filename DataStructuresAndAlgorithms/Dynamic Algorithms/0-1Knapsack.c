#include<stdio.h>

/**
 * \brief 
 */
typedef struct knapsack
{
	char item;
	int value;
	int weight;
}knapsack;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

void print_knapsack(knapsack zero_one[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Item: %c\tValue: %d\tWeight: %d\n", zero_one[i].item, zero_one[i].value, zero_one[i].weight);
	}
	printf("\n");
}

int knapsack0_1(knapsack zero_one[], int weight[], int value[], const int n, const int knapsack_capacity)
{
	if (knapsack_capacity == 0 || n == 0)
		return 0;

	if (zero_one[n - 1].weight > knapsack_capacity)
		return knapsack0_1(zero_one, zero_one[n - 1].weight, zero_one[n - 1].value, n - 1, knapsack_capacity);
	return (max(
		zero_one[n - 1].value + knapsack0_1(zero_one, zero_one[n - 1].weight, zero_one[n - 1].value, n - 1,
		                                    knapsack_capacity - zero_one[n - 1].weight),
		knapsack0_1(zero_one, zero_one[n - 1].weight, zero_one[n - 1].value, n - 1, knapsack_capacity)));
}

int main()
{
	knapsack zero_one[] = { { 'A', 60, 10 }, { 'B', 100, 20 }, { 'C', 120, 30 } };
	const int size = (sizeof(zero_one) / sizeof(zero_one[0]));
	print_knapsack(zero_one, size);
	int Capacity;
	printf("Enter maximum capacity for Knapsack: ");
	scanf_s("%d", &Capacity);
	const int max_value = knapsack0_1(zero_one, zero_one[size].weight, zero_one[size].value, size, Capacity);
	printf("Maximum Value for the Knapsack is: %d\n", max_value);
	return 0;
}