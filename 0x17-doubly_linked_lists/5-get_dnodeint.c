#include "lists.h"

/**
 * get_dnodeint_at_index - get a node at a given index.
 * @head: poiter to the beginnig of a list.
 * @index: index of node to be retrieved.
 * Return: address of new node.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int idx = 0;

	while (head)
	{
		if (idx == index)
			return (head);
		head = head->next;
		idx++;
	}
	return (NULL);
}
