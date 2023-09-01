#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @fir: Pointer to the first node to be found
 * @sec: Pointer to the second node to be found
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *fir,
		const binary_tree_t *sec)
{
	binary_tree_t *mom, *pop;

	if (!fir || !sec)
		return (NULL);
	if (fir == sec)
		return ((binary_tree_t *)fir);

	mom = fir->parent, pop = sec->parent;
	if (fir == pop || !mom || (!mom->parent && pop))
		return (binary_trees_ancestor(first, pop));
	else if (mom == sec || !pop || (!pop->parent && mom))
		return (binary_trees_ancestor(mom, sec));
	return (binary_trees_ancestor(mom, pop));
}
