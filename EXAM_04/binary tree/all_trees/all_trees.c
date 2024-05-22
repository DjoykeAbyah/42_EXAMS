#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_node {
    int           value;
    struct s_node *right;
    struct s_node *left;
}	t_node;

t_node *init(t_node *tree, int value)
{
    tree = malloc(sizeof(t_node));
    tree->value = value;
    tree->left = NULL;
    tree->right = NULL;
    return (tree);
}

t_node *create(t_node *tree, int num)
{
    t_node *return_tree;

    return_tree = NULL;
    if (!tree)
    {
        return_tree = init(return_tree, num);
        return (return_tree);
    }
    if (tree->value > num)
        tree->left = create(tree->left, num);
    else
        tree->right = create(tree->right, num);
    return (tree);
}

void print_tree(t_node *tree, int spaces)
{
    if (!tree)
        return ;
    spaces += 5;// +=!!!!!!!!!!
    print_tree(tree->right, spaces);
    printf("\n");
    for(int i = 0; i < spaces; i++)
        printf(" ");
    printf("%d\n", tree->value);
    print_tree(tree->left, spaces);
}

int smallest(t_node *tree)
{
    if (!tree)
        return (INT_MAX);
    int cur_small = tree->value;
    int left_small = smallest(tree->left);
    int right_small = smallest(tree->right);
    if (left_small < cur_small)
        cur_small = left_small;
    if (right_small < cur_small)
        cur_small = right_small;
    return (cur_small);
}

int biggest(t_node *tree)
{
    if (!tree)
        return(INT_MIN);
    int cur_max = tree->value;
    int left_max = biggest(tree->left);
    int right_max = biggest(tree->right);
    if (left_max > cur_max)
        cur_max = left_max;
    if (right_max > cur_max)
        cur_max = right_max;
    return (cur_max);
}

int tree_size(t_node *tree)
{
    int size_left = 0;
    int size_right = 0;

    if (!tree)
        return (0);
    int size = 1;
    if (tree->left)
        size_left = tree_size(tree->left);
    if (tree->right)
        size_right = tree_size(tree->right);
    size = size + size_left + size_right;
    return (size);
}

int tree_height(t_node *tree)
{
    if (!tree)
        return -1;//needs to be -1 without the root else 0
    int size = 1;
    int size_left = tree_height(tree->left);
    int size_right = tree_height(tree->right);
    if (size_left > size_right)
        return (size + size_left);
    else 
        return (size + size_right);
}

void swap_tree(t_node *tree)
{
    t_node *temp;

    temp = NULL;
    if (tree)
    {
        swap_tree(tree->left);//
        swap_tree(tree->right);//
        temp = tree->left;
        tree->left = tree->right;
        tree->right = temp;//no freeeing!!!!!
    }
}

int sum_tree(t_node *tree)
{
    if (!tree)
        return 0;
    int sum = tree->value; // Add the value of the current node
    sum += sum_tree(tree->left);
    sum += sum_tree(tree->right);
    return sum;
}

int find_num(t_node *tree, int value)
{
    if (tree)
    {
        if (tree->value > value)
            return find_num(tree->left, value);
        else if (tree->value < value)
            return find_num(tree->right, value);
        else
        {
            write(1, "found\n", 6);
            return 0;
        }
    }
    return 1;
}

int main()
{
    t_node *tree;
    int spaces = 0;

    tree = NULL;
    tree = create(tree, 500);
    tree = create(tree, 10);
    tree = create(tree, 3);
    tree = create(tree, 50);
    tree = create(tree, 6);
    tree = create(tree, 22);
    print_tree(tree, spaces);
    printf("smallest is %d\n", smallest(tree));
    printf("biggest is %d\n", biggest(tree));
    printf("tree size = %d\n", tree_size(tree));
    printf("tree height = %d\n", tree_height(tree));
    find_num(tree, 6);
    swap_tree(tree);
    print_tree(tree, spaces);
    printf("sum = %d\n", sum_tree(tree));
}