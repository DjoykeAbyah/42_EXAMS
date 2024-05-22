#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	void *content;
	struct s_list *next;
}	t_list;

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
	if (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void ft_lstaddback(t_list **lst, t_list *new)
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

int match_check(t_list **lst, char *word)
{
	t_list *prev;
	t_list *cur;
	t_list *temp;

	prev = NULL;
	cur = *lst;
	temp = NULL;
	if (!*lst)
		return (1);
	while (cur != NULL)
	{
		if (strcmp((char *)cur->content, word) == 0)
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
	int i;
	t_list *new;

	i = 0;
	new = NULL;
	if (!str)
		return (0);
	if (str[0] != '<')
		return (1);
	while (str[i])///
	{
		if (str[i] == '<' && str[i + 1] != '/')
		{
			int j = i + 1;
			while (str[j] != '\0' && str[j] != '>')
				j++;
			if (str[j] == '>')
			{
				char *word = malloc(sizeof(char) * (j - i));
				strncpy(word, &str[i + 1], j - i - 1);
				word[j - i - 1] = '\0';
				if (strcmp(word, "img") == 0)
				{
					new = ft_lstnew(word);
					ft_lstaddback(lst, new);
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
				char *word = malloc(sizeof(char) * (j - i));
				strncpy(word, &str[i + 2], j - i - 2);
				word[j - i - 1] = '\0';
				if (strcmp(word, "img") == 0)
				{
					if (match_check(lst, word) != 0)
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
	lst = NULL;
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (j < argc)
	{
		if (argv[i][0] == '\0')
			write(1, "OK\n", 3);
		else if (validate(&lst, argv[i]) != 0)
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
		i++;
		j++;
	}
	return (0);
}
























// t_list *init_list(void *content)
// {
// 	t_list *new;

// 	new = malloc(sizeof(t_list));
// 	if (new == NULL)
// 		return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
// }

// t_list *ft_lst_last(t_list *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst->next != NULL)
// 		lst = lst->next;
// 	return (lst);
// }

// void ft_lst_addback(t_list **lst, t_list *new)
// {
// 	t_list *back;

// 	back = NULL;
// 	if (*lst)/////////!!!!!!!!!!!!!!!!
// 	{
// 		back = ft_lst_last(*lst);
// 		back->next = new;
// 	}
// 	else
// 		*lst = new;
// }
// int match_check(t_list **lst, char *str)
// {
// 	t_list *cur;
// 	t_list *prev;
// 	t_list *temp;

// 	cur = *lst;
// 	prev = NULL;
// 	if (cur == NULL)//
// 		return (1);
// 	while (cur != NULL)
// 	{
// 		if (strcmp((char *)cur->content, str) == 0)
// 		{
// 			if (prev != NULL)//
// 				prev->next = cur->next;
// 			else
// 				*lst = cur->next;
// 			free(cur->content);
// 			temp = cur;
// 			cur = cur->next;
// 			free(temp);
// 			return (0);
// 		}
// 		prev = cur;//
// 		cur = cur->next;
// 	}
// 	return (1);
// }

// int validate(t_list **lst, char *str)
// {
// 	int i;
// 	t_list *new;

// 	i = 0;
// 	// new = NULL;
// 	if (!str)
// 		return (0);
// 	if (str[0] != '<')//!!!
// 		return (1);
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == '<' && str[i + 1] != '/')
// 		{
// 			int j = i + 1;//!!!
// 			while (str[j] != '\0' && str[j] != '>')
// 				j++;
// 			if (str[j] == '>')
// 			{
// 				char *word = malloc(sizeof(char) * (j - i));//
// 				strncpy(word, &str[i + 1], j - i);//
// 				word[j - i - 1] = '\0';//
// 				if (strcmp(word , "img") != 0)
// 				{
// 					new = init_list(word);
// 					ft_lst_addback(lst, new);
// 				}
// 				i = j;
// 			}
// 		}
// 		if (str[i] == '<' && str[i + 1] == '/')
// 		{
// 			int j = i + 1;//!!!
// 			while (str[j] != '\0' && str[j] != '>')
// 				j++;
// 			if (str[j] == '>')
// 			{
// 				char *word = malloc(sizeof(char) * (j - i));//
// 				strncpy(word, &str[i + 2], j - i - 2);//
// 				word[j - i - 2] = '\0';//
// 				if (strcmp(word , "img") != 0)
// 				{
// 					if (match_check(lst, word) == 1)
// 						return (1);
// 				}
// 				free(word);
// 			}
// 			i = j;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int main(int argc, char **argv)
// {
// 	t_list *lst;
// 	int i;
// 	int j;
	
// 	lst = NULL;
// 	i = 1;
// 	j = 1;
// 	if (argc == 1)
// 	{
// 		write(1, "\n", 1);
// 		return (0);
// 	}
// 	while (j < argc)
// 	{
// 		if (argv[i][0] == '\0')
// 			write(1, "OK\n", 3);
// 		else if (validate(&lst, argv[i]) == 1)
// 			write(1, "KO\n", 3);
// 		else
// 			write(1, "OK\n", 3);
// 		i++;
// 		j++;	
// 	}
// 	return (0);
// }