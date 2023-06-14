#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of a program.
 * @ac: argument count.
 * @av: argument vector.
 *
 * Return: pointer of an array of char
 */
char *argstostr(int ac, char **av)
{
	char *result;
	int c, i, j, ia;

	if (ac == 0)
	{
		return (NULL);
	}
	for (c = i = 0; i < ac; i++)
	{
		if (av[i] == NULL)
		{
			return (NULL);
		}

		for (j = 0; av[i][j] != '\0'; j++)
		{
			c++;
		}
		c++;
	}

	result = malloc((c + 1) * sizeof(char));

	if (result == NULL)
	{
		free(result);
		return (NULL);
	}

	for (i = j = ia = 0; ia < c; j++, ia++)
	{
		if (av[i][j] == '\0')
		{
			result[ia] = '\n';
			i++;
			ia++;
			j = 0;
		}
		if (ia < c - 1)
		{
			result[ia] = av[i][j];
		}
	}
	result[ia] = '\0';

	return (result);
}
