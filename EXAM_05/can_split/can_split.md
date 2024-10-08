Assignment name  : can_split
Expected files   : can_split.c
Allowed functions:
--------------------------------------------------------------------------------
ALERT: OPTIMIZED SOLUTION REQUIRED.
Given the root node of a binary tree, create a function that returns 1 if, by
removing one edge of the tree, it can be splitted in two trees with the same
number of nodes (same 'size').
The binary tree uses the following node structure :
struct s_node
{
    int value;
    struct s_node *left;
    struct s_node *right;
};
The function must be declared as follows:
int can_split(struct s_node *n);
Consideration:
- Be careful: the naive solution won't work on our big input, you have to find
an optimized solution which will run in O(N) time (where N is the number of nodes).
- The bigger test we will do is about 250 000 nodes. It should run in less
than 2 seconds.
Example 1:
       28
       /
      51
     / \
    /   \
   26   48
  / \
 /   \
76   13
In this case, it should return 1 (remove the edge between 51 and 26 will split the tree
in 2 trees with each a size of 3).
Example 2:
    30
    / \
   /   \
  15   41
 /     /
61    80
In this case, it should return 0 (you can't split the tree and make 2 trees with the
same size).
Example 3:
10
  \
   12
In this case, your function return 1.
Example 4:
   5
  / \
 /   \
1     6
    /  \
   7    4
 /  \    \
3    2    8
In this case, your function should return 0.