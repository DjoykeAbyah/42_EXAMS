/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   best_brackets.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/18 19:39:07 by djoyke        #+#    #+#                 */
/*   Updated: 2024/07/18 20:28:52 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int match_check(char a, char b)
{
	if ((a == '{' && b == '}') || (a == '(' && b == ')') || (a == '[' && b == ']'))
		return (0);
	return (1);
}

int close_check(char *str)
{
	int i = 0;
	int top = 0;
	int stack[4096];

	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '{' || str[i] == '(' || str[i] == '[')
		{
			stack[top] = str[i];
			top++;
		}
		else if (str[i] == '}' || str[i] == ')' || str[i] == ']')
		{
			if (top == 0 || match_check(stack[top - 1], str[i]))
				return (1);
			top--;
		}
		i++;
	}
	if (top != 0)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int i = 1;
	int count = argc;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (count != 0 && argv[i] != (void *)0)
	{
		if (argv[i][0] == '\0')
		{
			write(1, "OK\n", 3);
			return (0);
		}
		if (close_check(argv[i]) == 0)
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		count--;
		i++;
	}
	return (0);
}