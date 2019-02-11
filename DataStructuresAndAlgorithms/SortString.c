// A C Program to sort a string alphabetically

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Utility Function(Helper)
void copy_string(const char *string1, char* string2)
{
	int i;
	
	for (i = 0; string1[i]!='\0'; i++)
  	{
  		string2[i] = string1[i];
  	}

  	string2[i] = '\0';
}

// Utility Function
void swap_for_character_pointer(char **string1, char **string2)
{
	char *temp = *string1;
	*string1 = *string2;
	*string2 = temp;
}

void sort(char *strArray[], int n)
{
	char *temp;

	for (int i = 0; i < n; i++) 
	{
	    for (int j = 0; j < n - i - 1; j++) 
		{
	        if(strArray[j] > strArray[j + 1])
			{
	            temp = strArray[j];
	            strArray[j] = strArray[j + 1];
	            strArray[j + 1] = temp;
	        }
	    }
	}
}

void sort_string(char **s)
{
	int d = 0;
	int length = 0;
	char *string_copy;

	for (string_copy = *s; *string_copy; string_copy++, length++);

	char *result = (char*)malloc((length + 1) * sizeof(char));

	string_copy = *s;

	for (char ch = 'a'; ch <= 'z'; ch++)
	{
		for (int c = 0; c < length; c++)
		{
			if (*string_copy == ch)
			{
				*(result+d) = *string_copy;
				d++;
			}

			string_copy++;
		}

		string_copy = *s;
	}

	*(result+d) = '\0';
	*s = (char*)malloc((length + 1) * sizeof(char));
	copy_string(result, *s);
	free(result);
}

int main(void)
{
	/*char *string = "hello world";
	sort_string(string);
	printf("Sorted String: %s", string);*/

	char *more_strings[] = {"Sayan", "Rajarshi", "Vishal", "Anirban", "Souren"}; 	
	int n = 0;
	for (char** temp = more_strings; *temp; temp++, n++);
	sort(more_strings, n);
	for (int i = 0; i < n; i++)
		printf("%s", more_strings[i]);
	return 0;
}