#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_list {
	char *value;
	struct s_list *next;
} t_list;

t_list *init_node(char *value) {
	t_list *new_node = malloc(sizeof(t_list));
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

t_list *lst_last(t_list *lst) {
	while (lst && lst->next) {
		lst = lst->next;
	}
	return (lst);
}

void lst_add_back(t_list **lst, t_list *new) {
	t_list *back;
	if (*lst) {
		back = lst_last(*lst);
		back->next = new;
	}
	else
		*lst = new;
}

int check_words(t_list **stack, char *word) {
	t_list *previous = NULL;
	t_list *current = *stack;

	while (current && current->next) {
		previous = current;
		current = current->next;
	}
	if (current && strcmp(current->value, word) == 0) {
		if (previous == NULL)
			*stack = NULL;
		else
			previous->next = NULL;
		free(current->value);
		free(current);
		return (0);
	}
	else
		return (1);
}

char *tag_extractor(char *str, int len) {
	char *tag = malloc(sizeof(char) * len + 1);
	int i = 0;
	
	while (i < len && str[i] != ' ' && str[i] != '/') {
		tag[i] = str[i];
		i++;
	}
	tag[i] = '\0';
	return (tag);
}

int tag_validator(char *str) {
	int i = 0;
	t_list *stack = NULL;

	while (str[i]) {
		if (str[i] == '<' && str[i + 1] != '/') {
			int j = i + 1;
			while (str[i] != '>')
				i++;
			if (str[i] == '>') {
				int len = i - j;
				char *word = tag_extractor(&str[j], len);
				if (strcmp(word, "img") == 0)
					i = j;
				else {
					t_list *new_node = init_node(word);
					lst_add_back(&stack, new_node);
				}
			}
			i = j;
		}
		if (str[i] == '<' && str[i + 1] == '/') {
			int j = i + 2;
			while (str[i] != '>')
				i++;
			if (str[i] == '>') {
				int len = i - j;
				char *word = tag_extractor(&str[j], len);
				if (check_words(&stack, word) == 1) {
					free(word);
					t_list *temp;
					while (stack) {
						temp = stack;
						stack = stack->next;
						free(temp->value);
						free(temp);
						return (1);
					}
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
	else
		return (0);
}

int main(int argc, char **argv) {
	int i = 1;

	if (argc == 1) {
		return(write(1, "\n", 1));
	}
	while (argv[i]) {
		if (tag_validator(argv[i]) == 0) {
			write(1, "OK\n", 3);
		}
		else
			write(1, "Error\n", 6);
		i++;
	}
	return (0);
}