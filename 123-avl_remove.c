#include "binary_trees.h"

/**
 * balance_factor - Measures balance factor of an AVL tree
 * @tree: Pointer to the tree to go through
 *
 * Return: Balance factor
 */
void balance_factor(avl_t **tree)
{
	int balance_value;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	balance_factor(&(*tree)->left);
	balance_factor(&(*tree)->right);

	balance_value = binary_tree_balance((const binary_tree_t *)*tree);
	if (balance_value > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_value < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * get_successor - Get the next successor, i.e., the minimum node in the right subtree
 * @node: Tree node to check
 *
 * Return: The minimum value of this tree
 */
int get_successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = get_successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}

/**
 * remove_node_type - Function that removes a node depending on its children
 * @root: Node to remove
 *
 * Return: 0 if it has no children, otherwise returns another value
 */
int remove_node_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = get_successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - Remove a node from a BST tree
 * @root: Root of the tree
 * @value: Node with this value to remove
 *
 * Return: The changed tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int node_type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		node_type = remove_node_type(root);
		if (node_type != 0)
			bst_remove(root->right, node_type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - Remove a node from an AVL tree
 * @root: Root of the tree
 * @value: Node with this value to remove
 *
 * Return: The changed tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_avl = (avl_t *)bst_remove((bst_t *)root, value);

	if (root_avl == NULL)
		return (NULL);
	balance_factor(&root_avl);
	return (root_avl);
}
