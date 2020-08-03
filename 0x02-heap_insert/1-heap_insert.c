#include "binary_trees.h"
/**
 * _height - Measures the height of a binary tree
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
int _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (!tree)
		return (-1);

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * heapify - Check if child is greather than parent and order the heap
 * @firstParent: Node parent of node to insert
 * @nodeChild: Node that will be inserted and need to be checked with
 *             the parent
 */
void heapify(heap_t **firstParent, heap_t **nodeChild)
{
	heap_t *parentCheck, *childCheck, *nChild, *nodeLeft, *nodeRight, *parent;
	int swp;

	parentCheck = *firstParent, childCheck = *nodeChild;
	if (childCheck->n > parentCheck->n)
	{
		if (childCheck->left)
			childCheck->left->parent = parentCheck;
		if (childCheck->right)
			childCheck->right->parent = parentCheck;
		if (parentCheck->left == childCheck)
			nChild = parentCheck->right, swp = 0;
		else
			nChild = parentCheck->left, swp = 1;
		nodeLeft = childCheck->left, nodeRight = childCheck->right;
		if (swp == 0)
		{
			childCheck->right = nChild;
			if (nChild)
				nChild->parent = childCheck;
			childCheck->left = parentCheck;
		}
		else
		{
			childCheck->left = nChild;
			if (nChild)
				nChild->parent = childCheck;
			childCheck->right = parentCheck;
		}
		if (parentCheck->parent)
		{
			if (parentCheck->parent->left == parentCheck)
				parentCheck->parent->left = childCheck;
			else
				parentCheck->parent->right = childCheck;
		}
		parent = parentCheck->parent, childCheck->parent = parent;
		parentCheck->parent = childCheck, parentCheck->left = nodeLeft;
		parentCheck->right = nodeRight, *firstParent = childCheck;
	}
}
/**
 * treeFull - Check the height for the branches and if are full
 * @root: Pointer to the root
 * Return: 1 if tree is full otherwise 0
 */
int treeFull(const binary_tree_t *root)
{
	if (root && _height(root->left) == _height(root->right))
	{
		if (_height(root->left) == -1)
			return (1);
		if ((root->left && !((root->left)->left) && !((root->left)->right))
		&& (root->right && !((root->right)->left)
		&& !((root->right)->right)))
			return (1);
		if (root && root->left && root->right)
			return (treeFull(root->left) && treeFull(root->right));
	}
	return (0);
}
/**
 * heap_insert - function that inserts a value in Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: is the value store in the node to be inserted
 * Return: A pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	if (treeFull(*root) || !treeFull((*root)->left))
	{
		if ((*root)->left)
		{
			new = heap_insert(&((*root)->left), value);
			heapify(root, &((*root)->left));
			return (new);
		}
		else
		{
			new = (*root)->left = binary_tree_node(*root, value);
			heapify(root, &((*root)->left));
			return (new);
		}
	}
	if ((*root)->right)
	{
		new = heap_insert(&((*root)->right), value);
		heapify(root, (&(*root)->right));
		return (new);
	}
	else
	{
		new = (*root)->right = binary_tree_node(*root, value);
		heapify(root, &((*root)->right));
		return (new);
	}
	return (NULL);
}
