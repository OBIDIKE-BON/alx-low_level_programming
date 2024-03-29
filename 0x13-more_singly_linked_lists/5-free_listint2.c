#include "lists.h"

/**
 * free_listint2 - Frees a linked list
 * @head: pointer to the firs element in the list
 *
 * Return: noting
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (!head)
		return;
	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}

