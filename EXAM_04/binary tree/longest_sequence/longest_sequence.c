
#include <stdio.h>
#include <stdlib.h>

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};


// int longest_sequence(struct s_node *node) 
// {
//     if (!node)
//         return 0;

//     int seqleft = longest_sequence(node->left);
//     int seqright = longest_sequence(node->right);
//     int seq = 0;

//     if (node->left && node->left->value == node->value + 1)
//         seqleft++;
//     else
//         seqleft = 0;
//     if (node->right && node->right->value == node->value + 1)
//         seqright++;
//     else
//         seqright = 0;
//     if (seq < seqleft + 1)
//         seq = seqleft + 1;
//     if (seq < seqright + 1)
//         seq = seqright + 1;
//     if (seqleft > seqright)
//         return seqleft;
//     else
//         return seqright;
// }

int longest_sequence(struct s_node *node)
{
	int right;
	int left;

	if (!node)
		return (0);
	if (node->right && node->right->value == node->value + 1)
	{
		right = (1 + longest_sequence(node->right));
	}
	if (node->left && node->left->value == node->value + 1)
	{
		left = (1 + longest_sequence(node->left));
	}
	if (right > left)
		return (1 + longest_sequence(node->right));
	else
		return (1 + longest_sequence(node->left));
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

int	main()
{
	struct s_node	*root;
	int spaces = 0;
	root = malloc(sizeof(*root));
	root->value = 10;
	root->left = malloc(sizeof(struct s_node));
	root->left->value = 5;
	root->left->left = malloc(sizeof(struct s_node));
	root->left->left->value = 6;
	root->left->right = malloc(sizeof(struct s_node));
	root->left->right->value = 9;
	root->left->right->left = root->left->right->right = NULL;
	root->left->left->left = malloc(sizeof(struct s_node));
	root->left->left->left->value = 7;
	root->left->left->left->left = root->left->left->left->right = NULL;
	root->left->left->right = malloc(sizeof(struct s_node));
	root->left->left->right->value = 13;
	root->left->left->right->left = root->left->left->right->right = NULL;

	root->right = NULL;

	root->right = malloc(sizeof(struct s_node));
	root->right->value = 11;
	root->right->left = malloc(sizeof(struct s_node));
	root->right->left->value = 12;
	root->right->right = NULL;
	root->right->left->left = malloc(sizeof(struct s_node));
	root->right->left->left->value = 13;
	root->right->left->right = NULL;
	root->right->left->left->right = malloc(sizeof(struct s_node));
	root->right->left->left->right->value = 14;
	root->right->left->left->left = NULL;
	root->right->left->left->right->left = root->right->left->left->right->right = NULL;

	print_tree(root, spaces);
	printf("%i\n", longest_sequence(root));
}


// Assignment name  :                                           
// Expected files   : longest_sequence.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Given the root node of a binary tree, create a function that return the length of the longest path which comprises of nodes with consecutive values in increasing order.
// Every node is considered as a path of length 1.

// The binary tree uses the following node structure :

// struct s_node
// {
//         int value;
//         struct s_node *left;
//         struct s_node *right;
// };

// The function must be declared as follows:

// int        longest_sequence(struct s_node *node);


// Example 1:

//        10
//        /
//       5
//      / \
//     /   \
//    6    9
//   / \
//  /   \
// 7   13

// In this case, it should return 3 (because the longest consecutive sequence is: 5 -> 6 -> 7).

// Example 2:

//    5
//   / \
//  /   \
// 6     4
//     /  \
//    9    3
//  /  \    \
// 3    2    2

// In this case, your function return 2 (because the longest consecutive sequence is: 5 -> 6 ).

// Example 3:

//     30
//     / \
//    /   \
//   15   41
//  /     /
// 61    80

// In this case, it should return 1.

// Example 4:

// NULL

// In this case, as the root node is null, your function should return 0.