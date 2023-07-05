#include "lists.h"

/**
 * add_node_end - Adds a new node to a linked list
 * @str: string for the new node
 * @head: pointer to the firs element
 *
 * Return: the number of nodes printed
 */

list_t *add_node_end(list_t **head, const char *str)
{
	size_t len = 0;
	list_t *last, *temp;

	while (str[len])
		len++;

	last = malloc(sizeof(list_t));
	if (!last || !str)
		return (NULL);

	last->str = strdup(str);
	last->len = len;
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

