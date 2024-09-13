#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_node {
	int value;
	struct s_node *left;
	struct s_node *right;
} t_node;

t_node *init_node(int num) {
	t_node *node = malloc(sizeof(t_node));
	node->value = num;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_node *create_tree(t_node *tree, int num) {
	if (!tree)
		return (init_node(num));
	if (tree->value > num)
		tree->left = create_tree(tree->left, num);
	else
		tree->right = create_tree(tree->right, num);
	return (tree);
}

void print_tree(t_node *tree, int spaces) {
	if (!tree) {
		write(1, "\n", 1);
		return ;
	}
	spaces += 5;
	print_tree(tree->right, spaces);
	printf("\n");
	for (int i = 0; i < spaces; i++)
		printf(" ");
	printf("%d\n", tree->value);
	print_tree(tree->left, spaces);
}

int biggest_num(t_node *tree) {
	if (!tree) {
		return (INT_MIN);
	}
	int cur = tree->value;

	int left = biggest_num(tree->left);
	int right = biggest_num(tree->right);

	if (left > cur)
		cur = left;
	if (right > cur)
		cur = right;
	return (cur);
}

int main() {
	t_node *tree = NULL;

	tree = create_tree(tree, 5);
	tree = create_tree(tree, 10);
	tree = create_tree(tree, 15);
	tree = create_tree(tree, 4);
	tree = create_tree(tree, 20);

	print_tree(tree, 0);
	printf("biggest num = %d\n", biggest(tree));
}