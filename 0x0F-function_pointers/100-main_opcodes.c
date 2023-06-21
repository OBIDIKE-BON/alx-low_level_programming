#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints it's own opcodes.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int number_of_bytes, i;
	int (*main_ptr)(int, char **) = main;
	unsigned char opcode;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	number_of_bytes = atoi(argv[1]);

	if (number_of_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < number_of_bytes; i++)
	{
		opcode = *(unsigned char *)main_ptr;
		printf("%.2x", opcode);

		if (i == number_of_bytes - 1)
			continue;
		printf(" ");

		main_ptr++;
	}

	printf("\n");

	return (0);
}
