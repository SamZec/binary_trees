#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return:  pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *point, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);
	point = tree->left;
	temp = point->right;
	point->right = tree;
	tree->left = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = point;
	point->parent = temp;
	if (temp != NULL)
	{
		if (temp->right == tree)
			temp->right = point;
		else
			temp->left = point;
	}
	return (point);
}
