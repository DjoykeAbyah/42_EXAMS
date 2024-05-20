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
    if (!lst)
        return (NULL);
    while (lst->next != NULL)
        lst = lst->next;
    return (lst);
}

void *ft_lstaddback(t_list **lst, t_list *new)
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

int same_check(t_list **lst, char *str)
{
    t_list *prev;
    t_list *cur;
    t_list *temp;

    prev = NULL;
    cur = *lst;
    temp = NULL;
    if (!lst)
        return (1);
    while (cur != NULL)//not cur->next!
    {
        if (strcmp((char *)cur->content, str) == 0)//cast it!
        {
            if (prev != NULL)
                prev->next = cur->next;//not prev it's prev->next
            else
                *lst = cur->next;
            free(cur->content);
            temp = cur;
            cur = cur->next;
            free(temp);
            return (0);///don't forget
        }
        else
            prev = cur;
            cur = cur->next;
    }
    return (1);
}

int validate(t_list *lst, char *str)
{
    int i;
    t_list *new_node;

    i = 0;
    if (!str)
        return (0);
    if (str[0] != '<')
        return (1);
    while (str[i] != '\0')
    {
        if (str[i] = '<' && str[i + 1] != '/')
        {
            int j = i;
            while (str[j] != '>' && str[j] != '\0')
                j++;
            if (str[j] == '>')
            {
                char *word = malloc(sizeof (char) * (j - i + 1));
                strncy(word, str[i + 1], (j - i + 1));
                word[j] = '\0';
                if (strcmp(word, "img") != 0)
                {
                    new_node = ft_lstnew(word);
                    ft_lstaddback(lst, new_node);
                }
                i = j;
            }
        }
        if (str[i] = '<' && str[i + 1] == '/')
        {
            int j = i;
            while (str[j] != '>' && str[j] != '\0')
                j++;
            if (str[j] == '>')
            {
                char *word = malloc(sizeof (char) * (j - i + 1));
                strncy(word, str[i + 1], (j - i + 1));
                word[j] = '\0';
                if (strcmp(word, "img") != 0)
                {
                    if (same_check(lst, word) != 0)
                        return (1);
                }
                free (word);
            }
            i = j;
        }
        i++;
    }
    return (0);
}
int main(int argc, char **argv)
{
    int i;
    int j;
    t_list *lst;

    i = 1;
    j = 1;
    lst = NULL;
    if (argc == 1)
    {
        write(1, "\n", 1);
            return (0);
    }
    while (j < argc && argv[i] != NULL)
    {
        if (argv[i][0] == '\0')
            write(1, "OK\n", 3);
        else if (validate(lst, argv[i]) == 0)// remember else if
            write(1, "OK\n", 3);
        else
            write(1, "KO\n", 3);\
        j++;
    }
    return (0);
}