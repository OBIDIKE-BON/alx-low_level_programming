#include <stdio.h>

/**
 * main - program that prints all single digit numbers of base 10 starting from
 * You are not allowed to use any variable of type char
 * You can only use the putchar function
 * Return: 0
 */

int main(void)
{
int n;
for (n = 0 ; n <= 9 ; n++)
{
putchar(n + '0');
}
printf('\n');
return (0);
}
