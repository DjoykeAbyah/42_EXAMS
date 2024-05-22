#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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

int find_num(t_node *tree, int value)
{
    if (tree)
    {
        if (tree->value < value)//mind the order of creating!
            return find_num(tree->left, value);
        else if (tree->value > value)
            return find_num(tree->right, value);
        else
        {
            write(1, "found\n", 6);
            return 0;
        }
    }
    return 1;
}

int main()
{
	t_node *tree;
	int spaces = 0;

	tree = NULL;
	tree = create_tree(tree, 8);
	tree = create_tree(tree, 5);
	tree = create_tree(tree, -44);
	tree = create_tree(tree, 2);
	tree = create_tree(tree, 99);
	tree = create_tree(tree, 1);
	tree = create_tree(tree, 50);
	find_num(tree, 2);
	print_tree(tree, spaces);
}
