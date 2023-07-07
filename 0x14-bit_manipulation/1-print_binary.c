#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: parameter
 */
void print_binary(unsigned long int n)
{
	int bit = 0;

	if (n > 1)
		print_binary(n >> 1);
	bit = n & 1;
	_putchar(bit + '0');
}
