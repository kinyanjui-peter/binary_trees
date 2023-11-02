#include "binary_trees.h"

/**
 * is_tree_perfect - Checks if a binary tree is perfect.
 * A perfect tree has the same number of levels in the left and right subtrees, 
 * and each node has either 2 children or no children.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 0 if the tree is not perfect, or the level of height if it is.
 */
int is_tree_perfect(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	/* If both left and right children exist */
	if (tree->left && tree->right)
	{
		left_height = 1 + is_tree_perfect(tree->left);
		right_height = 1 + is_tree_perfect(tree->right);

		/* Check if the heights are the same and not equal to 0 */
		if (right_height == left_height && right_height != 0 && left_height != 0)
			return (right_height);
		return (0);
	}
	/* If the node has no children */
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	/* If one child is present */
	else
	{
		return (0);
	}
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	/* If the tree is NULL, it is not perfect */
	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		result = is_tree_perfect(tree);
		/* If the result is not 0, the tree is perfect */
		if (result != 0)
		{
			return (1);
		}
		return (0);
	}
}
