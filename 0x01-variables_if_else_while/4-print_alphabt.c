#include <stdio.h>

/**
 * main - program that prints the alphabet in lowercase, followed by a new line
 * You can only use the putchar
 * Return: 0
 */

int main(void)
{
int lw = 'a';
while (lw <= 'z')
{
if (lw != 'e' && lw != 'q')
{
putchar(lw);
}
lw++;
}
putchar('\n');
return (0);
}
