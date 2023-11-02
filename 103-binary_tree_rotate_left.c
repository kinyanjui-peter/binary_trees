#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left rotation on a BT
 * @tree: pointer to the root node
 * Return: pointer to the new node
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *new_root_left_child, *tree_parent;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	/* Storing the references of the nodes involved */
	tree_parent = tree;
	new_root = tree->right;
	new_root_left_child = new_root->left;

	/* Rotating left */
	tree_parent->right = new_root_left_child;
	if (new_root_left_child != NULL)
		new_root_left_child->parent = tree_parent;

	new_root->left = tree_parent;
	new_root->parent = tree_parent->parent;
	tree_parent->parent = new_root;

	return (new_root);
}
