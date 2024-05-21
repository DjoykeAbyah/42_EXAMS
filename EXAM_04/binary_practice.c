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

int smallest_num(t_node *tree, int current_min) 
{
    if (!tree)
        return (current_min);
    if (tree->value < current_min)
        current_min = tree->value;
    int left_min = smallest_num(tree->left, current_min);
    int right_min = smallest_num(tree->right, current_min);
	if (left_min < right_min)
		return (left_min);
	else if (right_min < left_min)
		return (right_min);
	return (right_min);
}

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
    print_tree(tree->right, spaces);
    printf("\n");
    for (int i = 0; i < spaces; i++)
        printf(" ");
    printf("%d\n", tree->value);
    print_tree(tree->left, spaces);
}

int biggest(t_node *tree) 
{
    if (!tree)
        return INT_MIN;
    int cur_val = tree->value;
    int left_val = biggest(tree->left);
    int right_val = biggest(tree->right);
    if (left_val > cur_val)
        cur_val = left_val;
    if (right_val > cur_val)
        cur_val = right_val;
    return cur_val;
}

int size(t_node *tree)
{
	int left = 0;
	int right = 0;
	int num = 0;

	if (!tree)
		return (num);
	num = 1;
	if (tree->left)
		left = size(tree->left);
	if (tree->right)
		right = size(tree->right);
	num = num + right + left;
	return (num);
}

void swap(t_node *tree)
{
	t_node *temp;

	if (tree)
	{
		swap(tree->left);
		swap(tree->right);
		temp = tree->left;
		tree->left = tree->right;
		tree->right = temp;
	}
}

int height(t_node *tree) {
    if (!tree)
        return (-1);
    int left_height = height(tree->left);
    int right_height = height(tree->right);
    int max_height;
    if (left_height > right_height) 
        max_height = left_height;
    else
        max_height = right_height;
    return 1 + max_height;
}

int findnum(t_node *tree, int value)
{
	if (tree)
	{
		if (tree->value > value)
			return (findnum(tree->left, value));
		else
			return (findnum(tree->right, value));
		if (tree->value == value)
		{
			write(1, "found\n", 6);
			return (0);
		}
	}
	return (1);
}


int longest_sequence(struct s_node *node) 
{
    if (!node)
        return 0;

    int seqleft = longest_sequence(node->left);
    int seqright = longest_sequence(node->right);
    int seq = 0;

    if (node->left && node->left->value == node->value + 1)
        seqleft++;
    else
        seqleft = 0;
    if (node->right && node->right->value == node->value + 1)
        seqright++;
    else
        seqright = 0;
    if (seq < seqleft + 1)
        seq = seqleft + 1;
    if (seq < seqright + 1)
        seq = seqright + 1;
    if (seqleft > seqright)
        return seqleft;
    else
        return seqright;
}

int main(void)
{
	t_node *tree;
	int spaces = 0;

	tree = NULL;
	tree = make_tree(tree, 1);
	tree = make_tree(tree, 20);
	tree = make_tree(tree, 5);
	tree = make_tree(tree, 14);
	tree = make_tree(tree, 52);
	tree = make_tree(tree, 11);
	tree = make_tree(tree, 30);
	print_tree(tree, spaces);
	printf("tree size = %d\n", size(tree));
	printf("smallest with  num = %d\n", smallest_num(tree, -1));
	printf("smallest is %d\n", smallest(tree));
	printf("biggest is %d\n", biggest(tree));
	printf("height = %d\n", height(tree));
	swap(tree);
	print_tree(tree, spaces);
	return 0;
}
// smallest num //
// max num	//
// insert //
// find num //
// longest leg //
// longest sequence //
// size //
// swap //
// make and insert
// width tree
// sort


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