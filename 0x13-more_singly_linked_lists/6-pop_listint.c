#include "lists.h"

/**
 * pop_listint - pops the header of a linked list
 * @head: pointer to the firs element in the list
 *
 * Return: noting
 */

int pop_listint(listint_t **head)
{
	int data = 0;
	listint_t *temp;

	if (!*head)
		return (data);
	data = (*head)->n;
	temp = *head;
	*head = temp->next;
	free(temp);

	return (data);
}

