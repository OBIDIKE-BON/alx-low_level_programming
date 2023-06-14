#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: width of the array.
 * @height: height of the array.
 *
 * Return: pointer of an array of integers
 */
int **alloc_grid(int width, int height)
{
	int **pointer;
	int i, j;

	if (width < 1 || height < 1)
	{
		return (NULL);
	}

	pointer = malloc(height * sizeof(int *));
	if (pointer == NULL)
	{
		free(pointer);
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		pointer[i] = malloc(width * sizeof(int));
		if (pointer[i] == NULL)
		{
			for (i--; i >= 0; i--)
			{
				free(pointer[i]);
			}
			free(pointer);
			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			pointer[i][j] = 0;
		}
	}

	return (pointer);
}
