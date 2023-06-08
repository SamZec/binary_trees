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
	binary_tree_t *parent, *temp;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	parent = first->parent, temp = second->parent;
	if (first == temp || !parent || (!parent->parent && temp))
		return (binary_trees_ancestor(first, temp));
	else if (parent == second || !temp || (!temp->parent && parent))
		return (binary_trees_ancestor(parent, second));
	return (binary_trees_ancestor(parent, temp));
}
