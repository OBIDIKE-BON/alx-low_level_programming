#include "main.h"

/**
 * print_number - prints integers enters as parameters using putchar
 * @n: integer to print
 * Return: void
 */
void print_number(int n)
{
	int power = 10;

	if (n < 0)
	{
		_putchar('-');
		n *= -1;
	}

	if (n >= 0 && n <= 9)
		_putchar((n) + '0');

	else
	{
		while (n / power > 9)
			power *= 10;

		while (power >= 1)
		{
			_putchar((n / power) + '0');
			n %= power;
			power /= 10;
		}
	}
}
