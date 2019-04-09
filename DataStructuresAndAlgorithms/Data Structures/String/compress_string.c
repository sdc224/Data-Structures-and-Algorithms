#include <stdio.h>

char* compress_string(char string[])
{
	char *s, *count_string;

	for (s = string, count_string = string; *s; s++)
	{
		int count = 1;

		count_string[0] = s[0];
		count_string++;

		while (s[0] == s[1])
		{
			count++;
			s++;
		}

		if (count > 1)
		{
			const int len = sprintf_s(count_string, sizeof(int), "%d", count);
			count_string += len;
		}
	}

	count_string[0] = 0;
	return string;
}

int main(void)
{
	char str[] = "AAAABBBCCCCEEFGIIJJJKLMNNNOOO";
	printf("Formatted String is: %s", compress_string(str));

	return 0;
}