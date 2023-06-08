#include "binary_trees.h"

int bst_check(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 otherwise 0 if tree is not a valid BST or NULL.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bst_check(tree, INT_MIN, INT_MAX));
}

/**
 * bst_check - check for valid Binary Search Tree.
 * @tree: pointer to root node of tree
 * @min: smallest node visited
 * @max: largest node visited
 *
 * Return: 1 if Tree is BST otherwise 0.
 */
int bst_check(const binary_tree_t *tree, int min, int max)
{
	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
			return (0);
		return (bst_check(tree->left, min, tree->n - 1) &&
				bst_check(tree->right, tree->n + 1, max));
	}
	return (1);
}
