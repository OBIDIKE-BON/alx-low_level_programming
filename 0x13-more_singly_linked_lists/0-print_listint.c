#include "lists.h"

/**
 * print_listint - prints a list
 * @h: pointer to the first node
 *
 * Return: number of items(Nodes)
 */

size_t print_listint(const listint_t *h)
{
	size_t  size = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		size++;
	}

	return (size);
}
