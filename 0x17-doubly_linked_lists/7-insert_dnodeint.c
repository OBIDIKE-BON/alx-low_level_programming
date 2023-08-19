#include "lists.h"

/**
 * insert_dnodeint_at_index - insert a node at a given index.
 * @h: poiter to the beginnig of a list.
 * @idx: index of node to be added.
 * @n: value to be addes.
 * Return: address of new node.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int index = 0;
	dlistint_t *current = *h, *new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);
	new->n = n;
	if (*h == NULL)
	{
		new = add_dnodeint_end(h, n);
		*h = new;
		return (*h);
	}
	while (current->next)
	{
		if (index == idx)
		{
			new->next = current;
			current->prev->next = new;
			new->prev = current->prev;
			current->prev = new;
			return (new);
		}
		current = current->next;
		index++;
	}
	if ((index + 1) == idx && current->next == NULL)
	{
		new = add_dnodeint_end(&current, n);
		return (new);
	}
	return (NULL);
}
