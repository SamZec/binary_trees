#include "binary_trees.h"

/**
 * binary_trees_ancestor - a function that finds the lowest
 *		common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 *		otherwise NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (first != NULL && second != NULL)
	{
		if (second->parent == first->parent)
			return (second->parent);
		if (second == first->parent)
			return (second->parent);
		if (second->parent == first->parent->parent)
			return (second->parent);
	}
	return (NULL);
}
