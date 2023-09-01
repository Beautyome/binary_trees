#include "binary_trees.h"

/**
 * binary_tree_node - Creates a node of a binary tree
 * @parent: A pointer to the parent of the node to created
 * @val: The value to put in the new node created
 *
 * Return: If an error occurs - NULL.
 * Otherwise - a pointer to the new node created
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int val)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = val;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
