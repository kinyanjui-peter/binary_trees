#include "binary_trees.h"
/**
 * Write a function that goes through a binary tree using level-order traversal
 * Where tree is a pointer to the root node of the tree to traverse 
 * And func is a pointer to a function to call for each node. The value in the
 *  node must be passed as a parameter to this function.
 *  If tree or func is NULL, do nothing
 */
/**
 * binary_tree_levelorder - Traverses a binary tree using a level-order approach
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to execute for each node's value
 *
 * Description:
 * This function traverses the binary tree in a breadth-first manner, processing
 * each node's value with the given function pointer. If either the tree or the
 * function pointer is NULL, the function does nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
        return;

    int tree_height = (int)binary_tree_height(tree);
    for (int i = 1; i <= tree_height; i++)
        binary_tree_levelorder_helper(tree, func, i);
}

/**
 * binary_tree_levelorder_helper - Traverses the tree in a given level
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to execute for each node's value
 * @level: The level of the tree to traverse
 */
void binary_tree_levelorder_helper(const binary_tree_t *tree, void (*func)(int), int level)
{
    if (!tree)
        return;
    if (level == 1)
        func(tree->n);
    else if (level > 1)
    {
        binary_tree_levelorder_helper(tree->left, func, level - 1);
        binary_tree_levelorder_helper(tree->right, func, level - 1);
    }
}
