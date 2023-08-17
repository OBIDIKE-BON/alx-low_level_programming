#include "lists.h"
/**
 * dlistint_len - counts a list.
 * @h: poiter to the list head.
 * Return: number of elements in the list.
*/
size_t dlistint_len(const dlistint_t *h)
{
	int i = 0;

	while (h)
	{
		h = h->next;
		++i;
	}
	return (i);
}
