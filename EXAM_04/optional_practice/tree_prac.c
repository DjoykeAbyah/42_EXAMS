#include <unistd.h>

typedef struct s_node {
    int           value;
    struct s_node *right;
    struct s_node *left;
}	t_node;


t_node *init_tree(t_node *tree, int value)//
{
    if (!tree)//
    {
        tree = malloc(sizeof (t_node));
        tree->value = value;
        tree->left = (void *)0;
        tree->right = NULL;
    }
    return (tree);
}

t_node *create_tree(t_node *tree, int value)
{
    if (!tree)
        return (init_tree(tree, value));
    if (tree->value > value)
        create_tree(tree->left, value);
    else
        create_tree(tree->right, value);
    return (tree);//
}

void print_tree(t_node *tree, int spaces)
{
    if (!tree)
        return ;
    int spaces += 5;//
    print_tree(tree->left, spaces);
        printf("\n");//
    for (int i = 0; i < spaces; i++)//
        printf(" ");//
    printf("%d\n", tree->value);
    printf(tree->right, spaces);
}

int size_tree(t_node *tree)
{
    int size = 0;

    if (tree)
    {
        size += 1;
        if (tree->left)
            size += size_tree(tree->left);
        if (tree->right)
            size += size_tree(tree->right);
        return (size);
    }
}