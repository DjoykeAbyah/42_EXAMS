// Assignment name  : reverse_tree
// Expected files   : reverse_tree.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Implement a function to reverse a binary tree (i.e., flip it from right to left).

// You must declare the following node structure for the binary tree in your code:


//         struct s_node {
//                 int           value;
//                 struct s_node *right;
//                 struct s_node *left;
//         };


// The function must be declared as follows:

//         void reverse_tree(struct s_node *root);

// You must include the struct in your file.

// EXAMPLE :

//         The following tree :

//                94
//                / \
//               /   \
//              34   52
//             / \
//            /   \
//           1    99
//          /     / \
//         20    /   \
//              /     \
//             83     39
//              \     / \
//              61   /   \
//                  37   67

//         would become :

//               94
//               / \
//              /   \
//             52   34
//                  / \
//                 /   \
//                99    1
//               / \     \
//              /   \    20
//             /     \
//            39     83
//           / \     /
//          /   \   61
//         67   37