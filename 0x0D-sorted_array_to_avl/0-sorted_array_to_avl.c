#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: pointer to the root node of the created AVL tree, NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *right, *left, *root = NULL;
	size_t half;

	if (!array || size < 1)
		return (NULL);
	root = malloc(sizeof(avl_t));
	if (!root)
		return (NULL);
	half = (size - 1) / 2;
	root->n = array[half];
	root->parent = NULL;
	if (half > 0)
		left = sorted_array_to_avl(array, half);
	else
		left = NULL;
	if (size > (half + 1))
		right = sorted_array_to_avl(&array[half + 1], size - (half + 1));
	else
		right = NULL;
	root->left = left;
	root->right = right;
	if (root->left)
		(root->left)->parent = root;
	if (root->right)
		(root->right)->parent = root;
	return (root);
}
