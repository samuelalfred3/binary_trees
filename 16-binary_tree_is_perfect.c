#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the binary tree. If tree is NULL, your function
 * must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	return (right_height + 1);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: A pointer to the root node of the tree to measure the size.
 *
 * Return: The size of the binary tree. If tree is NULL, the function must
 * return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the binary tree is full, 1. Otherwise, 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if ((tree->left) && (tree->right))
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the binary tree is perfect, 1. Otherwise, 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	return (binary_tree_is_full(tree) && ((1 << (int)height) - 1 == size));
}

