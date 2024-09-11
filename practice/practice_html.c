#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list {
	char *value;
	struct s_list *next;
} t_list;

t_list *init_node(char *value) {
	
	t_list *new_node;
	new_node = malloc(sizeof (t_list));
	// if (new_node == NULL)
	// 	return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

t_list *list_last(t_list *list) {
	while (list && list->next)
		list = list->next;
	return (list);
}

void ft_list_add_back(t_list **list, t_list *new) {
	t_list *back;
	if (*list) {
		back = list_last(*list);
		back->next = new;
	}
	else
		*list = new;
}

int compare_words(t_list **list, char *word) {
	t_list *previous;
	t_list *current = *list;

	while (current->next) {
		previous = current;
		current = current->next;
	}
	if (current && strcmp(current->value, word) == 0) {
		if (previous == NULL)
			*list = NULL; //only one node in list
		else
			previous->next = NULL; //erase last in list
		free(current->value);
		free(current);
		return (0);
	}
	else
		return (1);
}

int parse_words(char *str) {
	int i = 0;
	t_list *stack = NULL;
	
	while (str[i]) {
		if (str[i] == '<' && str[i + 1] != '/') {
			int j = i + 1;
			printf("int j = %i\n", j);
			while (str[i] != '>')
				i++;
			if (str[i] ==  '>') {
				int len = i - j;
				printf("int i = %i\n", i);
				char *word = malloc(sizeof(char) * (len + 1));
				strncpy(word, &str[j], len);
				word[len] = '\0';
				printf("word = %s\n", word);
				t_list *new_node = init_node(word);
				ft_list_add_back(&stack, new_node);
			}
			i = j;
		}
		if (str[i] == '<' && str[i + 1] == '/') {
			int j = i + 2;
			while (str[i] != '>')
				i++;
			if (str[i] ==  '>') {
				int len = i - j;
				char *word = malloc(sizeof(char) * (len + 1));
				strncpy(word, &str[j], len);
				word[len] = '\0';
				if (compare_words(&stack, word) == 1) {
					free(word);
					t_list *temp;
					while (stack) {
						temp = stack;
						stack = stack->next;
						free(temp->value);
						free(temp);
					}
					return (1);
				}
				free(word); 
			}
			i = j;
		}
		i++;
	}
	if (stack != NULL) {
		t_list *temp;
		while (stack) {
			temp = stack;
			stack = stack->next;
			free(temp->value);
			free(temp);
		}
		return (1);
	}
	return (0);
}

int main(int argc, char **argv) {
	int i = 1;

	if (argc == 1)
		return (write(1, "\n", 1));
	while (argv[i]) {
		if (parse_words(argv[i]) == 0)
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		i++;
	}
	return (0);
}