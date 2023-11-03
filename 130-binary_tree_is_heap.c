#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree
 * is a valid Max Binary Heap.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a max heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int nodes = 0;

    if (tree == NULL)
        return (0);
    if (!is_complete(tree, 0, nodes) || !is_heap(tree))
        return (0);
    return (1);
}
