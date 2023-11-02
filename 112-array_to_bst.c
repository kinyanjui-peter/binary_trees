#include "binary_trees.h"

/**
 * array_to_bst - Converts an array to a Binary Search Tree (BST)
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Description:
 * This function builds a BST from the elements in the array.
 *
 * Return: Pointer to the root node of the newly created BST, or NULL on
 * failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t counter;
	bst_t *bst_tree = NULL;

	for (counter = 0; counter < size; counter++)
	{
		bst_insert(&bst_tree, array[counter]);
	}
	return (bst_tree);
}
