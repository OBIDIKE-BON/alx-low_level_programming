#include "lists.h"

/**
 * add_dnodeint_end - adds node to the end of a list.
 * @head: poiter to the list head.
 * @n: number to be added to the list.
 * Return: address of new node.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *tmp = *head;
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	if (tmp == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (*head);
	}
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new;
	new->next = NULL;
	new->prev = tmp;
	return (new);
}
