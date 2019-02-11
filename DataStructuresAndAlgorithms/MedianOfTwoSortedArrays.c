// We have to find median of two arrays.
// For e.g. if two arrays array1 is {1, 12, 15, 26, 38}
// and array2 is {2, 13, 17, 30, 45}
// For first array, median is 15 and second array, median is 17
// So median for bot of the two arrays after joining them is 16

#include <stdio.h>
#include <stdlib.h>

/*
	1) Calculate the medians m1 and m2 of the input arrays ar1[] 
	   and ar2[] respectively.
	2) If m1 and m2 both are equal then we are done.
	     return m1 (or m2)
	3) If m1 is greater than m2, then median is present in one 
	   of the below two sub arrays.
	    a)  From first element of ar1 to m1 (ar1[0...|_n/2_|])
	    b)  From m2 to last element of ar2  (ar2[|_n/2_|...n-1])
	4) If m2 is greater than m1, then median is present in one    
	   of the below two sub arrays.
	   a)  From m1 to last element of ar1  (ar1[|_n/2_|...n-1])
	   b)  From first element of ar2 to m2 (ar2[0...|_n/2_|])
	5) Repeat the above process until size of both the sub arrays 
	   becomes 2.
	6) If size of the two arrays is 2 then use below formula to get 
	  the median.
	    Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
 */

int median(int arr[], const int n)
{
	if (n % 2 == 0)
		return (arr[n / 2] + arr[n / 2 - 1]) / 2;
	else
		return arr[n / 2];
}

int get_median(int arr1[], int arr2[], const int n)
{
	if (n <= 0)
		return -1;

	if (n == 1)
		return (arr1[0] + arr2[0]) / 2;

	if (n == 2)
		return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2;

	const int median1 = median(arr1, n);
	const int median2 = median(arr2, n);

	if (median1 == median2)
		return median1;

	if (median1 < median2)
	{
		if (n % 2 == 0)
			return get_median(arr1 + n / 2 - 1, arr2, n - n / 2 + 1);
		return get_median(arr1 + n / 2, arr2 , n - n / 2);
	}

	if (n % 2 == 0)
		return get_median(arr2 + n / 2 - 1, arr1, n - n / 2 + 1);
	return get_median(arr2 + n /2, arr1, n - n / 2);
}

int main(void)
{
	int ar1[] = { 1, 2, 3, 6 }; 
    int ar2[] = { 4, 6, 8, 10 };
	const int n1 = sizeof ar1 / sizeof ar1[0];
	const int n2 = sizeof ar2 / sizeof ar2[0];

    if (n1 == n2) 
        printf("Median is %d\n", get_median(ar1, ar2, n1)); 
    else
        printf("Doesn't work for arrays of unequal size\n");

    return 0; 
}