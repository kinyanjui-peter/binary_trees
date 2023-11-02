#include "binary_trees.h"

/**
 * bst_find_min - Finds the node with the minimum value in a BST
 *
 * @node: Pointer to the node
 *
 * Return: NULL if node is NULL, pointer to the node with the
 * minimum value otherwise
 */
bst_t *bst_find_min(bst_t *node)
{
if (node == NULL)
    return (NULL);

while (node->left != NULL)
    node = node->left;
return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 *
 * @root: Pointer to the root node of the BST
 *
 * @value: Value to remove from the BST
 *
 * Return: Pointer to the new root node of the BST
 */
bst_t *bst_remove(bst_t *root, int value)
{
bst_t *tmp_node;

if (root == NULL)
    return (NULL);

if (value < root->n)
    root->left = bst_remove(root->left, value);
else if (value > root->n)
    root->right = bst_remove(root->right, value);
else
{
    if (root->left == NULL)
    {
        tmp_node = root->right;
        free(root);
        return (tmp_node);
    }
    else if (root->right == NULL)
    {
        tmp_node = root->left;
        free(root);
        return (tmp_node);
    }

    tmp_node = bst_find_min(root->right);
    root->n = tmp_node->n;

    root->right = bst_remove(root->right, tmp_node->n);
}

return root;
}
