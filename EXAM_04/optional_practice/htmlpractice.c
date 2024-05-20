#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content)
{
    t_list *new;

    new = malloc(sizeof (t_list));
    if (new == NULL)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

t_list *ft_lstlast(t_list *lst)
{
    if (lst == NULL)//!!!
		return (NULL);//!!
    while (lst->next != NULL)
        lst = lst->next;
    return (lst);
}

void ft_lst_addback(t_list **lst, t_list *new)
{
    t_list *back;

    if (*lst)
    {
        back = lstlast(*lst);
        back->next = new;
    }
    else
        *lst = new;
}

int check(t_list **lst, char *str)
{
    t_list *prev;
    t_list *cur;
    t_list *temp;

    prev = NULL;
    cur = *lst;
    temp = NULL;
    if (!*lst)
        return (1);//
    while (cur->content != NULL)
    {
        if (strcmp((char *)cur->content, str) == 0)
        {
            if (prev == NULL)
                prev->next = cur->next;
            else
                *lst = cur->next;
            free(cur->content);
            temp = cur;
            cur = cur->next;
            free(temp);
            return (0);
        }
        prev = cur;
        cur = cur->next;
    }
    return (1);
}

int validate(t_list **lst, char *str)
{
    t_list *new_node;
    int i;

    i = 0;
    if (!str)
        return (0);
    if (str[0]  == '>')
        return (1);
    while (str[i])
    {
        if (str[i] == '<' && str[i + 1] != '/')
        {
            int j = i;
            while (str[j] != '>' && str[j] != '\0')
                j++;
            if (str[j] == '>')
            {
                char *word = malloc(sizeof (char) * (j - i + 1));
                strncpy(word, &str[i + 1], (j - i + 1));
                word[j] = '\0';
                if (strcmp(word, "img") != 0)
                {
                    new_node = ft_lstnew(word);
                    ft_lst_addback(lst, new_node);
                }
                i = j;
            }
        }
        if (str[i] == '<' && str[i + 1] == '/')
        {
            int j = i;
            while (str[j] != '>' && str[j] != '\0')
                j++;
            if (str[j] == '>')
            {
                char *word = malloc(sizeof (char) * (j - i + 1));
                strncpy(word, &str[i + 2], (j - i + 2));
                word[j] = '\0';
                if (strcmp(word, "img") != 0)
                {
                    if (check(lst, word) != 0)
                        return (1);

                }
                free(word);
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
    if (argc == 1)
    {
        write(1, "\n", 1);
        return (0);
    }
    while (j < argc)
    {
        if (argv[i][0] == '\0')
            write(1, "OK\n", 3);
        else if (validate(&lst, argv[i]) == 0)
            write(1, "OK\n", 3);
        else
            write(1, "Error\n", 6);
        i++;
        j--;
    }
    return (0);
}
