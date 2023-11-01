#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node
 * Return: 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_node_height, right_node_height;

	if (tree == NULL)
		return (0);

	left_node_height = binary_tree_height(tree->left);
	right_node_height = binary_tree_height(tree->right);

	return (left_node_height - right_node_height);
}

/**
 * binary_tree_height - calculate height of a binary tree
 * @tree: pointer to the root node
 * Return: 0 on failure || height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_node_height = 0;
	size_t right_node_height = 0;

	if (tree == NULL)
		return (0);

	left_node_height += 1 + binary_tree_height(tree->left);
	right_node_height += 1 + binary_tree_height(tree->right);

	if (left_node_height > right_node_height)
		return (left_node_height);
	else
		return (right_node_height);
}
