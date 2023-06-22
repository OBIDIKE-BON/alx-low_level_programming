#include "variadic_functions.h"

/**
 * print_numbers - Prints all numbers passed as args, followed by a new line.
 * @separator: The string to be printed between numbers.
 * @n: The number of integers passed to the function.
 * @...: A variable number of numbers to be printed.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	int i = 0;
	va_list ints;

	if (n <= 0)
		return;

	va_start(ints, n);
	while (++i <= n)
		printf("%d%s", va_arg(ints, int), (separator != NULL ? separator : "");

	va_end(ints);
	_putchar('\n');
}
