#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *nnode, *hld;

	if (tree != NULL)
	{
		hld = *tree;
		if (hld == NULL)
		{
			nnode = binary_tree_node(hld, value);
			if (nnode == NULL)
				return (NULL);
			return (*tree = nnode);
		}
		if (value < hld->n)
		{
			if (hld->left != NULL)
				return (bst_insert(&hld->left, value));
			nnode = binary_tree_node(hld, value);
			if (nnode == NULL)
				return (NULL);
			return (hld->left = nnode);
		}
		if (value > hld->n)
		{
			if (hld->right != NULL)
				return (bst_insert(&hld->right, value));
			nnode = binary_tree_node(hld, value);
			if (nnode == NULL)
				return (NULL);
			return (hld->right = nnode);
		}
	}
	return (NULL);
}
