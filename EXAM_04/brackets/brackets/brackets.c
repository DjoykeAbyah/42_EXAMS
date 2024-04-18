/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brackets.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/17 12:45:29 by dreijans      #+#    #+#                 */
/*   Updated: 2024/04/18 17:46:32 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int match_check(char a, char b)
{
	if ((a == '[' && b == ']') || (a == '{' && b == '}') || (a == '(' && b == ')'))
		return (0);
	else 
		return (1);
}

int close_check(char *str)
{
	int i;
	int top;
	int stack[4096];

	i = 0;
	top = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			stack[top] = str[i];
			top++;
		}
		if (str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if (top == 0 || match_check(stack[top - 1], str[i]) != 0)
				return (1);
			top--;
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int i;
	int count;

	i = 1;
	count = argc;
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (count != 0 && argv[i] != (void *)0)
	{
		if (close_check(argv[i]) == 0)
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		count--;
		i++;
	}
	return (0);
}

