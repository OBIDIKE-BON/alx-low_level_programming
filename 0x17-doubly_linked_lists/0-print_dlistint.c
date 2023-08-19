#include "lists.h"
/**
 * print_dlistint - print a list.
 * @h: poiter to the list head.
 * Return: number of elements in the list.
*/
size_t print_dlistint(const dlistint_t *h)
{
	int i = 0;
	const dlistint_t *tmp = h;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
		i++;
	}
	return (i);
}
