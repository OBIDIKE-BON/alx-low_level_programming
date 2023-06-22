#include "variadic_functions.h"

/**
 * print_all - prints any type
 * @format: arguments to print
 */

void print_all(const char * const format, ...)
{
	int i = 0;
	char *sep = "", *c;
	va_list list;

	va_start(list, format);
	while (format[i])
	{
		switch (format[i])
		{
		case 'c':
			printf("%s", sep);
			printf("%c", va_arg(list, int));
			sep = ", ";
		break;
		case 'i':
			printf("%s", sep);
			printf("%i", va_arg(list, int));
			sep = ", ";
		break;
		case 'f':
			printf("%s", sep);
			printf("%f", va_arg(list, double));
			sep = ", ";
		break;
		case 's':
			c =  va_arg(list, char*);
			printf("%s", sep);
			if (c != NULL)
				printf("%s", c);
			if (c == NULL)
				printf("(nil)");
			sep = ", ";
		break;
		default:
		break;
		}
		i++;
	}
	printf("\n");
	va_end(list);
}
