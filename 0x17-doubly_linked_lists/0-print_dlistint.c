#include "lists.h"

size_t print_dlistint(const dlistint_t *h)
{
	int i = 0;
	while (h->next)
	{
		printf("%d\n", h->n);
		++i;
	}
	return (i);
}