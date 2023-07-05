#include "lists.h"

/**
 * add_node - Adds a new node to a linked list
 * @str: string for the new node
 * @head: pointer to the firs element
 *
 * Return: the number of nodes printed
 */
list_t *add_node(list_t **head, const char *str)
{
	size_t len = 0;
	list_t *first;

	while (str[len])
		len++;

	first = malloc(sizeof(list_t));
	if (first == NULL)
		return (NULL);

	first->str = strdup(str);
	first->len = len;
	first->next = *head;
	*head = first;

	return (*head);
}

