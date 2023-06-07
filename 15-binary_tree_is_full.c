#include "binary_trees.h"

int check_full(const binary_tree_t *tree);

/**
 * binary_tree_is_full - a function that checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 otherwise 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree != NULL)
		return (check_full(tree));
	return (0);
}

/**
 * check_full - a function that check the fullness of a binary tree
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: 1 otherwise 0 if tree is NULL
 */
int check_full(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
				(tree->left == NULL && tree->right != NULL) ||
				(check_full(tree->left) == 0) ||
				(check_full(tree->right) == 0))
			return (0);
	}
	return (1);
}
