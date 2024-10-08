Assignment name  : longest_sequence
Expected files   : longest_sequence.c
Allowed functions:
--------------------------------------------------------------------------------

Given the root node of a binary tree, create a function that return the length of the longest path which comprises of nodes with consecutive values in increasing order.
Every node is considered as a path of length 1.

The binary tree uses the following node structure :

struct s_node
{
        int value;
        struct s_node *left;
        struct s_node *right;
};

The function must be declared as follows:

int        longest_sequence(struct s_node *node);


Example 1:

       10
       /
      5
     / \
    /   \
   6    9
  / \
 /   \
7   13

In this case, it should return 3 (because the longest consecutive sequence is: 5 -> 6 -> 7).

Example 2:

   5
  / \
 /   \
6     4
    /  \
   9    3
 /  \    \
3    2    2

In this case, your function return 2 (because the longest consecutive sequence is: 5 -> 6 ).

Example 3:

    30
    / \
   /   \
  15   41
 /     /
61    80

In this case, it should return 1.

Example 4:

NULL

In this case, as the root node is null, your function should return 0.