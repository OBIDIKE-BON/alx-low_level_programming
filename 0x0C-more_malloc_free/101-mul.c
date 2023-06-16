#include "main.h"

/**
 * _puts - prints string
 * @str: input string
 * Return: no return
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
/**
 * main - multiplies two positive numbers
 * @argc: nunber of arguments passed at run-time
 * @argv: arguments passed at run-time
 * Return: int
 */

int main(int argc, char *argv[])
{
unsigned long mul;
int i, j;
	if (argc != 3)
	{ _puts("Error");
	exit(98); }
	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] > 57 || argv[i][j] < 48)
			{  _puts("Error");
			exit(98); }
		}

	}
	mul = atol(argv[1]) *  atol(argv[2]);
	_puts((char) mul);
return (0);
}
