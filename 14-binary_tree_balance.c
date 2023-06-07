#include "binary_trees.h"

size_t tree_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - a function that measures the balance factor of a tree.
 * @tree: a pointer to the root node of the tree to measure balance factor.
 *
 * Return: measured balance (int) otherwise 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree != NULL)
		return (tree_height(tree->left) - tree_height(tree->right));
	return (0);
}

/**
 * tree_height - a function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: height otherwise 0 if tree is NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree != NULL)
	{
		left = tree->left ? 1 + tree_height(tree->left) : 1;
		right = tree->right ? 1 + tree_height(tree->right) : 1;
		return ((left > right) ? left : right);
	}
	return (0);
}
