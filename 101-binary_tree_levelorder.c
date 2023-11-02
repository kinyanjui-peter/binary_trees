#include "binary_trees.h"

/**
 * binary_tree_height - Measure the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((left_height > right_height) ? left_height : right_height);
	}
}

/**
 * binary_tree_depth - Calculate the depth of a specified node from the root
 * @tree: Pointer to the node to check the depth
 * Return: 0 if it is the root, or the depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

/**
 * linked_node - Create a linked list from a node at a certain depth level
 * @head: Pointer to the head of the linked list
 * @tree: Node to store
 * @level: Depth of the node to store
 * Return: Nothing
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *new_node, *aux_node;

	new_node = malloc(sizeof(link_t));
	if (new_node == NULL)
	{
		return;/* Unable to allocate memory*/
	}
	new_node->n = level;
	new_node->node = tree;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		aux_node = *head;
		while (aux_node->next != NULL)
		{
			aux_node = aux_node->next;
		}
		new_node->next = NULL;
		aux_node->next = new_node;
	}
}

/**
 * recursion - Traverse the complete tree and store each node in the
 * linked_node function
 * @head: Pointer to the head of the linked list
 * @tree: Node to check
 * Return: Nothing; it affects the pointer
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}

/**
 * binary_tree_levelorder - Print the elements of the nodes in level order
 * @tree: Root node of the binary tree
 * @func: Function to apply to each node
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *aux_node;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
		/*No tree or no function provided*/
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (count <= height)
		{
			aux_node = head;
			while (aux_node != NULL)
			{
				if (count == aux_node->n)
				{
					func(aux_node->node->n);
				}
				aux_node = aux_node->next;
			}
			count++;
		}
		while (head != NULL)
		{
			aux_node = head;
			head = head->next;
			free(aux_node);
		}
	}
}
