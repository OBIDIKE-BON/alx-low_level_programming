#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - Delete a node at a given positiion.
 * @head: First node address.
 * @index: Position of the node to delete.
 * Return: If success (1).
 **/

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *node_index, *next;

	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
		return (1);
	}
	node_index = *head;
	for (i = 0; i < index - 1; i++)
	{
		if (node_index->next == NULL)
			return (-1);
		node_index = node_index->next;
	}
	next = node_index->next;
	node_index->next = next->next;
	free(next);
	return (1);
}
