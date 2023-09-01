#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root 	node of the BST to insert the value.
 * @val: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int val)
{
	bst_t *curr, *new;

	if (tree != NULL)
	{
		curr = *tree;

		if (curr == NULL)
		{
			new = binary_tree_node(curr, val);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}

		if (val < curr->n) /* insert in left subtree */
		{
			if (curr->left != NULL)
				return (bst_insert(&curr->left, val));

			new = binary_tree_node(curr, val);
			if (new == NULL)
				return (NULL);
			return (curr->left = new);
		}
		if (val > curr->n) /* insert in right subtree */
		{
			if (curr->right != NULL)
				return (bst_insert(&curr->right, val));

			new = binary_tree_node(curr, val);
			if (new == NULL)
				return (NULL);
			return (curr->right = new);
		}
	}
	return (NULL);
}
