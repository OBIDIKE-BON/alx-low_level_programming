#include <stdio.h>

/**
 * printString - Function to print a string using _putchar()
 * @str: pointer to the char being printed
 */

void printString(char *str)
{
	while (*str != '\0')
	{
		putchar(*str);
		str++;
	}
	putchar('\n');
}

/**
 * main - Prgram Entry point and
 * Prints the name of this file
 * Return: Always 0
 */

int main(void)
{
	printString(__FILE__);
	return (0);
}
