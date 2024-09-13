#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct s_node {
	int value;
	struct s_node *left;
	struct s_node *right;
} t_node;

t_node *init_node(int num) {
	t_node *new_node = malloc(sizeof(t_node));
	new_node->value = num;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
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
		printf("\n");
		return ;
	}
	spaces += 5;
	print_tree(tree->right, spaces);
	for (int i = 0; i < spaces; i++)
		printf(" ");
	printf("%d\n", tree->value);
	printf("\n");
	print_tree(tree->left, spaces);
}

int smallest(t_node *tree) {
	if (!tree)
		return (INT_MAX);
	
	int cur = tree->value;
	int left = smallest(tree->left);
	int right = smallest(tree->right);

	if (left < cur)
		cur = left;
	if (right < cur)
		cur = right;
	return (cur);
}

int main() {
	t_node *tree = NULL;

	tree = create_tree(tree, 5);
	tree = create_tree(tree, 10);
	tree = create_tree(tree, 1);
	tree = create_tree(tree, 25);
	tree = create_tree(tree, 50);

	print_tree(tree, 0);
	printf("%d\n", smallest(tree));

	return (0);
}