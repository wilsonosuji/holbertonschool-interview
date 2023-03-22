#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: the head of the linked list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *liebre = list;
	listint_t *tortuga = list;

	if (list == NULL || list->next == NULL)
		return (0);

	if (list->next == list)
		return (1);

	while (liebre->next != NULL && liebre->next->next != NULL)
	{
		tortuga = tortuga->next;
		liebre = liebre->next->next;

		if (liebre == tortuga)
		{
			return (1);
		}
	}
	return (0);
}
