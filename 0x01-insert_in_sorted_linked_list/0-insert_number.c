#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * insert_node - insert a new node at listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */

listint_t *insert_node(listint_t **head, int number)
{

	listint_t *tmp1 = *head;
	listint_t *new_node;
	listint_t *tmp2;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = number;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	if (number < tmp1->n)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	while (tmp1->next != NULL)
	{
		if (number < tmp1->next->n)
			break;
		tmp1 = tmp1->next;
	}

	tmp2 = tmp1->next;
	tmp1->next = new_node;
	new_node->next = tmp2;
	return (new_node);
}
