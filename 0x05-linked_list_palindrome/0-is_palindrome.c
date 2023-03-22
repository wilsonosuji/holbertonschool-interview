#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * cpalidrome - checks if it's a palindrome
 * @left: double pointer to left node
 * @right: double pointer to right node
 *
 * Return: 0 if it's not a palindrome, pal otherwise
 */
int cpalindrome(listint_t **left, listint_t *right)
{
	int pal;

	if (right == NULL)
		return (1);

	pal = cpalindrome(left, right->next);

	if (pal == 0)
		return (0);

	pal = (right->n == (*left)->n);
	*left = (*left)->next;

	return (pal);
}
/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: double pinter to head node
 *
 * Return: A palindrome
 */
int is_palindrome(listint_t **head)
{
	int pal = cpalindrome(head, *head);
	return (pal);
}
