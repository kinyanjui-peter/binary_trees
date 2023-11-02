#include "binary_trees.h"

size_t _max(size_t number_1, size_t number_2);
/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 * @tree: tree
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int let = 1;

	if (!tree || binary_tree_balance(tree) != 0)
		return (0);
	if (tree->left)
		let = let & binary_tree_is_perfect(tree->left);
	if (tree->right)
		let = let & binary_tree_is_perfect(tree->right);
	return (let);
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: tree
 *
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	binary_tree_t *tree_tmp = NULL, *child_tmp = (binary_tree_t *) tree;
	int left_height = 0, right_height = 0;

	if (!tree)
		return (0);
	tree_tmp = child_tmp->right;
	child_tmp->right = NULL;
	left_height = (int) binary_tree_height(child_tmp);
	child_tmp->right = tree_tmp;
	tree_tmp = child_tmp->left;
	child_tmp->left = NULL;
	right_height = (int) binary_tree_height(child_tmp);
	child_tmp->left = tree_tmp;
	return (left_height - right_height);
}
/**
 * binary_tree_height - height of a tree
 * @tree: tree
 *
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree && (tree->left || tree->right))
		return (1 + _max(binary_tree_height(tree->left),
					binary_tree_height(tree->right)));
	return (0);
}
/**
 * _max - find max of two numbers
 * @number_1: number
 * @number_2: number
 *
 * Return: max of two numbers
 */
size_t _max(size_t number_1, size_t number_2)
{
	return (number_1 > number_2 ? number_1 : number_2);
}

