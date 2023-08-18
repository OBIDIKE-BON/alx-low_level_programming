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
	dlistint_t *tmp, *new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);
	new->n = n;
	if (*h == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*h = new;
		return (*h);
	}
	while ((*h)->prev)
		*h = (*h)->prev;
	while ((*h)->next)
	{
		if (index == idx)
		{
			tmp = (*h)->prev;
			new->prev = tmp;
			new->next = *h;
			(*h)->prev = new;
			return (new);
		}
		(*h) = (*h)->next;
		index++;
	}
	if ((index + 1) == idx && (*h)->next == NULL)
	{
		tmp = (*h)->next;
		new->prev = *h;
		new->next = tmp;
		(*h)->next = new;
		return (new);
	}
	return (NULL);
}
