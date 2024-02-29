#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, or NULL if node is NULL,
 *         has no parent, or no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	/* Check if grandparent has two children */
	if (node->parent->parent->left && node->parent->parent->right)
	{
	/* If node's parent is left child of grandparent, return right child */
		if (node->parent->parent->left == node->parent)
			return (node->parent->parent->right);

	/* If node's parent is right child of grandparent, return left child */
		if (node->parent->parent->right == node->parent)
			return (node->parent->parent->left);
	}
	return (NULL);
}
