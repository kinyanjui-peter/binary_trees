#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node
 * A NULL pointer is not a leaf
 * Return: 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leftleafnode, rightleafnode;

	if (tree == NULL)
		return (0);
	/* Nodes that have no children are called leaves */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Recursively count the leaves */
	leftleafnode = binary_tree_leaves(tree->left);
	rightleafnode = binary_tree_leaves(tree->right);

	return (leftleafnode + rightleafnode);
}

