#include "binary_trees.h"

/* Function prototypes */
size_t calculate_tree_size(const binary_tree_t *tree);
heap_t *find_heap_node(heap_t *root, size_t number);
heap_t *rebalance_heap(heap_t *new_node, heap_t *parent);

/**
 * heap_insert - Inserts a node into a heap
 *
 * @tree: Double pointer to the root of the heap
 * @value: The value to be stored in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **tree, int value)
{
	size_t size;
	int do_swap = 1;
	heap_t *new_node, *parent_node;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}

	size = calculate_tree_size(*tree);
	parent_node = find_heap_node(*tree, (size - 1) / 2);
	new_node = binary_tree_node(parent_node, value);

	/* Assign the new node as a left or right child depending on size */
	if (size % 2 == 1)
		parent_node->left = new_node;
	else
		parent_node->right = new_node;

	if (new_node == NULL)
		return (NULL);

	while (do_swap == 1 && parent_node != NULL)
	{
		if (parent_node->n >= new_node->n)
			do_swap = 0;
		else
		{
			new_node = rebalance_heap(new_node, parent_node);
			parent_node = new_node->parent;
		}
	}

	return (new_node);
}

/**
 * calculate_tree_size - Measures the size of the tree
 *
 * @tree: Pointer to the root of the tree
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t calculate_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + calculate_tree_size(tree->left) + calculate_tree_size(tree->right));
}

/**
 * find_heap_node - Finds the node at a specific index in the heap
 *
 * @root: Pointer to the root of the heap
 * @number: Index of the node to find
 *
 * Return: Pointer to the node found at the index
 */
heap_t *find_heap_node(heap_t *root, size_t number)
{
	size_t parent_number, direction;

	if (number == 0)
		return (root);

	parent_number = (number - 1) / 2;
	direction = (number - 1) % 2;

	if (direction == 0)
		return (find_heap_node(root, parent_number)->left);
	return (find_heap_node(root, parent_number)->right);
}

/**
 * rebalance_heap - Rebalances the heap after node insertion
 *
 * @new_node: Pointer to the newly added node
 * @parent_node: Pointer to the parent of the new node
 *
 * Return: Pointer to the parent node
 */
heap_t *rebalance_heap(heap_t *new_node, heap_t *parent_node)
{
	int temp;

	temp = new_node->n;
	new_node->n = parent_node->n;
	parent_node->n = temp;
	return (parent_node);
}
