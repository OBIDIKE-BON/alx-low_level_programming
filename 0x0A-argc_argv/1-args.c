#include <stdio.h>
#include "main.h"
/**
 * Description: main - prints number of command line arguments 
 * passed at run-time followed by a new line.
 * @argc: the number of cammand line arguments passed at run-time.
 * @argv: an array of cammand line arguments passed at run-time.
 * Return: 0 if success.
 */
int main(int argc, char *argv[])
{
	printf("%d\n", argc - 1);
	return (0);
	UNUSED(argv);
}
