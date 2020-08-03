#include "binary_trees.h"
/**
 * checkFree - Check the first free position in the tree
 * @root: Pointer to the root node of the Heap
 * Return: Pointer to parent with free position
 */
heap_t *checkFree(heap_t *root)
{
	heap_t *arr[1000];
	heap_t *strider = root;
	int inPos = 0, outPos = 0;

	while (strider && strider->left && strider->right)
	{
		arr[inPos] = strider->left;
		inPos += 1;
		if (inPos >= 999)
			inPos = 0;
		arr[inPos] = strider->right;
		inPos += 1;
		if (inPos >= 999)
			inPos = 0;
		strider = arr[outPos];
		outPos += 1;
		if (outPos >= 999)
			outPos = 0;
	}
	return (strider);
}

/**
 * heap_insert - function that inserts a value into a Max Binary Heap
 * @root: is a double pointer to the root node of the Heap
 * @value: is the value store in the node to be inserted
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *posInsertion = NULL;
	heap_t *new = NULL;
	int temp;

	if (root == NULL)
		return (NULL);
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	posInsertion = checkFree(*root);
	new = binary_tree_node(posInsertion, value);
	if (posInsertion->left == NULL)
		posInsertion->left = new;
	else
		posInsertion->right = new;
	while (new->parent && new->n > (new->parent)->n)
	{
		temp = (new->parent)->n;
		(new->parent)->n = new->n;
		new->n = temp;
		new = new->parent;
	}
	return (new);
}
