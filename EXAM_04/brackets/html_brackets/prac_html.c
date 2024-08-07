#include <unistd.h>
#include <stdio.h>
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
	new = malloc(sizeof(t_list));
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list *ft_lstlast(t_list *lst)
{
	if (!lst)
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

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int match_check(t_list **lst, char *word)
{
	t_list *prev = NULL;
	t_list *cur = *lst;
	t_list *temp = NULL;

	if (!*lst)
		return (1);
	while (cur != NULL)
	{
		if (strncmp((char *)cur->content, word, ft_strlen(word)) == 0)
		{
			if (prev != NULL)
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
	int i = 0;
	int open_num = 0;
	t_list *new = NULL;

	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '<' && str[i + 1] != '/')
		{
			int j = i + 1;
			while (str[j] != '\0' && str[j] != '>')
				j++;
			if (str[j] == '>')
			{
				char *word = malloc(sizeof(char) * (j - i));
				strncpy(word, &str[i + 1], j - i);
				word[j - i - 1] = '\0';
				printf("word1 = %s\n", word);
				if (strncmp(word, "img", ft_strlen(word)) != 0)
				{
					new = ft_lstnew(word);
					ft_lstadd_back(lst, new);
				}
				open_num ++;
				i = j;
			}
		}
		if (str[i] == '<' && str[i + 1] == '/')
		{
			if (open_num == 0)
				return (1);
			int j = i + 1;
			while (str[j] != '\0' && str[j] != '>')
				j++;
			if (str[j] == '>')
			{
				char *word = malloc(sizeof(char) * (j - i));
				strncpy(word, &str[i + 2], j - i - 2);
				word[j - i - 2] = '\0';
				printf("word2 = %s\n", word);
				if (strncmp(word, "img", ft_strlen(word)) != 0)
				{
					if (match_check(lst, word) == 1)
						return (1);
				}
				free(word);
                open_num--;
			}
			i = j;
		}
		i++;
	}
	if (*lst)
		return (1);
	if (open_num != 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv) 
{
	t_list *list =  NULL;
	int i = 1;

	if (argc == 1)
    {
        write(1, "\n", 1);
		return (0);
    }
	while (i < argc)
	{
		if (argv[i][0] == '\0')
            printf("YES\n");
		else if (validate(&list, argv[i]) == 1)
            printf("NO\n");
        else
            printf("YES\n");
		i++;
	}
    return (0);
}
