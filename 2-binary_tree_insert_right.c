#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node to the right of the parent node
 * If the parent node already has a right child, the new node is added as the
 * right child, and the original right child becomes the right
 * child of the new node.
 * @parent: Pointer to the parent node
 * @value: Value to be stored in the new node
 * Return: Pointer to the newly inserted node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	/* Declare a new binary_tree_t pointer for the new node */
	binary_tree_t *new_node;

	/* Check if the parent is NULL */
	if (parent == NULL)
	{
		return (NULL);
	}

	/* Create a new node */
	new_node = binary_tree_node(parent, value);

	/* Check if the creation of the new node fails */
	if (new_node == NULL)
	{
		return (NULL);
	}

	/* If the parent already has a right child, reassign pointers */
	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}

	/* Set the new node as the right child of the parent */
	parent->right = new_node;

	/* Return a pointer to the newly inserted node */
	return (new_node);
}
