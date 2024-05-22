#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
}	t_node;

t_node *init_tree(t_node *tree, int value)
{
	tree = malloc(sizeof(t_node));
	tree->value = value;
	tree->left = NULL;
	tree->right = NULL;
	return (tree);
}

t_node *create_tree(t_node *tree, int value)
{
	t_node *return_tree;

	return_tree = NULL;
	if (!tree)
	{
		return_tree = init_tree(return_tree, value);
		return (return_tree);
	}
	if (value > tree->value)
		tree->left = create_tree(tree->left, value);
	else
		tree->right = create_tree(tree->right, value);
	return (tree);
}

void print_tree(t_node *tree, int spaces)
{
	if (!tree)
		return ;
	spaces += 5;
	print_tree(tree->left, spaces);
	printf("\n");
	for (int i = 0; i < spaces; i++)
		printf(" ");
	printf("%d\n", tree->value);
	print_tree(tree->right, spaces);
}

int tree_size(t_node *tree)
{
	int left_size = 0;
	int right_size = 0;

	if (!tree)
		return (0);
	int size = 1;
	if (tree->left)
		left_size = tree_size(tree->left);
	if (tree->right)
		right_size = tree_size(tree->right);
	size = size + left_size + right_size;
	return (size);
}

int main()
{
	t_node *tree;
	int spaces = 0;

	tree = NULL;
	tree = create_tree(tree, 5);
	tree = create_tree(tree, 2);
	tree = create_tree(tree, 20);
	tree = create_tree(tree, 600);
	tree = create_tree(tree, 3);
	tree = create_tree(tree, 2);
	print_tree(tree, spaces);
	printf("size is %d\n", tree_size(tree));
}