#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning a linked list
 * @n: int for the new node
 * @head: pointer to the firs element
 *
 * Return: the number of nodes printed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	size_t len = 0;
	listint_t *first;

	first = malloc(sizeof(listint_t));
	if (first == NULL)
		return (NULL);

	first->n = n;
	first->next = *head;
	*head = first;

	return (*head);
}

