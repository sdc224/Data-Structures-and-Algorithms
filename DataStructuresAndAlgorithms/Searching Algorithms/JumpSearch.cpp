#include <bits/stdc++.h>
using namespace std;

/**
 * \brief 
 * \param arr 
 * \param n 
 * \param searching_element 
 * \return 
 */
int jump_search(const int arr[], const int n, const int searching_element)
{
	auto step = static_cast<int>(sqrt(n));

	auto prev = 0;
	while (arr[min(step, n) - 1] < searching_element)
	{
		prev = step;
		step += static_cast<int>(sqrt(n));
		if (prev >= n)
			return -1;
	}

	while (arr[prev] < searching_element)
	{
		prev++;

		if (prev == min(step, n))
			return -1;
	}

	if (arr[prev] == searching_element)
		return prev;

	return -1;
}

int main()
{
	int arr[] = { 10, 7, 8, 4, 3, 11, 7, 2, 5, 17, 14, 22, 13 };
	const int n = sizeof arr / sizeof arr[0];
	sort(arr, arr + n);
	const auto key = jump_search(arr, n, 11);
	cout << key << endl;
	return 0;
}
