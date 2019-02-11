#include<stdio.h>

typedef struct Knapsack
{
	char item;
	float value;
	float weight;
	float ratio;
}Knapsack;

void swap(float *x, float *y)
{
	float temp = *x;
	*x = *y;
	*y = temp;
}

void swapChar(char x, char y)
{
	char temp = x;
	x = y;
	y = temp;
}

void printKnapsack(Knapsack fractional[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Item: %c\tValue: %0.0f\tWeight: %0.0f\n", fractional[i].item, fractional[i].value, fractional[i].weight);
	}
	printf("\n");
}

void BubbleSort(Knapsack fractional[], int n)
{
	int i, j, swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (fractional[j].ratio < fractional[j + 1].ratio)
			{
				swap(&fractional[j].ratio, &fractional[j + 1].ratio);
				swap(&fractional[j].weight, &fractional[j + 1].weight);
				swap(&fractional[j].value, &fractional[j + 1].value);
				swapChar(fractional[j].item, fractional[j + 1].item);
				swapped = 1;
			}
		}

		if (swapped = 0)
			break;
	}
}

float FractionalKnapsack(Knapsack fractional[], int n, float KnapsackCapacity)
{
	float maxValue = 0.0;
	float currentWeight = 0.0, remainingCapacity;
	BubbleSort(fractional, n);
	for (int i = 0; i < n; i++)
	{
		if (fractional[i].weight + currentWeight < KnapsackCapacity)
		{
			currentWeight += fractional[i].weight;
			maxValue += fractional[i].value;
		}
		else
		{
			remainingCapacity = KnapsackCapacity - currentWeight;
			currentWeight = KnapsackCapacity;
			maxValue += (fractional[i].value *  (remainingCapacity / fractional[i].weight));

		}
	}
	return maxValue;
}

int main()
{
	Knapsack fractional[] = { { 'A', 100, 30, 100 / 30 },{ 'B', 120, 40, 120 / 40 },{ 'C', 90, 35, 90 / 35} };
	int size = (sizeof(fractional) / sizeof(fractional[0]));
	printKnapsack(fractional, size);
	float Capacity, maxValue;
	printf("Enter maximum capacity for Knapsack: ");
	scanf_s("%f", &Capacity);
	maxValue = FractionalKnapsack(fractional, size, Capacity);
	printf("Maximum Value for the Knapsack is: %0.1f\n", maxValue);
	return 0;

}