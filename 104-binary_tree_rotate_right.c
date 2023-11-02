#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree
 * @tree: A pointer to the root node
 * Return: A pointer to the new root node after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *new_root_right_child, *tree_parent;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	/* Storing references of the involved nodes */
	tree_parent = tree;
	new_root = tree->left;
	new_root_right_child = new_root->right;

	/* Perform the right rotation */
	tree_parent->left = new_root_right_child;
	if (new_root_right_child != NULL)
		new_root_right_child->parent = tree_parent;

	new_root->right = tree_parent;
	new_root->parent = tree_parent->parent;
	tree_parent->parent = new_root;
	return (new_root);
}
