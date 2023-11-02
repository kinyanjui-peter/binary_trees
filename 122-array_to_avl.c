#include "binary_trees.h"

/**
 * array_to_avl - Converts an array to an AVL tree.
 * @array: Array to be converted to an AVL tree.
 * @size: Size of the array.
 * Return: AVL tree created from the array.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t index, check_index = 0;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (index = 0; index < size; index++)
	{
		for (check_index = 0; check_index < index; check_index++)
		{
			if (array[check_index] == array[index])
				break;
		}
		if (check_index == index)
		{
			if (avl_insert(&root, array[index]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (root);
}
