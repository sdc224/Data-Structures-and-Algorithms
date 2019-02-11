#include <stdio.h>

typedef struct activity_selection
{
	char activity;
	int start;
	int end;
}as;

/**
* \brief
* \param as1
* \param n
*/
void insertion_sort(as as1[], const int n)
{
	for (int i = 1; i < n; i++)
	{
		const int key = as1[i].end;
		const char temp_activity = as1[i].activity;
		const int temp_start = as1[i].start;
		int j = i - 1;

		while (j >= 0 && as1[j].end > key)
		{
			as1[j + 1].end = as1[j].end;
			as1[j + 1].activity = as1[j].activity;
			as1[j + 1].start = as1[j].start;
			j--;
		}

		as1[j + 1].end = key;
		as1[j + 1].activity = temp_activity;
		as1[j + 1].start = temp_start;
	}
}

int main()
{
	printf("Activity Selection Problem......\n");
	as as1[] = {
		{'a', 2, 4}, {'b', 1, 5}, {'c', 4, 7}, {'d', 6, 9}, {'e', 7, 14}, {'f', 8, 11}, {'g', 9, 10}, {'h', 13, 16},
		{'i', 12, 14}, {'j', 15, 19}, {'k', 18, 20}, {'l', 17, 21}, {'m', 20, 23}, {'n', 21, 22}
	};
	const int n = sizeof as1 / sizeof as1[0];
	
	//Algorithm Part
	insertion_sort(as1, n);
	
	int last = -1;
	for (int i = 0; i < n; i++)
		if (as1[i].start >= last)
		{
			printf("%c ", as1[i].activity);
			last = as1[i].end;
		}
	
	printf("\n");
	return 0;
}