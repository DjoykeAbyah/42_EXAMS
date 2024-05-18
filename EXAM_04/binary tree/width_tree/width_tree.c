
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:43:49 by exam              #+#    #+#             */
/*   Updated: 2019/03/26 11:50:55 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

static int	max_depth(struct s_node *node, int depth)
{
	int left = 0;
	int right = 0;

	if (!(node->left || node->right))
		return (depth);
	if (node->left)
		left = max_depth(node->left, depth + 1);
	if (node->right)
		right = max_depth(node->right, depth + 1);
	return ((left >= right) ? left : right);
}

static void	send_snake_down(struct s_node *node, int *ptr)
{
	int	left;
	int	right;

	left = (node->left) ? max_depth(node->left, 1) : 0;
	right = (node->right) ? max_depth(node->right, 1) : 0;
	if (left + right + 1 > *ptr)
		*ptr = left + right + 1;
	if (node->left)
		send_snake_down(node->left, ptr);
	if (node->right)
		send_snake_down(node->right, ptr);
}

int		width_tree(struct s_node *n)
{
	int	ptr = 0;
	if (!n)
		return (0);
	send_snake_down(n, &ptr);
	return (ptr);
}

// Assignment name  : width_tree
// Expected files   : width_tree.c
// Allowed functions:
// --------------------------------------------------------------------------------

// ALERT: OPTIMIZED SOLUTION REQUIRED.

// Given the root node of a binary tree, create a function that returns the
// 'width' of the tree, which is the number of node present on the longest
// path between two leaves in the tree.

// The binary tree uses the following node structure :

// struct s_node
// {
//         int value;
//         struct s_node *left;
//         struct s_node *right;
// };

// The function must be declared as follows:

// int        width_tree(struct s_node *n);

// Consideration:

// - Be careful: the naive solution won't work on our big input, you have to find
// an optimized solution which will run in O(N) time (where N is the number of nodes).
// - The values of each node does not matter.
// - The bigger test we will do is about 250 000 nodes. It should run in less
// than 2 seconds.

// Example 1:

//         1
//       /   \
//     2      \
//    / \       \
//  3    4       5
//      /       /  \
//     6       7    8

// In this case, your function should return 6,

// because the longest path between two leaves is 6->4->2->1->5->7 (or finish by 8),
// which contains 6 nodes, so the tree have a 'width' of 6.

// Example 2:

//          1
//        /  \
//      2     \
//     / \     3
//   4    \
//  / \    \
// 5   6    7
//  \      / \
//   8    9   10
//       / \    \
//      11   12  13

// In this case, your function should return 7,

// because the longest path between two leaves is 8->5->4->2->7->9->11 .

// Example 3:

// 10
//   \
//    12

// In this case, your function should return 2.

// Example 4:

//         25
//       /
//     33
//    / \
//  12   9
//      /
//     3
// In this case, your function should return 4.

// Example 5:

//   10
// (here is a root with no children)
// In this case, your function should return 1.