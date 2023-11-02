#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    if (!check_complete(tree, 0, count_nodes(tree)))
        return (0);
    return (1);
}

/**
 * count_nodes - Counts the total number of nodes in a binary tree
 * @tree: A pointer to the root node of the tree to count
 *
 * Return: The total number of nodes
 */
size_t count_nodes(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * check_complete - Checks if a binary tree is complete recursively
 * @tree: A pointer to the root node of the tree to check
 * @index: The index of the current node
 * @nodes: The total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int check_complete(const binary_tree_t *tree, size_t index, size_t nodes)
{
    if (!tree)
        return (1);

    if (index >= nodes)
        return (0);

    return (check_complete(tree->left, 2 * index + 1, nodes) &&
            check_complete(tree->right, 2 * index + 2, nodes));
}

