#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to head of list
 * @number: number to insert.
 * Return: new inserted node or NULL if failed.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *nodes = *head, *new_node;

	if (!head)
		return (NULL);
	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);
	new_node->n = number;
	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}
	if (new_node->n < nodes->n)
	{
		new_node->next = nodes;
		*head = new_node;
		return (new_node);
	}
	while (nodes->next && number > nodes->next->n)
	{
		nodes = nodes->next;
	}
	new_node->next = nodes->next;
	nodes->next = new_node;
	return (new_node);
}
