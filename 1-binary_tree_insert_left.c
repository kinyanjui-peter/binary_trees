#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 * If parent already has a left-child, the new node must take its place,
 * and the old left-child must be set as the left-child of the new node.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left_child;

	if (parent == NULL)
		return (NULL);

	new_left_child = malloc(sizeof(binary_tree_t));
	if (new_left_child == NULL)
		return (NULL);

	new_left_child->parent = parent;
	new_left_child->n = value;
	/*replacing old left child if it was already there*/
	new_left_child->left = parent->left;
	new_left_child->right = NULL;
	/*point left child of parent to new left child*/
	parent->left = new_left_child;

	/*set old left child as new left child if it was already there*/
	if (new_left_child->left)
	{
		new_left_child->left->parent = new_left_child;
	}

	return (new_left_child);
}
