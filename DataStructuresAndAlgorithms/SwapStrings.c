// This program is for swapping two strings
// Algorithm 1 is for character pointer
// Algorithm 2 is for character array(string)

#include <stdio.h>
#include <stdlib.h>

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

// Algorithm 1
void swap_for_character_pointer(char **string1, char **string2)
{
	char *temp = *string1;
	*string1 = *string2;
	*string2 = temp;
}

// Algorithm 2
void swap_for_character_array(char *string1, char *string2)
{
	int len = 0;
	for (char* p = string1; *p; p++, len++);
	char *temp = (char *)malloc((len + 1) * sizeof(char));
	copy_string(string1, temp);
	copy_string(string2, string1);
	copy_string(temp, string2);
	free(temp);
}

int main(void)
{
	char *str1 = "hello"; 
	char *str2 = "world"; 
	swap_for_character_pointer(&str1, &str2);
	printf("str1 is %s, str2 is %s\n", str1, str2);

	char str3[] = "hello";
	char str4[] = "world";
	swap_for_character_array(str3, str4);
	printf("str3 is %s, str4 is %s\n", str3, str4);

	return 0; 
}