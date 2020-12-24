#include "binary_trees.h"
#include <stdlib.h>

/**
 * depth - depth of a binary tree
 * @tree: pointer to the root node
 *
 * Return: depth
 */
size_t depth(const heap_t *tree)
{
    size_t depth_l = 0;
    size_t depth_r = 0;

    if (!tree)
        return (0);

    if (tree->left)
        depth_l = 1 + depth(tree->left);

    if (tree->right)
        depth_r = 1 + depth(tree->right);

    if (depth_l > depth_r)
        return (depth_l);
    return (depth_r);
}
/**
 * depthTotal - sum of depths
 * @tree: pointer to the root node
 *
 * Return: depth
 */
size_t depthTotal(const binary_tree_t *tree)
{
    size_t depth_l = 0;
    size_t depth_r = 0;

    if (!tree)
        return (0);

    if (tree->left)
        depth_l = 1 + depthTotal(tree->left);

    if (tree->right)
        depth_r = 1 + depthTotal(tree->right);

    return (depth_l + depth_r);
}

/**
 * subTree - sub tree binary
 * @tree: pointer to the root
 * @node: last node
 * @depth: depth of tree
 *
 * Return: No Return
 */
void subTree(heap_t *tree, heap_t **node, size_t depth)
{
    if (!tree)
        return;

    if (!depth)
        *node = tree;
    depth--;

    subTree(tree->left, node, depth);
    subTree(tree->right, node, depth);
}

/**
 * heapTree - binary heap
 * @root: pointer
 */
void heapTree(heap_t *root)
{
    int value;
    heap_t *tmp1, *tmp2;

    if (!root)
        return;

    tmp1 = root;

    while (1)
    {
        if (!tmp1->left)
            break;
        if (!tmp1->right)
            tmp2 = tmp1->left;
        else
        {
            if (tmp1->left->n > tmp1->right->n)
                tmp2 = tmp1->left;
            else
                tmp2 = tmp1->right;
        }
        if (tmp1->n > tmp2->n)
            break;
        value = tmp1->n;
        tmp1->n = tmp2->n;
        tmp2->n = value;
        tmp1 = tmp2;
    }
}

/**
 * heap_extract - function that extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node
 **/
int heap_extract(heap_t **root)
{
    int value;
    heap_t *heap_r, *node;

    if (!root || !*root)
        return (0);
    heap_r = *root;
    value = heap_r->n;
    if (!heap_r->left && !heap_r->right)
    {
        *root = NULL;
        free(heap_r);
        return (value);
    }

    subTree(heap_r, &node, depth(heap_r));

    heap_r->n = node->n;
    if (node->parent->right)
        node->parent->right = NULL;
    else
        node->parent->left = NULL;
    free(node);
    heapTree(heap_r);
    *root = heap_r;
    return (value);
}
