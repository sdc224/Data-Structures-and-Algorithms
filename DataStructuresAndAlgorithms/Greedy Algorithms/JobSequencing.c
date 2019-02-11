#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct job
{
	char id;
	int deadline;
	int profit;
} job;

/**
 * \brief 
 * \param job1 
 * \param n 
 */
void insertion_sort(job job1[], const int n)
{
	for (int i = 1; i < n; i++)
	{
		const int key = job1[i].profit;
		const char temp = job1[i].id;
		const int temp2 = job1[i].deadline;
		int j = i - 1;

		while (j >= 0 && job1[j].profit < key)
		{
			job1[j + 1].profit = job1[j].profit;
			job1[j + 1].id = job1[j].id;
			job1[j + 1].deadline = job1[j].deadline;
			j--;
		}

		job1[j + 1].profit = key;
		job1[j + 1].id = temp;
		job1[j + 1].deadline = temp2;
	}
}

/*
 * | 2 | 1 | 1 | 3 | 2 | deadline days
 * | 20 | 27 | 10 | 15 | 6 | profit
 * 
 * After sorting
 * | 1 | 2 | 3 | 1 | 2 |
 * | 27 | 20 | 15 | 10 | 6 |
 * 
 * Creating a seperate array to store the result and also to store the free time slot
 * 0 1 2 3 4 5
 * 27 20 15
 * result is 27+20+15
 */

void job_scheduling(job job1[], const int n)
{
	insertion_sort(job1, n);								//Sorted the job sequence in terms of profit

	int result[MAX];										//For storing the result
	int slot[MAX];											//For storing the free time slot

	//All are free slots
	for (int i = 0; i < n; i++)
		slot[i] = 0;

	//Iterating in the sorted job schedule
	for (int i = 0; i < n; i++)
		for (int j = min(job1[i].deadline, n) - 1; j >= 0; j--)
			if (slot[j] == 0)
			{
				result[j] = i;
				slot[j] = 1;
				break;
			}

	int sum = 0;											//For storing the maximum profit

	printf("The sequence is: \n");
	for (int i = 0; i < n; i++)
		if (slot[i])
		{
			printf("Id: %c\nProfit: %d\n", job1[result[i]].id, job1[result[i]].profit);
			sum = sum + job1[result[i]].profit;
		}

	printf("\nMaximum profit is: %d\n", sum);
}

int main()
{
	printf("\nJob Scheduling problem.....\n");
	job job1[] = {
		{'a', 5, 200}, {'b', 2, 300}, {'c', 3, 400}, {'d', 7, 500}, {'e', 1, 600}, {'f', 2, 700}, {'g', 4, 250},
		{'h', 6, 450}, {'i', 7, 550}, {'j', 5, 650}, {'k', 3, 240}, {'l', 4, 440}
	};
	const int n = sizeof job1 / sizeof job1[0];
	job_scheduling(job1, n);
	return 0;
}