#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree for inserting the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        if (!*tree)
            return (NULL);
        return (*tree);
    }

    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert(&(*tree)->left, value);
        if (!(*tree)->left)
            return (NULL);
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert(&(*tree)->right, value);
        if (!(*tree)->right)
            return (NULL);
    }
    else
        return (NULL);

    return *tree;
}
