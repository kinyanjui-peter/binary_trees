#include "binary_trees.h"

/**
 * create_avl_tree - Create the AVL tree using the middle element of the array.
 * @parent: Parent of the node to create.
 * @array: The sorted array.
 * @start: Position where the array starts.
 * @end: Position where the array ends.
 *
 * Return: The AVL tree created.
 */
avl_t *create_avl_tree(avl_t *parent, int *array, int start, int end)
{
	avl_t *avl_root;
	binary_tree_t *tree_aux;
	int mid = 0;

	if (start <= end)
	{
		mid = (start + end) / 2;
		tree_aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (tree_aux == NULL)
			return (NULL);
		avl_root = (avl_t *)tree_aux;
		avl_root->left = create_avl_tree(avl_root, array, start, mid - 1);
		avl_root->right = create_avl_tree(avl_root, array, mid + 1, end);
		return (avl_root);
	}
	return (NULL);
}

/**
 * sorted_array_to_avl - Create an AVL tree from a sorted array.
 * @array: The sorted array.
 * @size: The size of the sorted array.
 *
 * Return: The AVL tree formed from the sorted array.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (create_avl_tree(NULL, array, 0, ((int)(size)) - 1));
}
