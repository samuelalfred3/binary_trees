#include "binary_trees.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * queue_push - Pushes a node into a level-order traversal queue
 * @queue: Pointer to the pointer to the queue
 * @node: Pointer to the node to push into the queue
 *
 * Return: Pointer to the created queue node
 */
levelorder_queue_t *queue_push(levelorder_queue_t **queue, const binary_tree_t *node)
{
	levelorder_queue_t *new_node, *temp;

	new_node = malloc(sizeof(levelorder_queue_t));
	if (new_node == NULL)
		return (NULL);

	new_node->node = (binary_tree_t *)node;
	new_node->next = NULL;

	if (*queue == NULL)
	{
		*queue = new_node;
	}
	else
	{
		temp = *queue;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}

	return (new_node);
}

/**
 * queue_pop - Pops a node from a level-order traversal queue
 * @queue: Pointer to the pointer to the queue
 *
 * Return: Pointer to the popped node
 */
binary_tree_t *queue_pop(levelorder_queue_t **queue)
{
	levelorder_queue_t *temp;
	binary_tree_t *node;

	if (*queue == NULL)
		return (NULL);

	temp = *queue;
	*queue = (*queue)->next;
	node = temp->node;
	free(temp);

	return (node);
}

/**
 * binary_tree_levelorder - Performs a level-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each visited node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *queue = NULL;

	if (tree == NULL || func == NULL)
		return;

	queue_push(&queue, tree);

	while (queue != NULL)
	{
		const binary_tree_t *temp = queue_pop(&queue);

		func(temp->n);
		if (temp->left != NULL)
			queue_push(&queue, temp->left);
		if (temp->right != NULL)
			queue_push(&queue, temp->right);
	}
}

