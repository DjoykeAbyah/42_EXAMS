//height tree

To implement a function that calculates the height of an n-ary tree, we need to adapt our approach to handle nodes with multiple children stored in a null-terminated array. The height is defined as the number of edges on the longest path from the root to a leaf. Here's the step-by-step plan:

1. Define the structure `struct s_node` to represent a node in the n-ary tree.
2. Implement the `height_tree` function to calculate the height of the tree recursively.
3. Ensure the function correctly handles the null-terminated array of child nodes.

Here's the implementation:

```c
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the n-ary tree node
struct s_node {
    int value;
    struct s_node **nodes; // Null-terminated array of child nodes
};

// Function to calculate the height of the tree
int height_tree(struct s_node *root) {
    if (!root) {
        return -1; // Height of an empty tree is -1
    }
    
    int max_child_height = -1;
    for (int i = 0; root->nodes[i] != NULL; i++) {
        int child_height = height_tree(root->nodes[i]);
        if (child_height > max_child_height) {
            max_child_height = child_height;
        }
    }
    
    return 1 + max_child_height;
}

// Helper function to create a new node
struct s_node* new_node(int value) {
    struct s_node* node = (struct s_node*)malloc(sizeof(struct s_node));
    node->value = value;
    node->nodes = (struct s_node**)malloc(sizeof(struct s_node*));
    node->nodes[0] = NULL; // Null-terminated array of child nodes
    return node;
}

// Helper function to add a child to a node
void add_child(struct s_node* parent, struct s_node* child) {
    int i;
    for (i = 0; parent->nodes[i] != NULL; i++);
    parent->nodes = (struct s_node**)realloc(parent->nodes, (i + 2) * sizeof(struct s_node*));
    parent->nodes[i] = child;
    parent->nodes[i + 1] = NULL;
}

// Test function (for demonstration purposes)
int main() {
    // Create example tree:
    //       94
    //       / \
    //      /   \
    //     34   52
    //    / \     \
    //   /   \     \
    //  1    99    11
    //             /
    //            /
    //           13
    
    struct s_node* root = new_node(94);
    struct s_node* node34 = new_node(34);
    struct s_node* node52 = new_node(52);
    struct s_node* node1 = new_node(1);
    struct s_node* node99 = new_node(99);
    struct s_node* node11 = new_node(11);
    struct s_node* node13 = new_node(13);
    
    add_child(root, node34);
    add_child(root, node52);
    add_child(node34, node1);
    add_child(node34, node99);
    add_child(node52, node11);
    add_child(node11, node13);
    
    printf("Height of the tree: %d\n", height_tree(root)); // Should output 3

    // Free allocated memory (not shown here but should be done in a real program)
    return 0;
}
```

### Explanation:

- **struct s_node**: Defines a node in the n-ary tree with a value and a null-terminated array of child nodes.
- **height_tree**: Recursively calculates the height of the tree:
  - If the root is `NULL`, it returns `-1`.
  - Iterates through each child, calculating their heights and tracking the maximum height among them.
  - Returns `1 + max_child_height` to account for the current node.
- **new_node**: Allocates and initializes a new tree node with a value and a null-terminated array of children.
- **add_child**: Adds a child to a given parent node, ensuring the array of children remains null-terminated.
- **main**: Constructs an example tree and prints its height, which should match the provided example output of `3`.