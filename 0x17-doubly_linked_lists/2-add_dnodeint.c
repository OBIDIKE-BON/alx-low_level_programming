#include "lists.h"

/**
 * add_dnodeint - adds node to a list.
 * @head: poiter to the list head.
 * @n: number to be added to the list.
 * Return: address of new node.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
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
	tmp = *head;
	new->next = tmp;
	tmp->prev = new;
	new->prev = NULL;
	*head = new;

	return (new);
}
