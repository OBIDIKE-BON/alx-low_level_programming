#include <stdio.h>
#include "main.h"
/**
 * Description: main - prints all command line arguments, one per line.
 * followed by a new line.
 * @argc: the number of cammand line arguments passed at run-time.
 * @argv: an array of cammand line arguments passed at run-time.
 * Return: 0 if success.
 */
int main(int argc, char *argv[])
{
	int i;

	for(i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
