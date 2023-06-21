#include "function_pointers.h"

/**
 * array_iterator - Executes a function given as a
 * 		    parameter on each element of an array.
 * @array: Pointer to int array.
 * @size: The size of array.
 * @action: A pointer to the function to be executed.
 *
 * Returns: Nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array != NULL && action != NULL)
	{
		while(size--)
		{
			action(*array++);
		}
	}
}
