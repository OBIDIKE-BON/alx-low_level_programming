#include "lists.h"
/**
 * sum_dlistint - sum all n in a list.
 * @head: poiter to the list head.
 * Return: the sum.
*/
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
