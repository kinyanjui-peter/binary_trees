#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree (BST)
 * @tree: Pointer to the root node of the BST
 * @value: Value to search for in the tree
 *
 * Description:
 * If tree is NULL or if nothing is found, return NULL.
 * 
 * Return: Pointer to the node with a value equal to the specified value,
 *         or NULL if no such node exists.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
    if (tree == NULL || tree->n == value)
        return ((bst_t *)tree);

    if (value < tree->n)
        return (bst_search(tree->left, value));
    else
        return (bst_search(tree->right, value));
}
