#include <stdlib.h>
#include <stdio.h>
#include <limits.h>//

typedef struct s_node {
    int           value;
    struct s_node *right;
    struct s_node *left;
}	t_node;

t_node *init_tree(t_node *branch, int value)
{
    branch = malloc(sizeof (t_node));
    branch->value = value;
    branch->left = NULL;
    branch->right = NULL;
    return (branch);
}

t_node *create_tree(t_node *tree, int value)
{
    t_node *return_tree;

    if (!tree)
    {
        return_tree = init_tree(tree, value);// init return_tree
        return (return_tree);//
    }
    if (value > tree->value)
        tree->left = create_tree(tree->left, value);//create left->tree
    else
        tree->right = create_tree(tree->right, value);//create right->tree
    return (tree); // in this case tree
}

void print_tree(t_node *tree, int spaces)
{
    spaces += 5;

    if (!tree)
        return ;
    print_tree(tree->right, spaces);
    printf("\n");//dont forget endline
    for (int i = 0; i < spaces; i++)
        printf(" ");
    printf("%d\n",tree->value);//dont forget to print endline with value
    print_tree(tree->left, spaces);
}

int tree_size(t_node *tree)
{
    int size;
    int left_size = 0;
    int right_size = 0;

    if (!tree)
        return (0);
    size = 1;
    if (tree->left)
        left_size = tree_size(tree->left);
    if (tree->right)
        right_size = tree_size(tree->right);
    size = size + right_size + left_size;
    return (size);
}

// int check(t_node *tree, int value)
// {
// 	if (tree)
// 	{
// 		if (tree->value > value)
// 			return (check(tree->left, value));
// 		else
// 			return (check(tree->right, value));
// 		if (tree->value == value)
// 		{
// 			printf("found\n");
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

int smallest_num(t_node *tree)
{
    if (!tree)
        return (INT_MAX);
}


int main()
{
    int spaces = 0;
    t_node *tree;

    tree = NULL;
    tree = create_tree(tree, 1);
    tree = create_tree(tree, 20);
    tree = create_tree(tree, 3);
    tree = create_tree(tree, 6);
    tree = create_tree(tree, 30);
    // check(tree, 3);
    // check(tree, 7);

    print_tree(tree, spaces);
    printf("size = %d\n", tree_size(tree));

}

// smallest num
// max num
// insert **
// find num WERKT NIET
// longest leg
// longest sequence
// size **
// swap

// width tree
// sort