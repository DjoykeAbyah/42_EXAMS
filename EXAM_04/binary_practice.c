#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_node {
    int           value;
    struct s_node *right;
    struct s_node *left;
}	t_node;

t_node *init_tree(t_node *tree, int value)//
{
	tree = malloc(sizeof (t_node));
	if (tree == NULL)
		return (NULL);
	tree->value = value;
	tree->left = NULL;
	tree->right = NULL;
	return (tree);
}

void *make_tree(t_node *tree, int value)
{
	t_node *return_tree;//

	if (!tree)
		return (return_tree = init_tree(tree, value));//
	else if (value > tree->value)
		tree->left = make_tree(tree->left, value);//
	else
		tree->right = make_tree(tree->right, value);//
	return (tree);
}

// int smallest(t_node *tree, int num)
// {
// 	int num_left;
// 	int num_right;

// 	if (!tree)
// 		return (num);
// 	if (tree->left->value < tree->value)
// 		num_left = smallest(tree, num);
// 	if (tree->right->value < tree->value)
// 		num_right = smallest(tree, num);
// 	if (num_right < num_left)
// 		return(num_right);
// 	else
// 		return (num_left);	
// }

// int smallest(t_node *tree, int current_min) 
// {
//     if (!tree)
//         return (current_min);
//     if (tree->value < current_min)
//         current_min = tree->value;
//     int left_min = smallest(tree->left, current_min);
//     int right_min = smallest(tree->right, current_min);
// 	if (left_min < right_min)
// 		return (left_min);
// 	else if (right_min < left_min)
// 		return (right_min);
// 	return (right_min);
// }

int smallest(t_node *tree) 
{
    if (!tree)
        return INT_MAX;
    int current_min = tree->value;
    int left_min = smallest(tree->left);
    int right_min = smallest(tree->right);
    if (left_min < current_min)
        current_min = left_min;
    if (right_min < current_min)
        current_min = right_min;
    return current_min;
}



void print_tree(t_node *tree, int spaces) 
{
    if (!tree)
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

// smallest num
// max num	
// insert
// longest leg
// size
// swap
// count nodes


/*
    also appends/inserts
*/
// t_node *create_tree(t_node *tree, int value)
// {
// 	t_node *new_node;

// 	new_node = malloc(sizeof(t_node));
// 	new_node->value = value;
// 	new_node->right = NULL;
// 	new_node->left = NULL;
// 	if (!tree)
// 		return (new_node);
// 	if (tree->value > value)
// 		tree->left = create_tree(new_node, value);
// 	else
// 		tree->right = create_tree(new_node, value);
// 	return (tree);
// }

int main(void)
{
	t_node *tree;
	int spaces = 0;

	// // Initialize num directly
	// int num = INT_MAX; // Initialize num to the maximum possible integer value

	tree = NULL;
	tree = make_tree(tree, 5);
	tree = make_tree(tree, 20);
	tree = make_tree(tree, 1);
	tree = make_tree(tree, 14);
	tree = make_tree(tree, 52);
	tree = make_tree(tree, 11);
	tree = make_tree(tree, 13);
	print_tree(tree, spaces);	
	// Pass num to smallest function
	// printf("smallest is %d\n", smallest(tree, num));
	printf("smallest is %d\n", smallest(tree));
	return 0;
}