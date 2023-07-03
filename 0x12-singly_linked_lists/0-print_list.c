#include "lists.h"

/**
 * print_list - prints a list
 * @h: pointer to the first node
 *
 * Return: number of items(Nodes)
 */

size_t print_list(const list_t *h)
{
	size_t  size = 0;
	list_t *temp;

	if (!h)
		return (-1);

	if (!h->str)
		printf("[%d] %s\n", 0, "(nil)");
	else
		printf("[%d] %s\n", h->len, h->str);
	temp = h->next;
	size++;
	while (temp)
	{
		if (!temp->str)
			temp->str = "(nil)";
		printf("[%d] %s\n", temp->len, temp->str);
		temp = temp->next;
		size++;
	}

	return (size);
}
