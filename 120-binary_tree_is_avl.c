#include "binary_trees.h"

/**
 * tree_height - Compute the height of a tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */
int tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return (1 + ((left_height > right_height) ? left_height : right_height));
}

/**
 * is_binary_search_tree - Check if a binary tree is a BST
 * @tree: Pointer to the root node
 * @prev: Pointer to the integer holding the traversed value
 *
 * Return: 1 if it is a valid BST, 0 otherwise
 */
int is_binary_search_tree(const binary_tree_t *tree, int *prev)
{
	if (tree == NULL)
		return (1);
	if (!is_binary_search_tree(tree->left, prev))
		return (0);
	if (*prev >= tree->n)
		return (0);

	*prev = tree->n;

	return (is_binary_search_tree(tree->right, prev));
}

/**
 * binary_tree_is_avl - Check if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height, balance_factor;
	int prev = INT_MIN;

	if (tree == NULL)
		return (0);

	if (!is_binary_search_tree(tree, &prev))
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);
	balance_factor = left_height - right_height;

	return ((balance_factor >= -1 && balance_factor <= 1) &&
	binary_tree_is_avl(tree->left) &&
	binary_tree_is_avl(tree->right));
}
