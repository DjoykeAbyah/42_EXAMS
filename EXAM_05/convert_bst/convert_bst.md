Assignment name  : convert_bst
Expected files   : convert_bst.c
Allowed functions:
--------------------------------------------------------------------------------
A binary search tree (BST) is a binary tree in which every node fits
a specific ordering property :
all left descendants <= n < all right descendants
This must be true for each node n.
Implement a function to convert a binary search tree to a sorted, circular,
doubly-linked list.
This conversion must be in-place (using the tree nodes as the new list nodes).
The binary search tree uses the following node structure :
    struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
    };
The function must be declared as follows:
    struct s_node *convert_bst(struct s_node *bst);
The function must return a pointer to the smallest element of the sorted,
circular, doubly-linked list.
For each node of the linked list, the right pointer points to the next node
and the left pointer points to the previous node.
The sort is in increasing order.