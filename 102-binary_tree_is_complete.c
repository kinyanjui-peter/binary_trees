#include "binary_trees.h"

/**
 * create_new_node - Creates a new node in a linked list
 * @node: Pointer to the node to be created
 * Return: The created node
 */
link_t *create_new_node(binary_tree_t *node)
{
	link_t *new_node;

	new_node =  malloc(sizeof(link_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * free_linked_list - Frees the nodes in the linked list
 * @head: Head node of the linked list
 */
void free_linked_list(link_t *head)
{
	link_t *temp_node;

	while (head)
	{
		temp_node = head->next;
		free(head);
		head = temp_node;
	}
}

/**
 * push_node - Pushes a node into the stack
 * @node: Pointer to the node of the tree
 * @head: Head node in the stack
 * @tail: Tail node in the stack
 */
void push_node(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *new_node;

	new_node = create_new_node(node);
	if (new_node == NULL)
	{
		free_linked_list(head);
		exit(1);
	}
	(*tail)->next = new_node;
	*tail = new_node;
}

/**
 * pop_node - Pops a node from the stack
 * @head: Head node in the stack
 */
void pop_node(link_t **head)
{
	link_t *temp_node;

	temp_node = (*head)->next;
	free(*head);
	*head = temp_node;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the node of the tree
 * Return: 1 if the tree is complete, 0 if it is not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *head, *tail;
	int flag = 0;

	if (tree == NULL)
	{
		return (0);
	}
	head = tail = create_new_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_linked_list(head);
				return (0);
			}
			push_node(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_linked_list(head);
				return (0);
			}
			push_node(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop_node(&head);
	}
	return (1);
}
