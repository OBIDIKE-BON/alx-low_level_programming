#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "lists.h"

size_t _print_dlistint_backward(const dlistint_t *h);

/**
 * _create_dlist - Create a list
 *
 * @n: Number of elements
 *
 * Return: A pointer to the first element of the created list
 */
dlistint_t *_create_dlist(unsigned int n, ...)
{
	va_list args;
	dlistint_t *list;
	dlistint_t *tmp;
	dlistint_t *prev;
	unsigned int i;
	int nb;

	va_start(args, n);
	prev = tmp = list = NULL;
	i = 0;
	while (i < n)
	{
		nb = va_arg(args, int);
		tmp = malloc(sizeof(*tmp));
		if (!tmp)
			return (NULL);
		tmp->n = nb;
		tmp->next = NULL;
		tmp->prev = prev;
		if (!list)
			list = tmp;
		if (prev)
			prev->next = tmp;
		prev = tmp;
		++i;
	}
	va_end(args);
	return (list);
}

/**
 * _free_dlistint - Free a list
 *
 * @list: A pointer to the first element of a list to free
 */
void _free_dlistint(dlistint_t *list)
{
	if (list)
	{
		_free_dlistint(list->next);
		free(list);
	}
}

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	dlistint_t *head;
	dlistint_t *node;
	size_t n;
	int i;

	head = _create_dlist(150, 919955, -221576, -859826, -673092, -227441, -274387, -436509, -877540, -312324, -132610, -451068, -634665, 265754, 680646, -103124, 455298, -674129, -505322, -480779, -976755, -61049, 752586, -780309, -225601, 545574, 967894, -952912, -710816, -464807, -83928, -144352, 272984, -103436, -469044, 727842, -471465, 632218, 484071, 164176, -888075, 375238, -368407, -126852, 747849, -444324, -508919, 212726, 921259, 145606, -168736, 482175, 417315, -144374, 766661, 459419, -971797, 614621, 395332, 382023, 937524, 281705, 106337, 588634, 914645, 904202, 123836, -912500, -937165, 904917, 514808, -429722, 364031, 4549, 849042, -130394, -678079, 866332, 290840, -398001, 894631, -843992, 650923, 759358, -173141, -814339, 102554, -152928, -384918, -694858, -909105, 758674, -903057, 995532, -473530, 170832, -283768, 202502, -77236, -828210, -5871, 751590, 617269, -113835, -424265, 885113, -228101, 348995, -597740, 488342, 178172, 636416, -115361, 349580, 598603, 463378, -892583, -426662, 246129, -831511, -287468, 694342, -935414, 230693, 22105, -803356, -739612, -134577, -702335, -952953, 825327, -199434, 162758, -725024, 554175, 644023, -983839, -931458, -825615, -121051, -2142, 331891, -330280, 547907, -626812, 107124, -140852, 862279, -694146, 775690, -98861);
	node = insert_dnodeint_at_index(&head, 150, 150);
	if (node)
		printf("-> %d\n", node->n);
	else
		printf("(nil)\n");
	for (i = 0; i < 10; ++i)
	{
		node = insert_dnodeint_at_index(&head, i * 10, 98);
		if (node)
			printf("-> %d\n", node->n);
		else
			printf("(nil)\n");
	}
	n = print_dlistint(head);
	printf("-> %lu elements\n", n);
	n = _print_dlistint_backward(head);
	printf("-> %lu elements\n", n);
	_free_dlistint(head);
	return (0);
}
