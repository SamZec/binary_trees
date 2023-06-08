#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Retrun:  pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *point, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	point = tree->right;
	temp = point->left;
	point->left = tree;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = point;
	point->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = point;
		else
			temp->right = point;
	}
	return (point);
}
