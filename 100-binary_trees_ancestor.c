#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node,
 *         or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,const binary_tree_t *second)
{
	const binary_tree_t *ancestor = NULL;
	size_t depth_first = 0, depth_second = 0;

	if (first == NULL || second == NULL)
		return (NULL);

	/* Calculate the depth of each node */
	for (ancestor = first; ancestor != NULL; ancestor = ancestor->parent)
		depth_first++;
	for (ancestor = second; ancestor != NULL; ancestor = ancestor->parent)
		depth_second++;
	/* Move the deeper node up to the same depth as the shallower node */
	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}
	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}
	/* Move both nodes up until they meet at the common ancestor */
	while (first != second)
	{
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}
