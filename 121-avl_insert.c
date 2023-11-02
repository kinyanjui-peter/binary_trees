#include "binary_trees.h"

/**
 * insert_node_avl - Insert a node value into an AVL tree.
 * @tree: Pointer to the root node of the AVL tree struct.
 * @parent: Parent node of the AVL struct.
 * @new: Pointer to the left or right insertion.
 * @value: Value to be inserted into the AVL tree.
 * 
 * Return: Pointer to the new root after insertion, otherwise NULL.
 */
avl_t *insert_node_avl(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
    int balance_value;

    if (*tree == NULL)
        return (*new = binary_tree_node(parent, value));

    if ((*tree)->n > value)
    {
        (*tree)->left = insert_node_avl(&(*tree)->left, *tree, new, value);
        if ((*tree)->left == NULL)
            return (NULL);
    }
    else if ((*tree)->n < value)
    {
        (*tree)->right = insert_node_avl(&(*tree)->right, *tree, new, value);
        if ((*tree)->right == NULL)
            return (NULL);
    }
    else
    {
        return (*tree);
    }

    balance_value = binary_tree_balance(*tree);

    if (balance_value > 1 && (*tree)->left->n > value)
    {
        *tree = binary_tree_rotate_right(*tree);
    }
    else if (balance_value > 1 && (*tree)->left->n < value)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        *tree = binary_tree_rotate_right(*tree);
    }
    else if (balance_value < -1 && (*tree)->right->n < value)
    {
        *tree = binary_tree_rotate_left(*tree);
    }
    else if (balance_value < -1 && (*tree)->right->n > value)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        *tree = binary_tree_rotate_left(*tree);
    }

    return (*tree);
}

/**
 * avl_insert - Insert a value into an AVL tree.
 * @tree: Pointer to the root node of the AVL tree to insert into.
 * @value: Value to store in the node to be inserted.
 * 
 * Return: Inserted node, or NULL if fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new = NULL;

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    insert_node_avl(tree, *tree, &new, value);
    return (new);
}
