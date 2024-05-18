
// #include <stdlib.h>
// #include <stdio.h>

struct s_node
{
	int           value;
	struct s_node **nodes;
};

struct s_node	*create_node(int val)
{
	struct s_node	*new;
	int				i;

	new = malloc(sizeof(*new));
	new->value = val;
	new->nodes = malloc(sizeof(*new->nodes) * 4);
	i = -1;
	while (++i < 4)
		new->nodes[i] = 0;
	return (new);
}

int height_tree(struct s_node *root)
{
	int	ht;
	int	httmp;
	int	i;

	/* initialize height as 0 in each call of the recursion */
	ht = 0;
	if (!(root))
		return (-1);
	i = 0;
	/* height will be incremented on all levels except lowest one.
	 * this way we will discount 1 ht, because edges = (levels - 1) */
	if (root->nodes)
	{
		while (root->nodes[i])
		{
			/* store the return of the recursion in httmp.
			 * only overwrite ht if the result is bigger */
			httmp = 1 + height_tree(root->nodes[i]);
			ht = (httmp > ht) ? httmp : ht;
			i++;
		}
	}
	return (ht);
}

/*
int	main()
{
	struct s_node	*root;
	int				i;
	int				val;

	root = create_node(1);
	val = 2;
	i = -1;
	while (++i < 3)
	{
		root->nodes[i] = create_node(val);
		val++;
	}
	root->nodes[0]->nodes[0] = create_node(10);
	root->nodes[1]->nodes[0] = create_node(20);
	root->nodes[1]->nodes[0]->nodes[0] = create_node(30);

	printf("%i\n", height_tree(root));
}
*/


// Assignment name  : height_tree
// Expected files   : height_tree.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Implement a function to calculate the height of an n-ary tree.

// Your should use the following node structure in your code for the n-ary tree:

//         struct s_node {
//                 int           value;
//                 struct s_node **nodes;
//         };

// In this struct nodes is a null-terminated array.

// Note that the height of a tree is the number of EDGES on the longest path from
// the root node to a leaf. A tree with a single node will have a height of 0.

// An empty tree should have height -1;

// The function must be declared as follows:

//         int height_tree(struct s_node *root);

// EXAMPLE:

// The Input Tree :

//            94
//            / \
//           /   \
//          34   52
//         / \     \
//        /   \     \
//       1    99    11
//                  /
//                 /
//                13
// Output : 3


//https://github.com/ruv1nce/42-exam_intermediate/blob/master/str_maxlenoc.subject