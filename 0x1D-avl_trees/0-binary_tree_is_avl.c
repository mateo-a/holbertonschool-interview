#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_check - checks for bestness
 * @root: root node of tree
 * @min: minimum value constraint
 * @max: maximum value constraint
 * Return: 1 if bst, 0 otherwise
 */

int bst_check(const binary_tree_t *root, int min, int max)
{
	if (root == NULL)
		return (1);
	if (root->n < min || root->n > max)
		return (0);
	return (bst_check(root->left, min, root->n - 1) &&
		bst_check(root->right, root->n + 1, max));
}

/**
 * h_check - check tree height
 * @root: root node of tree
 * Return: height of tree
 */

int h_check(const binary_tree_t *root)
{
	int l, r;

	if (root == NULL)
		return (0);
	l = h_check(root->left);
	r = h_check(root->right);
	if (r > l)
		return (1 + r);
	return (1 + l);
}


/**
 * b_check - checks tree balance
 * @root: root node of tree
 * Return: 1 if balanced, 0 otherwise
 */

int b_check(const binary_tree_t *root)
{
	int l, r;

	if (root == NULL)
		return (1);
	l = h_check(root->left);
	r = h_check(root->right);
	if (abs(l - r) <= 1 &&
	    b_check(root->left) &&
	    b_check(root->right))
		return (1);
	return (0);
}


/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL, 0 otherwise.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (bst_check(tree, -2147483648, 2147483647) != 1)
		return (0);
	if (b_check(tree) != 1)
		return (0);
	return (1);
}
