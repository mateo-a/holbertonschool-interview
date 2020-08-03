#include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * first_empty - finds first parent with an empty child in a heap
 *
 * @root: pointer to root of heap
 *
 * Return: pointer to empty parent or NULL
 */

heap_t *first_empty(heap_t *root)
{
	heap_t *queue[100];
	heap_t *strider = root;
	int enter = 0, exit = 0;

	while (strider && strider->left && strider->right)
	{
		queue[enter] = strider->left;
		enter += 1;
		if (enter >= 99)
			enter = 0;
		queue[enter] = strider->right;
		enter += 1;
		if (enter >= 99)
			enter = 0;
		strider = queue[exit];
		exit += 1;
		if (exit >= 99)
			exit = 0;
	}
	return (strider);
}

/**
 * heap_insert - inserts into a max binary heap
 *
 * @root: root of max binary heap
 * @value: value to insert into max binary heap
 *
 * Return: pointer to inserted node or NULL
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *insert = NULL;
	heap_t *new = NULL;
	int temp;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	insert = first_empty(*root);
	new = binary_tree_node(insert, value);
	if (!insert->left)
		insert->left = new;
	else
		insert->right = new;
	while (new->parent && new->n > (new->parent)->n)
	{
		temp = (new->parent)->n;
		(new->parent)->n = new->n;
		new->n = temp;
		new = new->parent;
	}
	return (new);
}
