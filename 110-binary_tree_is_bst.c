#include "binary_trees.h"

/**
 * is_bst_util - Recursive helper function to check if a binary tree is a valid BST
 * @node: A pointer to the current node being checked
 * @min: The minimum value that the node's value can be
 * @max: The maximum value that the node's value can be
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);

	if (node->n < min || node->n > max)
		return (0);

	return (is_bst_util(node->left, min, node->n - 1) &&
			is_bst_util(node->right, node->n + 1, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst_util(tree, INT_MIN, INT_MAX));
}

