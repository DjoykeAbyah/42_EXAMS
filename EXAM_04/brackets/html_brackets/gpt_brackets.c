#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Define a stack node structure
typedef struct s_stack {
    char *tag;
    struct s_stack *next;
} t_stack;

void ft_putstr(char *str) {
    while (*str) {
        write(1, str, 1);
        str++;
    }
}

void push(t_stack **stack, char *tag) {
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    new_node->tag = strdup(tag);
    new_node->next = *stack;
    *stack = new_node;
}

char *pop(t_stack **stack) {
    if (*stack == NULL)
        return NULL;
    t_stack *top = *stack;
    char *tag = top->tag;
    *stack = top->next;
    free(top);
    return tag;
}

char *get_tag(char *str, int *i) {
    int start = *i;
    while (str[*i] && str[*i] != '>')
        (*i)++;
    if (str[*i] == '>') {
        int length = *i - start + 1;
        char *tag = (char *)malloc(length + 1);
        strncpy(tag, &str[start], length);
        tag[length] = '\0';
        (*i)++;
        return tag;
    }
    return NULL;
}

int check_html(char *str) {
    t_stack *stack = NULL;
    int i = 0;
    while (str[i]) {
        if (str[i] == '<') {
            i++;
            int is_closing = (str[i] == '/');
            if (is_closing)
                i++;
            char *tag = get_tag(str, &i);
            if (tag) {
                if (strncmp(tag, "img", 3) == 0) {
                    // Ignore <img> tags
                    free(tag);
                    continue;
                }
                if (is_closing) {
                    char *top_tag = pop(&stack);
                    if (!top_tag || strcmp(top_tag + 1, tag) != 0) {
                        free(tag);
                        if (top_tag)
                            free(top_tag);
                        while (stack)
                            free(pop(&stack));
                        return 0;
                    }
                    free(top_tag);
                } else {
                    if (tag[strlen(tag) - 2] != '/')
                        push(&stack, tag);
                }
                free(tag);
            }
        } else {
            i++;
        }
    }
    int result = (stack == NULL);
    while (stack)
        free(pop(&stack));
    return result;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        write(1, "\n", 1);
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        if (check_html(argv[i]))
            ft_putstr("OK\n");
        else
            ft_putstr("Error\n");
    }

    return 0;
}
