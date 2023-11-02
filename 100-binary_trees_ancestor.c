#include "binary_trees.h"
/**
 * Write a function that finds the lowest common ancestor of two nodes
 * Where first is a pointer to the first node
 * And second is a pointer to the second node 
 * Your function must return a pointer to the lowest common ancestor node 
 * of the two given nodes 
 * If no common ancestor was found, your function must return NULL
 */

/**
 * binary_trees_ancestor - finds the lowest common ancestor
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the LCA || NULL on failure
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
const binary_tree_t *left_LCA, *right_LCA;

	for (left_LCA = first; left_LCA; left_LCA = left_LCA->parent)
		for (right_LCA = second; right_LCA; right_LCA = right_LCA->parent)
			if (left_LCA == right_LCA)
				return ((binary_tree_t *)left_LCA);
	return (NULL);
}
