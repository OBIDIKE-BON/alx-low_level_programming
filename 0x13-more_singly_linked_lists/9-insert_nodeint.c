#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - Insert a new node at a given positiion.
 * @head: First node address.
 * @idx: Position of the new node to be inserted in.
 * @n: Data of the new node.
 * Return: Address of the new node.
 **/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *node_idx, *temp;
	unsigned int i = 0;

	if (*head == NULL && idx != 0)
		return (NULL);
	if (idx != 0)
	{
	temp = *head;
	for (; i < idx - 1 && temp != NULL; i++)
		temp = temp->next;
	if (temp == NULL)
		return (NULL);
	}
	node_idx = malloc(sizeof(listint_t));
	if (node_idx == NULL)
		return (NULL);
	node_idx->n = n;
	if (idx == 0)
	{
		node_idx->next = *head;
		*head = node_idx;
		return (node_idx);
	}
	node_idx->next = temp->next;
	temp->next = node_idx;
	return (node_idx);
}
