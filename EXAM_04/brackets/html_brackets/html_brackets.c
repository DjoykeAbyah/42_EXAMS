/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   html_brackets.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/17 14:55:29 by dreijans      #+#    #+#                 */
/*   Updated: 2024/04/29 19:24:15 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

bool tagvalidator(char *str1) 
{
    char stack[100];
	char tag[100];
	char end[100];
    int top = -1;
    int i = 0;
	
    if (!str1)
	{
		write(1, "no string\n", 11);
		return (false);
	}
	if (str1[0] != '<')
	{
		return (true);
	}
    while (str1[i] != '\0') 
	{
        if (str1[i] == '<' && str1[i + 1] != '/') 
		{
            int j = i + 1;
            while (str1[j] != '\0' && str1[j] != '>') 
			{
                j++;
            }
            if (str1[j] == '>') 
			{
                strncpy(tag, &str1[i], j - i + 1);
                tag[j - i + 1] = '\0';
                if (tag[ft_strlen(tag) - 2] != '/') 
				{
					top++;
                    ft_strcpy(&stack[top], tag);
					printf("top = %d\n", top);
					printf("top = %s\n", &stack[top]);
                }
                i = j;
            }
        } 
		else if (str1[i] == '<' && str1[i + 1] == '/') 
		{
            int j = i + 2;
            while (str1[j] != '\0' && str1[j] != '>') 
			{
                j++;
            }
            if (str1[j] == '>') 
			{
                strncpy(end, str1 + i, j - i + 1);
                end[j - i + 1] = '\0';
				int k = 0;
				printf("k = %d\n", k);
				printf("end = %s\n", end);
				printf("compare top = %s\n", &stack[top]);
                if (top == -1 || strcmp(&stack[top + 1], &end[k + 2]) != 0) 
				{
					return (false);
                }
                top--;
                i = j;
            }
        }
        i++;
    }
    return top == -1;
}

// <html></html>
// <html><body><img/><div></div></body></html>
// <bla></html><bla></html>
// <html><bla></html><html></bla></html>
// <html><html></html><img></html><html><img></html>
int main(int argc, char **argv) 
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (tagvalidator(argv[i]) == false)
		{
			write(1, "KO\n", 3);
			return (1);
		}
		else if (tagvalidator(argv[i]) == true)
		{
			write(1, "OK\n", 3);
			return (0);
		}
		if (argc == 1)
		{
			write(1, "\n", 1);
			return (1);
		}
	}
    return 0;
}
