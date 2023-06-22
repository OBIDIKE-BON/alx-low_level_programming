#include "variadic_functions.h"

/**
 * sum_them_all -  sum all arguments
 * @n: int, number of expected arguments
 *
 * Return: sum of args
 * On error, 0 is returned
 */

int sum_them_all(const unsigned int n, ...)
{
	int sum;
	va_list ints;

	if (n <= 0)
		return (0);

	va_start(ints, n);
	while (n--)
		sum += va_arg(ints, int);
	va_end(ints);

	return (sum);
}
