struct s_node
{
	int           value;
	struct s_node *right;
	struct s_node *left;
};

struct s_node	*bst_min(struct s_node *root)
{
	while (root->left)
		root = root->left;
	return (root);
}

struct s_node	*bst_max(struct s_node *root)
{
	while (root->right)
		root = root->right;
	return (root);
}

void			in_trav(struct s_node *root, struct s_node *min, struct s_node *max)
{
	static struct s_node	*prev;

	if (root)
	{
		/* prevent from traversing left from min (it points to max) */
		if (root != min)
			in_trav(root->left, min, max);
		/* update links for all nodes except min (for min prev == 0 ) */
		if (prev)
		{
			prev->right = root;
			root->left = prev;
		}
		/* set prev to current node */
		prev = root;
		/* prevent from traversing right from max (it points to min) */
		if (root != max)
			in_trav(root->right, min, max);
	}
}	

struct s_node	*convert_bst(struct s_node *bst)
{
	struct s_node	*min;
	struct s_node	*max;

	if (!bst)
		return (bst);
	min = bst_min(bst);
	max = bst_max(bst);
	min->left = max;
	max->right = min;
	in_trav(bst, min, max);
	return (min);
}

// Assignment name  : convert_bst
// Expected files   : convert_bst.c
// Allowed functions:
// --------------------------------------------------------------------------------
// A binary search tree (BST) is a binary tree in which every node fits
// a specific ordering property :
// all left descendants <= n < all right descendants
// This must be true for each node n.
// Implement a function to convert a binary search tree to a sorted, circular,
// doubly-linked list.
// This conversion must be in-place (using the tree nodes as the new list nodes).
// The binary search tree uses the following node structure :
//     struct s_node {
//         int           value;
//         struct s_node *right;
//         struct s_node *left;
//     };
// The function must be declared as follows:
//     struct s_node *convert_bst(struct s_node *bst);
// The function must return a pointer to the smallest element of the sorted,
// circular, doubly-linked list.
// For each node of the linked list, the right pointer points to the next node
// and the left pointer points to the previous node.
// The sort is in increasing order.