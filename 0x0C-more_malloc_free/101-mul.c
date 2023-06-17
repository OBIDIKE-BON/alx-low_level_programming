#include <stdlib.h>
#include <stdio.h>
#include "main.h"

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
 * isNumeric - Function to check if a string contains only digits
 * @str: pointer to the char being checked
 * Return: 0 or 1 based on the check
 */
int isNumeric(char *str)
{
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * stringLength - Function to calculate the length of a string
 * @str: pointer to the char array
 * Return: length of passed char array
 */
int stringLength(char *str)
{
	int length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}
/**
 * multiply - Function to multiply two numbers and print the mul
 * @num1: pointer to the first char array passed at run-time
 * @num2: pointer to the second char array passed at run-time
 */
void multiply(char *num1, char *num2)
{
	int len1 = stringLength(num1);
	int len2 = stringLength(num2);
	int mulSize = len1 + len2;
	int *mul = (int *)malloc(sizeof(int) * mulSize);
	int i, j, digit1, digit2, product, carry, remainder;

	if (!isNumeric(num1) || !isNumeric(num2))
	{
		printString("Error");
		exit(98);
	}
/** Initialize mul array with zeros */
	for (i = 0; i < mulSize; i++)
		mul[i] = 0;
	for (i = len1 - 1; i >= 0; i--)/** Perform multiplication */
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			digit1 = num1[i] - '0';
			digit2 = num2[j] - '0';
			product = digit1 * digit2;
			carry = product / 10;
			remainder = product % 10;
			mul[i + j + 1] += remainder;
			mul[i + j] += carry;
		}
	}
	for (i = mulSize - 1; i > 0; i--)
	{
		carry = mul[i] / 10;/** Handle carry */
		mul[i] %= 10;
		mul[i - 1] += carry;
	}
	i = 0;/** Skip leading zeros */
	while (mul[i] == 0 && i < mulSize - 1)
		i++;
	for (; i < mulSize; i++)
		_putchar(mul[i] + '0');/** Print the mul */
	_putchar('\n');
	free(mul);
}

/**
 * main - multiplies two positive numbers
 * @argc: nunber of arguments passed at run-time
 * @argv: arguments passed at run-time
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printString("Error");
		exit(98);
	}

	multiply(argv[1], argv[2]);

	return (0);
}
