#include "lists.h"

/**
 * add_nodeint_end - Adds a new node to the end of a linked list
 * @n: in for the new node
 * @head: pointer to the firs element
 *
 * Return: the number of nodes printed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *last, *temp;

	last = malloc(sizeof(listint_t));
	if (!last)
		return (NULL);

	last->n = n;
	last->next = NULL;
	if (!(*head))
	{
		*head = last;
		return (last);
	}

	temp = (*head);
	while ((*temp).next)
		temp = temp->next;

	(*temp).next = last;
	return (last);
}

