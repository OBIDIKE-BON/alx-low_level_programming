#include "lists.h"

/**
 * free_listint - Frees a linked list
 * @head: pointer to the firs element in the list
 *
 * Return: noting
 */

void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

