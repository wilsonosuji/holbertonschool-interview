#include "binary_trees.h"

static int NOMEM;

/**
 * maxheapify - swaps node n values so parent n is greater than child n values
 * @inserted: node n value being swapped
 */
void maxheapify(heap_t **inserted)
{
	heap_t *cur;
	int tmp;

	for (cur = *inserted; cur->parent; cur = cur->parent)
		if (cur->n > cur->parent->n)
		{
			tmp = cur->parent->n;
			cur->parent->n = cur->n;
			cur->n = tmp;
			*inserted = (*inserted)->parent;
		}
}

/**
 * popq - pops node from queue
 * @qnode: double pointer to queue node
 */
void popq(queue **qnode)
{
	queue *tmp;

	if (*qnode)
	{
		tmp = *qnode;
		*qnode = (*qnode)->next;
		free(tmp);
	}
}

/**
 * pushq - pushes address of cur to queue
 * @qnode: double pointer to queue node
 * @cur: pointer to cur node
 *
 * Return: pointer to newly created queue node
 */
queue *pushq(queue **qnode, heap_t *cur)
{
	queue **curq, *newq = malloc(sizeof(*newq));

	if (!newq)
		return (NULL);
	newq->node = cur;
	newq->next = NULL;

	curq = qnode;
	while (*curq)
		curq = &(*curq)->next;
	newq->next = *curq;
	*curq = newq;
	return (newq);
}

/**
 * pushinsert - pushes node to queue and inserts into binary tree
 * @cur: pointer to current node
 * @curq: double pointer to current queue node
 * @inserted: double pointer to inserted node
 * @dir: double pointer to cur direction
 * @value: value stored in the node to be inserted
 *
 * Return: pointer to inserted node
 */
heap_t *pushinsert(heap_t *cur, queue **curq, heap_t **inserted, heap_t **dir,
		   int value)
{
	if (*dir)
	{
		if (!pushq(curq, *dir))
			NOMEM = 1;
	}
	else
	{
		*dir = binary_tree_node(cur, value);
		if (!*dir)
			NOMEM = 1;
		*inserted = *dir;
	}
	return (*inserted);
}

/**
 * levelorder - traverses tree in level order
 * @root: double pointer to root node
 * @value: value stored in the node to be inserted
 *
 * Return: pointer to inserted node, or NULL on failure
 */
heap_t *levelorder(heap_t **root, int value)
{
	queue *curq = NULL;
	heap_t *inserted, *cur = *root;

	if (!pushq(&curq, cur))
		return (NULL);
	inserted = NULL;
	while (curq)
	{
		cur = curq->node;
		if (!inserted)
			pushinsert(cur, &curq, &inserted, &cur->left, value);
		if (!inserted)
			pushinsert(cur, &curq, &inserted, &cur->right, value);
		if (NOMEM)
			return (NULL);
		popq(&curq);
	}
	return (inserted);
}

/**
 * heap_insert - inserts a value into a max binary heap
 * @root: double pointer to the root node of the heap
 * @value: value stored in the node to be inserted
 *
 * Return: pointer to inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *inserted;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = binary_tree_node(*root, value);
		inserted = *root;
	}
	else
	{
		inserted = levelorder(root, value);
		maxheapify(&inserted);
	}
	return (inserted);
}
