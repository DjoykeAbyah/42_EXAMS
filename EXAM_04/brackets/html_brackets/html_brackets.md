Assignment name  : html_anglebrackets
Expected files   : *.c *.h
Allowed functions: strncpy, write, malloc, free, strcmp
--------------------------------------------------------------------------------

Write a program that takes an undefined number of strings in arguments. For each
argument, the program prints on the standard output "OK" followed by a newline
if the expression is correctly closed, otherwise it prints "Error" followed by
a newline.

<html> is an open
</html> is closed
<img> is ignored

An open must always be closed by the corresponding close in the
correct order. A string which not contains any angle brackets is considered as a
correct string. the string between the angle brackets can be anything not just html

If there is no arguments, the program must print only a newline.

Examples :

$> ./html_anglebrackets '<html></html>' | cat -e
OK$
$> ./html_anglebrackets '<bla></html><bla></html>' | cat -e
Error$
$> ./html_anglebrackets '' '<html><bla></html><html></bla></html>' | cat -e
OK$
OK$
$> ./html_anglebrackets | cat -e
$
$> ./html_anglebrackets '<html><html></html><img></html><html><img></html>' | cat -e
OK$


#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char **alloc_array(int count)
{
	char **new_array;
	int i;
	
	i = 0;
	new_array = malloc((sizeof(char *)) * (count + 1));
	while (i <= count)
	{
		new_array[i] = NULL;
		i++;
	}
	return (new_array);
}

int ft_strncmp(char *str1, char *str2, int len)
{
	int	i;

	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0') && len > i)
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}

int find_size(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '>')
			j++;
		i++;
	}
	return (j);
}

int find_bracket(char *str)
{
	int i;

	i = 0;
	while (str[i] != '>')
		i++;
	return (i);
}

char **fill_array(char *str, char **new_array)
{
	int i;
	int j;
	int result;
	
	i = 0;
	j = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '<') 
		{
			result = find_bracket(&str[i]) + 1;
			new_array[j] = malloc(sizeof(char) * (result + 1));
			strncpy(new_array[j], &str[i], result);
			new_array[j][result] = '\0';
			i += result;
			j++;
		}
		else
			i++;
	}
	return (new_array);
}

int count_array(char **array)
{
	int i;

	i = 0;
	while (array != NULL)
	{
		if (*array == NULL)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

void print_array(char **array)
{
	while (array != NULL)
	{
		if (*array == NULL)
		{
			printf("array = NULL\n");
			break ;
		}	
		printf("array = [%s]\n", *array);
		array++;
	}
}

int main (int argc, char **argv)
{
	int i;
	int j;
	int k;
	int iterator;
	int size_open;
	int size_close;
	char **array;
	char **open;
	char **close;

	i = 1;
	j = 0;
	k = 0;
	iterator = 0;
	array = NULL;
	open = NULL;
	close = NULL;
	if (argc == 1)
	{
		write(1, "no input\n", 10);
		return (0);
	}
	array = alloc_array(find_size(argv[i]));
	array = fill_array(argv[i], array);
	open = alloc_array(argc);
	close = alloc_array(argc);
	while (array[iterator] != NULL)
	{
		if (strcmp(array[iterator], "<img>") != 0)
		{
			if (ft_strncmp(array[iterator], "</", 2) == 0)
			{
				close[j] = malloc((sizeof (char)) * (ft_strlen(array[iterator])));
				close[j] = strncpy(close[j], array[iterator], ft_strlen(array[iterator]));
				close[ft_strlen(array[iterator])] = "\0";
				j++;
			}
			else
			{
				open[k] = malloc((sizeof (char)) * (ft_strlen(array[iterator]) + 1));
				open[k] = strncpy(open[k], array[iterator], ft_strlen(array[iterator]));
				open[ft_strlen(array[iterator])] = "\0";
				k++;
			}
			iterator++;

		}
		iterator++;
			
	}
	size_close = count_array(close);
	size_open = count_array(open);
	if (size_close != size_open)
	{
		write(1, "KO\n", 3);
		return (0);
	}
	else
	{
		write(1, "OK\n", 3);
		return (0);
	}
}