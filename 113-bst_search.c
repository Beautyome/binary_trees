#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a binary search tree.
 * @tree: A pointer to the root node of the BST to search.
 * @val: The value to search for in the BST.
 *
 * Return: If the tree is NULL or the value is not found, NULL.
 * Otherwise, a pointer to the node containing the value.
 */
bst_t *bst_search(const bst_t *tree, int val)
{
	if (tree != NULL)
	{
		if (tree->n == val)
			return ((bst_t *)tree);
		if (tree->n > val)
			return (bst_search(tree->left, val));
		return (bst_search(tree->right, val));
	}
	return (NULL);
}
