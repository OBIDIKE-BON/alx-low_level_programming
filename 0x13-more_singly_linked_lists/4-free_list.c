#include "lists.h"

/**
 * free_list - Frees a linked list
 * @head: pointer to the firs element in the list
 *
 * Return: noting
 */

void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free((*head).str);
		free(head);
		head = temp;
	}
}

