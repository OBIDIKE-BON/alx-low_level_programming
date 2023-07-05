#include "lists.h"

/**
 * free_listint2 - Frees a linked list
 * @head: pointer to the firs element in the list
 *
 * Return: noting
 */

void free_listint2(listint_t **head)
{
	free(*head);
	*head = NULL;
}

