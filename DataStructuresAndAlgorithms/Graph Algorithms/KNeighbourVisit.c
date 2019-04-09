#include <stdio.h>
#include <limits.h>

long stack[3];
int top = -1;

void push(const long data)
{
	if (top == 3)
		return;

	stack[++top] = data;
}

long pop()
{
	if (top == -1)
		return INT_MIN;

	return stack[top--];
}

void clear()
{
	top = -1;
}

int is_empty()
{
	if (top == -1)
		return 1;
	return 0;
}

long min(long sum1, long sum2, long sum3)
{
	return  sum1 < sum2 ? (sum1 < sum3 ? sum1 : sum3) : sum2 < sum3 ? sum2 : sum3 ;
}

void find_min_neighbor_visit(long ha, long hb, long hc, long ab, long ac,
                             long bc)
{
	int i;
	long sum = 0, min_sum = INT_MAX;
	long ba = ab, ca = ac, cb = bc, ah = ha, bh = hb, ch = hc;
	
	// Case 1
	push(ha);
	push(ab);
	push(bh);

	while (!is_empty())
	{
		sum += pop();
	}

	if (sum < min_sum)
		min_sum = sum;

	// Case 2
	sum = 0;
	push(ha);
	push(ac);
	push(ch);

	while (!is_empty())
	{
		sum += pop();
	}

	if (sum < min_sum)
		min_sum = sum;

	// Case 3
	sum = 0;
	push(hb);
	push(bc);
	push(ch);

	while (!is_empty())
	{
		sum += pop();
	}

	if (sum < min_sum)
		min_sum = sum;

	// Case 4
	sum = 0;
	push(hb);
	push(ba);
	push(ah);

	while (!is_empty())
	{
		sum += pop();
	}

	if (sum < min_sum)
		min_sum = sum;

	// Case 5
	sum = 0;
	push(hc);
	push(ca);
	push(ah);

	while (!is_empty())
	{
		sum += pop();
	}

	if (sum < min_sum)
		min_sum = sum;

	// Case 6
	sum = 0;
	push(hc);
	push(cb);
	push(bh);

	while (!is_empty())
	{
		sum += pop();
	}

	if (sum < min_sum)
		min_sum = sum;

	sum = 0;
	const long a_path = ha * 2;
	const long b_path = hb * 2;
	const long c_path = hc * 2;

	const long sum1 = a_path + b_path;
	const long sum2 = b_path + c_path;
	const long sum3 = a_path + c_path;

	sum = min(sum1, sum2, sum3);

	if (sum < min_sum)
		min_sum = sum;

	printf("%ld", min_sum);
}

int main(void)
{
	long ha = 0, hb = 0, hc = 0, ab = 0, ac = 0, bc = 0;
	scanf_s("%ld%ld%ld%ld%ld%ld", &ha, &hb, &hc, &ab, &ac, &bc);

	find_min_neighbor_visit(ha, hb, hc, ab, ac, bc);

	return 0;
}
