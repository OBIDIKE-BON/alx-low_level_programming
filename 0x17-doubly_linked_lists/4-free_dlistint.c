#include "lists.h"

/**
 * free_dlistint - frees a doubly liked list.
 * @head: poiter to the list head.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	if (head == NULL)
		return;
	while (head->next)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	free(head);
}
