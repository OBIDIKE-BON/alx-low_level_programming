#include "variadic_functions.h"

/**
 * print_strings - Prints all string passed as args, followed by a new line.
 * @separator: The string to be printed between numbers.
 * @n: The number of strings passed to the function.
 * @...: A variable number of strings to be printed.
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i = 0;
	va_list ints;
	char *c;

	va_start(ints, n);
	while (++i <= n)
	{
		c = va_arg(ints, char*);
		printf("%s", (c != NULL ? c : "(nil)"));
		printf("%s", (separator != NULL && i != n ? separator : ""));
	}

	printf("\n");

	va_end(ints);
}
