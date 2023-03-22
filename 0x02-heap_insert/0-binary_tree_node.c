#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_node - Add a new node in a binary tree
 *
 * @value: Integer stored in the node
 * @parent: Pointer to the parent node
 *
 * Return: a pointer to the new node, or NULL on failure
 **/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	return (new_node);
}
