#include "lists.h"

/**
 * is_palindrome - checks if a linked list is a palindrome
 * @head: pointer to head of list
 * Return: number of nodes
 */
int is_palindrome(listint_t **head)
{
	listint_t **first = NULL;
	listint_t *last = NULL;
	int result = 0;

	if (!head)
		return (0);
	if (!*head)
		return (1);
	first = head;
	last = *head;
	result = palindrome(first, last);
	return (result);
}

/**
 * palindrome - Recursive function to check a linked list for palindromeness
 * @first:first value to check
 * @last: last value to check
 * Return: 1 or 0;
 */
int palindrome(listint_t **first, listint_t *last)
{
	int result = -1;
	int output = -1;

	if (last == NULL)
		return (1);
	result = palindrome(first, last->next);
	if (result == 0)
		return (0);
	if ((*first)->n == last->n)
		output = 1;
	else
		output = 0;
	*first = (*first)->next;
	return (output);
}
