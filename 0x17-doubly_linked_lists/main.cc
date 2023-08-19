#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;

    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 40);
    add_dnodeint_end(&head, 10);
    print_dlistint(head);
    printf("-----------------\n");
    insert_dnodeint_at_index(&head, 0, 1096);
    insert_dnodeint_at_index(&head, 0, 2096);
    insert_dnodeint_at_index(&head, 8, 5096);
    insert_dnodeint_at_index(&head, 9, 8096);
    insert_dnodeint_at_index(&head, 10, 9096);
    insert_dnodeint_at_index(&head, 11, 1096);
    print_dlistint(head);
    free_dlistint(head);
    head = NULL;
    return (EXIT_SUCCESS);
}