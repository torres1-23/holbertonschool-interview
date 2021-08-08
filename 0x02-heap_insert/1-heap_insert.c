#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 * Return: pointer to the new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent_node = NULL;
	heap_t *new_node = NULL;
	int temp;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	parent_node = first_empty(*root);
	new_node = binary_tree_node(parent_node, value);
	if (!parent_node->left)
		parent_node->left = new_node;
	else
		parent_node->right = new_node;
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		temp = new_node->parent->n;
		new_node->parent->n = new_node->n;
		new_node->n = temp;
		new_node = new_node->parent;
	}
	return (new_node);
}

/**
 * first_empty - Finds first parent with an empty child in a heap
 * @root: pointer to root of heap
 * Return: pointer to empty parent or NULL
 */

heap_t *first_empty(heap_t *root)
{
	heap_t *queue[100];
	heap_t *parent = root;
	int enter = 0, exit = 0;

	while (parent && parent->left && parent->right)
	{
		queue[enter] = parent->left;
		enter += 1;
		if (enter >= 99)
			enter = 0;
		queue[enter] = parent->right;
		enter += 1;
		if (enter >= 99)
			enter = 0;
		parent = queue[exit];
		exit += 1;
		if (exit >= 99)
			exit = 0;
	}
	return (parent);
}
