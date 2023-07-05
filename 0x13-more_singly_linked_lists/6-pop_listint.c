#include "lists.h"

/**
 * pop_listint - pops the header of a linked list
 * @head: pointer to the firs element in the list
 *
 * Return: noting
 */

int pop_listint(listint_t **head)
{
	int data =0;

	if (!head)
		return (data);
	data = (*head)->n;
	free(*head);
	*head = NULL;

	return (data);
}

