#include "main.h"

/**
 * get_bit - gets value of a bit at a given index
 * @n: decimal parameter
 * @index: index of bit to be returned
 * Return: value at index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit;

	bit = (n >> index);
	if (index > 32)
		return (-1);
	return (bit & 1);
}
