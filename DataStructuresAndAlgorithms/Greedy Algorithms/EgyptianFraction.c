#include <stdio.h>

void egyptian_fraction(const int nr, const int dr)
{
	if (nr == 0 || dr == 0)
		return;

	if (dr%nr == 0)
	{
		printf("1/%d", dr / nr);
		return;
	}

	if (nr%dr == 0)
	{
		printf("%d", nr / dr);
		return;
	}

	if(nr>dr)
	{
		printf("%d + ", nr / dr);
		egyptian_fraction(nr%dr, dr);
		return;
	}

	const int n = dr / nr + 1;
	printf("1/%d + ", n);
	egyptian_fraction(nr*n - dr, dr*n);
}

int main()
{
	int n, d;
	printf("Enter numerator and denominator: ");
	scanf_s("%d%d", &n, &d);
	printf("%d / %d = ", n, d);
	egyptian_fraction(n, d);
	printf("\n");
	return 0;
}
