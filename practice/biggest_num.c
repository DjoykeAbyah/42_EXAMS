#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

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
	print_tree(tree->right, spaces);
	printf("\n");
	for (int i = 0; i < spaces; i++)
		printf(" ");
	printf("%d\n", tree->value);
	print_tree(tree->left, spaces);
}

int biggest_num(t_node *tree)
{
	int cur_num;
	int left_biggest = 0;
	int right_biggest = 0;

	if (!tree)
		return (INT_MIN);
	cur_num = tree->value;
	left_biggest = biggest_num(tree->left);
	right_biggest = biggest_num(tree->right);
	if (left_biggest > cur_num)
		cur_num = left_biggest;
	if (right_biggest > cur_num)
		cur_num = right_biggest;
	return (cur_num);
}

int main()
{
	t_node *tree;
	int spaces = 0;

	tree = NULL;
	tree = create_tree(tree, 5);
	tree = create_tree(tree, 6);
	tree = create_tree(tree, 90);
	tree = create_tree(tree, 8);
	tree = create_tree(tree, 15);
	tree = create_tree(tree, 1);
	tree = create_tree(tree, 100);
	print_tree(tree, spaces);
	printf("biggest number = %d\n", biggest_num(tree));
}