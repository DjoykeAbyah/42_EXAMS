/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perimiter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mtaylor <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/02 14:27:00 by mtaylor       #+#    #+#                 */
/*   Updated: 2024/05/15 01:20:38 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define	LEAF(n)	(!n->left && !n->right)

struct s_node {
	int				value;
	struct s_node	*right;
	struct s_node	*left;
};

static void	leaf_nodes(struct s_node *n)
{
	if (n)
	{
		if (LEAF(n))
			printf(" %d", n->value);
		else
		{
			leaf_nodes(n->left);
			leaf_nodes(n->right);
		}
	}
}

static void	leftmost_nodes(struct s_node *n)
{
	if (n && !LEAF(n))
	{
		printf(" %d", n->value);
		leftmost_nodes(n->left);
	}
}

static void	rightmost_nodes(struct s_node *n)
{
	if (n && !LEAF(n))
	{
		rightmost_nodes(n->right);
		printf(" %d", n->value);
	}
}

/*
**	leftmost() & rightmost() can't be leaf nodes,
**		and are not run on the root.
**	But I DO need to protect against double-printing
**		root that is also a leaf node.
*/
void	perimeter(struct s_node *root)
{
	if (root)
	{
		printf("%d", root->value);
		if (!LEAF(root))
		{
			leftmost_nodes(root->left);
			leaf_nodes(root);
			rightmost_nodes(root->right);
		}
		printf("\n");
	}
}




// Assignment name  : perimeter
// Expected files   : perimeter.c
// Allowed functions: printf
// --------------------------------------------------------------------------------

// Implement a function which prints the perimeter of a binary tree.

// The perimeter is defined as follows :
// - leftmost nodes from top to bottom
// - leaf nodes from left to right
// - rightmost nodes from bottom to top

// The binary tree uses the following node structure :

//         struct s_node {
//                 int           value;
//                 struct s_node *right;
//                 struct s_node *left;
//         };

// The function prints on the standard output the value of the nodes
// seperated by a single space and with a new line at the end.

// The function must be declared as follows:

//         void perimeter(struct s_node *root);


// EXAMPLE :

//         For the following tree :

//                          92
//                          / \
//                         /   \
//                        85   26
//                       /       \
//                      79       64
//                       \       / \
//                       10     /   \
//                       /     /     \
//                      39    /       \
//                     /     /         \
//                    35    /           \
//                   /     /             \
//                  96    /               \
//                       /                 \
//                      40                 78
//                     / \                 / \
//                    /   \               /   \
//                   /     \             2    85
//                  /       \           / \     \
//                 /         \         /   \    51
//                /           \       /     \
//               /             \     33     11
//              88             10     \     /
//             / \             / \    55   99
//            /   \           /   \
//           12   55         52   87
//          /     / \       / \     \
//         58    /   \     /   \    31
//              58   41   22   35

//         the output would be :

//         92 85 79 96 58 58 41 22 35 31 55 99 51 85 78 64 26