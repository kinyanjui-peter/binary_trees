#include "binary_trees.h"

/**
 * is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 * @index: index of the node
 * @number_nodes: number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, int index, int number_nodes)
{
    if (tree == NULL)
        return (1);
    if (index >= number_nodes)
        return (0);
    return (is_complete(tree->left, 2 * index + 1, number_nodes) &&
            is_complete(tree->right, 2 * index + 2, number_nodes));
}

/**
 * is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the tree is a max heap, 0 otherwise
 */
int is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (1);

    if (tree->left != NULL && tree->n < tree->left->n)
        return (0);

    if (tree->right != NULL && tree->n < tree->right->n)
        return (0);

    return (is_heap(tree->left) && is_heap(tree->right));
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the tree is a max heap, 0 otherwise
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
