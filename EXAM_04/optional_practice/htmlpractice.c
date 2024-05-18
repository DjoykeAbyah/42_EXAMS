#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content)
{
    t_list *new_node;

    new_node = malloc(sizeof (t_list));
    if (new_node == NULL)
        return (NULL);
    new_node->content = content;
    new_node->next = NULL;
    return (new_node);
}

t_list *ft_lstlast(t_list *lst)
{
    if (lst == NULL)
        return (NULL);
    while (lst->next != NULL)
        lst = lst->next;
    return (lst);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *back;

    if (*lst)
    {
        back = ft_lstlast(*lst);
        back->next = new;
    }
    else
        *lst = new;
}


int check_same(t_list **lst, char *word)
{
    t_list *prev_node;
    t_list *curr_node;
    t_list *temp;

    prev_node = NULL;
    curr_node = *lst;
    if (*lst == NULL)
        return (false);
    while (curr_node != NULL)
    {
        if (strcmp((char *)curr_node->content, word) == 0)
        {
            if (prev_node != NULL)
                prev_node->next = curr_node->next;
            else
                *lst = curr_node->next;
            free(curr_node->content);
            temp = curr_node;
            curr_node = curr_node->next;
            free(temp);
            return (0);
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    return (1);
}

bool validate(t_list **lst, char *str)
{
    int i;
    t_list *new_node;

    i = 0;
    if (!str)
        return (true);
    if (str[0] != '<')
        return (false);
    while (str[i] != '\0')
    {
        if (str[i] == '<' && str[i + 1] != '/')
        {
            int j = i + 1;
            while (str[j] != '\0' && str[j] != '>')
                j++;
            if (str[j] == '>')
            {
                char *word = malloc((j - i + 1) * sizeof(char));
                strncpy(word, &str[i + 1], j - i - 1);
                word[j] = '\0';
                if (strcmp(word, "img") != 0)
                {
                    new_node = ft_lstnew(word);
                    ft_lstadd_back(lst, new_node);
                }
                i = j;
            }
        }
        if (str[i] == '<' && str[i + 1] == '/')
        {
            int j = i + 1;
            while (str[j] != '\0' && str[j] != '>')
                j++;
            if (str[j] == '>')
            {
                char *word = malloc((j - i + 1) * sizeof(char));
                strncpy(word, &str[i + 2], (j - i - 2));
                word[j - i + 1] = '\0';
                 if (strcmp(word, "img") != 0)
                {
                    if (check_same(lst, word) == 1)
                        return (false);
                }
                free(word);
            }
            i = j;
        }
        i++;
    }
    return (true);
}

int main(int argc, char **argv)
{
    t_list *lst;
    int i;
    int j;

    lst = NULL;
    i = 1;
    j = 1;
    if (argc == 1)
    {
        write(1, "\n", 1);
        return (0);
    }
    while (j < argc)
    {
        if (argv[i][0] == '\0')
            write(1, "OK\n", 3);
        else if (validate(&lst, argv[i]) == false)
            write(1, "KO\n", 3);
        else
            write(1, "OK\n", 3);
        i++;
        j++;
    }
    return (0);
}