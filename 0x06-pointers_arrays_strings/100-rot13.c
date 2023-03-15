#include "main.h"

/**
 * rot13 -  a   function that encodes a string using rot13.
 * @s: An input string to encode using rot13
 * Return: An encode string
 */
char *rot13(char *s) 
{
	char *result;

	int i, j;
	for (i = 0, j = 0; str[i] != '\0'; i++, j++) 
	{
		if (s[i] >= 'a' && s[i] <= 'z') 
		{
			result[j] = ((s[i] - 'a') + 13) % 26 + 'a';
		} else if (s[i] >= 'A' && s[i] <= 'Z') 
		{
			result[j] = ((s[i] - 'A') + 13) % 26 + 'A';
		}
		else 
		{
			result[j] = s[i];
		}
	}
	result[j] = '\0';
	return result;
}
