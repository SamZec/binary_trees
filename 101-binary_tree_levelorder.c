#include "binary_trees.h"

/**
 * binary_tree_levelorder - a function that goes through a
 *				binary tree using level-order traversal
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node.
 *
 * Return: value in node otherwise nothing if tree or func is NULL
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{

	binary_tree_t *queue[1024];
	binary_tree_t *tmp;
	int i = 0, j = 0;

	if (tree == NULL || func == NULL)
		return;
	for (i = 0; i < 1024; i++)
		queue[i] = NULL;
	queue[0] = (binary_tree_t *)tree;
	i = 0;
	while (queue[i] != NULL)
	{
		tmp = queue[i];
		func(tmp->n);
		if (tmp->left != NULL)
		{
			j++;
			queue[j] = tmp->left;
		}
		if (tmp->right != NULL)
		{
			j++;
			queue[j] = tmp->right;
		}
		i++;
	}
}
