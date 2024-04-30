#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
    int           value;
    struct s_node *right;
    struct s_node *left;
}	t_node;


t_node *init_tree(t_node *tree, int value)
{
	if (!tree)
	{
		tree = malloc(sizeof(t_node));
		if (!tree)
			return(NULL);
		tree->value = value;
		tree->right = NULL;
		tree->left = NULL;
	}
	return (tree);
}

/*
    also appends/inserts
*/
t_node *create_tree(t_node *tree, int value)
{
	t_node *return_tree;

	if (!tree)
	{
		return (return_tree = init_tree(tree, value));
	}
	if (tree->value > value)
		tree->left = create_tree(tree->left, value);
	else
		tree->right = create_tree(tree->right, value);
	return (tree);
}

void print_tree(t_node *tree, int spaces) 
{
    if (tree == NULL)
	{
        return;
	}
	spaces += 5;
    print_tree(tree->left, spaces);
    printf("\n");
    for (int i = 0; i < spaces; i++)
        printf(" ");
    printf("%d\n", tree->value);
    print_tree(tree->right, spaces);
}

int	size_tree(t_node *tree)
{

	int	size = 0;

	if (!tree)
		return (0);
	size += 1;
	if (tree->left)
		size += size_tree(tree->left);
	if (tree->right)
		size += size_tree(tree->right);
	return (size);
}

int	longest_tree(t_node *tree)
{

	int	size = 0;
	int right_size;
	int left_size;

	if (!tree)
		return (0);
	size += 1;
	if (tree->left)
	{
		size += size_tree(tree->left);
		left_size = size;
	}
	if (tree->right)
	{
		size += size_tree(tree->right);
		right_size = size;
	}
	if (right_size > left_size)
		return (right_size);
	return (left_size);
}

int check(t_node *tree, int value)
{
	if (tree)
	{
		if (tree->value > value)
			check(tree->left, value);
		else
			check(tree->right, value);
		if (tree->value == value)
		{
			printf("found");
			return (1);
		}
	}
	return (0);
}

void swap_tree(t_node *tree)
{
	t_node *temp;

	if (tree)
	{
		swap_tree(tree->left);
		swap_tree(tree->right);
		temp = tree->right;
		tree->right = tree->left;
		tree->left = temp;
	}
}

int main(void)
{
	t_node *tree;
	int spaces = 0;

	tree = NULL;
	tree = create_tree(tree, 94);
	tree = create_tree(tree, 34);
	tree = create_tree(tree, 93);
	tree = create_tree(tree, 100);
	tree = create_tree(tree, 101);
	print_tree(tree, spaces);
	swap_tree(tree);
	// print_tree(tree, spaces);
	// check(tree, 34);
	print_tree(tree, spaces);
}