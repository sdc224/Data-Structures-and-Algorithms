#include "swap_integers.h"
#include "sorting.h"

int helper_arr[50];

void bubble_sort(int arr[], const int n) 
{
	int swapped = 0;
	
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i < n - j - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
				swapped = 1;
			}
		}

		if (swapped == 0)
			break;
	}
}

void selection_sort(int arr[], const int n) 
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_pos = i;
		for (int j = i+1; j < n; j++)
		{
			if (arr[j] < arr[min_pos])
			{
				min_pos = j;
			}
		}

		swap(&arr[i], &arr[min_pos]);
	}
}

int binary_search(int a[], const int start, const int end, const int val)
{
	if (end <= start)
	{
		if (val > a[start])
			return start + 1;
		return start;
	}
	
	const int mid = (start + end) / 2;

	if (a[mid] == val)
		return mid + 1;
	if (a[mid] < val)
		return binary_search(a, mid + 1, end, val);
	return binary_search(a, start, mid - 1, val);
}

void insertion_sort(int arr[], const int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		const int key = arr[i];
		const int location = binary_search(arr, 0, j, key);
		while (j >= location && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
}

void merge(int arr[], const int start, const int mid, const int end)
{
	int i = start, j = mid + 1, k = start;	
	
	while (i <= mid && j <= end)
	{
		if (arr[i] < arr[j])
			helper_arr[k] = arr[i++];
		else
			helper_arr[k] = arr[j++];
		
		k++;
	}

	while (i <= mid)
		helper_arr[k++] = arr[i++];

	while (j <= end)
		helper_arr[k++] = arr[j++];

	for (i = start; i < k; i++)
		arr[i] = helper_arr[i];
}

void merge_sort_helper(int arr[], const int start, const int end)
{
	if (start < end)
	{
		const int mid = (start + end) / 2;

		merge_sort_helper(arr, start, mid);
		merge_sort_helper(arr, mid + 1, end);

		merge(arr, start, mid, end);
	}
}

void merge_sort(int arr[], const int n)
{
	merge_sort_helper(arr, 0, n - 1);
}

int partition(int arr[], const int start, const int end)
{
	const int pivot = arr[end];
	int j = start - 1;

	for (int i = start; i < end; i++)
	{		
		if (arr[i] <= pivot)
		{
			j++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[j + 1], &arr[end]);
	return j + 1;
}

void quick_sort_helper(int arr[], const int start, const int end)
{
	if (start < end)
	{
		const int pivot_index = partition(arr, start, end);
		quick_sort_helper(arr, start, pivot_index - 1);
		quick_sort_helper(arr, pivot_index + 1, end);
	}
}

void quick_sort(int arr[], const int n)
{
	quick_sort_helper(arr, 0, n - 1);
}

void max_heap(int arr[], const int n, const int root)
{
	const int left = 2 * root + 1;
	const int right = 2 * root + 2;
	int max_value_node = root;

	if (arr[left] > arr[max_value_node])
		max_value_node = left;
	if (arr[right] > arr[max_value_node])
		max_value_node = right;

	if (max_value_node != root && max_value_node < n)
	{
		swap(&arr[max_value_node], &arr[root]);
		max_heap(arr, n, max_value_node);
	}
}

void build_heap(int arr[], const int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		max_heap(arr, n, i);
	}
}

void heap_sort(int arr[], const int n)
{
	build_heap(arr, n);
	for (int i = n-1; i >= 0; i--)
	{
		swap(&arr[i], &arr[0]);
		max_heap(arr, i, 0);
	}
}