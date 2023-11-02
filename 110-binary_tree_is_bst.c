#include "binary_trees.h"

/**
 * is_valid_BST - Performs an inorder traversal to check if a binary tree is a BST
 * @node: A pointer to the current node
 * @prev: A pointer to the int holding the previously traversed value
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_valid_BST(const binary_tree_t *node, int *prev)
{
    if (node == NULL)
        return (1);

    if (!is_valid_BST(node->left, prev)) // Check the left subtree
        return (0);

    if (*prev >= node->n) // Compare with the previously traversed value
        return (0);

    *prev = node->n; // Update the previously traversed value

    return (is_valid_BST(node->right, prev)); // Check the right subtree
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a binary search tree (BST)
 * @tree: A pointer to the root node of the tree
 * Return: 1 if the tree is a valid BST, 0 otherwise or if tree is NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    int prev = INT_MIN; // Set the initial previous value to the minimum integer value

    if (tree == NULL)
        return (0); // If the tree is NULL, return 0

    return (is_valid_BST(tree, &prev)); // Call the helper function to check if the tree is a valid BST
}
