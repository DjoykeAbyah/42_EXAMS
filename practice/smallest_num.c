#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_node 
{
    int           value;
    struct s_node *right;
    struct s_node *left;
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

int smallest_num(t_node *tree)
{
	int cur_num;

	if (!tree)
		return (INT_MAX);
	cur_num = tree->value;
	int left_min = smallest_num(tree->left);
	int right_min = smallest_num(tree->right);
	if (left_min < cur_num)
		cur_num = left_min;
	if (right_min < cur_num)
		cur_num = right_min;
	return (cur_num);
}

int main()
{
	t_node *tree;
	int spaces = 0;

	tree = NULL;
	tree = create_tree(tree, 6);
	tree = create_tree(tree, 70);
	tree = create_tree(tree, -3);
	tree = create_tree(tree, 50);
	tree = create_tree(tree, 99);
	tree = create_tree(tree, -5);
	tree = create_tree(tree, 1);
	print_tree(tree, spaces);
	printf("smallest num = %d\n", smallest_num(tree));
}