#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *par,
		avl_t **new, int val);
avl_t *avl_insert(avl_t **tree, int val);

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t a = 0, b = 0;

		a = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		b = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((a > b) ? a : b);
	}
	return (0);
}

/**
 * balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @par: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @val: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *par,
		avl_t **new, int val)
{
	int bfactor;

	if (*tree == NULL)
		return (*new = binary_tree_node(par, val));

	if ((*tree)->n > val)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, val);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < val)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, val);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bfactor = balance(*tree);
	if (bfactor > 1 && (*tree)->left->n > val)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && (*tree)->right->n < val)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfactor > 1 && (*tree)->left->n < val)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfactor < -1 && (*tree)->right->n > val)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @val: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int val)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, val);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, val);
	return (new);
}
