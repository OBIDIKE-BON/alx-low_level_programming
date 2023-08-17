#include "lists.h"
/**
 * print_dlistint - print a list.
 * @h: poiter to the list head.
 * Return: number of elements in the list.
*/
size_t print_dlistint(const dlistint_t *h)
{
	int i = 0;
	while (h->prev)
		h = h->prev;
	
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		++i;
	}
	return (i);
}