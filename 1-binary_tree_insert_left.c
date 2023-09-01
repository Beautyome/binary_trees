#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of
 * of another in a binary tree.
 * @par: A pointer to the node to insert the left-child in.
 * @val: The value to store in the new node to be inserted
 *
 * Return: If parent is NULL or an error occurs - NULL.
 * Otherwise - a pointer to the new node.
 *
 * Description: If parent already has a left-child, the new node
 * takes its place and the old left-child is set as
 * the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *par, int val)
{
	binary_tree_t *new;

	if (par == NULL)
		return (NULL);

	new = binary_tree_node(par, val);
	if (new == NULL)
		return (NULL);

	if (par->left != NULL)
	{
		new->left = par->left;
		par->left->par = new;
	}
	par->left = new;

	return (new);
}
