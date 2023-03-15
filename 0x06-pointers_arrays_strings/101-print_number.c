#include "main.h"

/**
 * print_number - prints integers enters as parameters using putchar
 * @n: integer to print
 * Return: void
 */
void print_number(int n)
{
	unsigned int num;
/* check if the number is negative */
	num = n;
	if (n < 0)
	{
		_putchar(45);
		num = -n;
	}
/* print number by recursion*/
	if (num / 10)
		print_number(num / 10);
	_putchar((num % 10) + '0');
}
