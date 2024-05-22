#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

int match_check(char a, char b)
{
	if ((a == '{' && b == '}') || (a == '(' && b == ')') || (a == '[' && b == ']'))
		return (0);
	else
		return (1);
}

int validate(char *str)
{
	int i;
	int top;
	int stack[4096];

	i = 0;
	top = 0;
	if (!str)
		return (0);
	if (str[0] == '}' || str[0] == ')' || str[0] == ']')
		return (1);
	if (ft_strlen(str) == 1 && str[0] != '{' && str[0] != '(' && str[0] != '[')
		return (0);
	if (ft_strlen(str) == 1)// dont forget
		return (1);// dont forget
	while (str[i])
	{
		if (str[i] == '{' || str[i] == '(' || str[i] == '[')
		{
			stack[top] = str[i];
			top++;
		}stack[top] = str[i];
		if (str[i] == '}' || str[i] == ')' || str[i] == ']')
		{
			if (match_check(stack[top - 1], str[i]) != 0)
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
	int i;
	int count;'' '{[(0 + 0)(1 + 1)](3*(-1)){()}}' | cat -e

	i = 1;
	count = argc;
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (count != 0 && argv[i] != NULL)
	{
		if (argv[i][0] == '\0')
			write(1, "OK\n", 3);
		else if (validate(argv[i]) != 0)
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
		count--;'' '{[(0 + 0)(1 + 1)](3*(-1)){()}}' | cat -e
		i++;
	}
	return (0);
}