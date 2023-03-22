#include "binary_trees.h"
/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 *
 * @array: Array Integer for sort to AVL
 * @size: size of Array
 *
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;

	if (array == NULL)
	{
		return (NULL);
	}

	tree = search_avl_tree(array, 0, size - 1, NULL);
	return (tree);
}

/**
 * search_avl_tree - function that validate and sort the tree
 *
 * @array: Array Integer for sort to AVL
 * @initial: Start of array
 * @final: End of array
 * @node: node parent
 *
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *search_avl_tree(int *array, int initial, int final, avl_t *node)
{
	int half;
	avl_t *new_node;

	if (initial > final)
	{
		return (NULL);
	}

	new_node = malloc(sizeof(avl_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	half = (initial + final) / 2;

	new_node->n = array[half];
	new_node->parent = node;
	new_node->left = search_avl_tree(array, initial, half - 1, new_node);
	new_node->right = search_avl_tree(array, half + 1, final, new_node);

	return (new_node);
}
