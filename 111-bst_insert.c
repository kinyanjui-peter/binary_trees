#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a binary search tree (BST)
 * @tree: Double pointer to the root node
 * @value: Value to store in the node to be inserted
 *
 * Description:
 * If the address stored in tree is NULL, the created node becomes
 * the root node.
 * If the value is already present in the tree, it is ignored.
 *
 * Return: Pointer to the created node, NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current_node;

	if (tree == NULL || *tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
	return (new_node);
	}

	current_node = *tree;

	while (current_node != NULL)
	{
		if (current_node->n == value)
			return (NULL);
		if (current_node->n > value)
		{
			if (current_node->left == NULL)
			{
				current_node->left = binary_tree_node(current_node, value);
				return (current_node->left);
			}
			current_node = current_node->left;
		}
		if (current_node->n < value)
		{
			if (current_node->right == NULL)
			{
				current_node->right = binary_tree_node(current_node, value);
				return (current_node->right);
			}
			current_node = current_node->right;
		}
	}
	return (NULL);
}
