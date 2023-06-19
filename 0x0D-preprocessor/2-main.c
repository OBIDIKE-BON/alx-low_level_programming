#include <stdio.h>

/**
 * printString - Function to print a string using _putchar()
 * @str: pointer to the char being printed
 */

void printString(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}

/**
 * main - Prgram Entry point and
 * Prints the name of this file
 */

int main(void)
{
	printString("%s", __FILE__);
}
