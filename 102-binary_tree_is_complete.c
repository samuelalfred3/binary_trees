#include "binary_trees.h"

/**
 * create_queue_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_queue_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node = malloc(sizeof(levelorder_queue_t));

	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;
	return (new_node);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	while (head != NULL)
	{
		levelorder_queue_t *tmp = head;

		head = head->next;
		free(tmp);
	}
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	levelorder_queue_t *queue = create_queue_node((binary_tree_t *)tree);

	if (queue == NULL)
		return (0);

	int has_null_child = 0;

	while (queue != NULL)
	{
		binary_tree_t *node = queue->node;

		if (node->left != NULL)
		{
			if (has_null_child)
			{
				free_queue(queue);
				return (0);
			}
			queue->next = create_queue_node(node->left);
			if (queue->next == NULL)
			{
				free_queue(queue);
				return (0);
			}
			queue = queue->next;
		}
		else
		{
			has_null_child = 1;
		}
		if (node->right != NULL)
		{
			if (has_null_child)
			{
				free_queue(queue);
				return (0);
			}
			queue->next = create_queue_node(node->right);
			if (queue->next == NULL)
			{
				free_queue(queue);
				return (0);
			}
			queue = queue->next;
		}
		else
		{
			has_null_child = 1;
		}
		queue = queue->next;
	}
	return (1);
}

