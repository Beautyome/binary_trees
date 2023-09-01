#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right-child
 *                            of another in a binary tree.
 * @par: A pointer to the node to insert the right-child in.
 * @val: The value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 * Otherwise - a pointer to the new node.
 *
 * Description: If parent already has a right-child, the new node
 * takes its place and the old right-child is set as
 * the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *par, int val)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(par, val);
	if (new == NULL)
		return (NULL);

	if (par->right != NULL)
	{
		new->right = par->right;
		par->right->par = new;
	}
	par->right = new;

	return (new);
}
