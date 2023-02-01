/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   palindrome.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 13:21:47 by dreijans      #+#    #+#                 */
/*   Updated: 2023/02/01 16:24:29 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "palindrome.h"

//checks lenght of string for j to start at
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

//when palindrome seems to be found
//checks if all positions till centre are equal
int	ft_check(char *str, int i, int j)
{
	while (str[i] == str[j] && i != j && j != 0)
	{
		i++;
		if (j != i)
			j--;
	}
	if (str[i] != str[j])
		return (0);
	return (1);
}

//when all positions are equal prints palindrome
//at start of palindrome in string
void	ft_printstr(char *s, int i, int j)
{
	int	len;
	int	x;

	len = j - i;
	x = 0;
	while (x <= len)
	{
		write(1, &s[x], 1);
		x++;
	}
}

void	ft_palindrome(char *str)
{
	int	i;
	int	j;
	int	x;
	int a = 0;
	int b = 0;

	i = 0;
	j = ft_strlen(str) - 1;
	while (str[i] != '\0' && j != 0)
	{
		if (str[i] == str[j])
		{
			//check if its actual palindrome
			x = ft_check(str, i, j);
			//save untill bigger or last one found
			if (x == 1)
			{
				if (b == 0 && a == 0)
				{
					a = i;
					b = j;
				}
				else
				{
					if ((b - a) <= (j - i))
					{
					a = i;
					b = j;
					}
				}
			}
		}
		j--;
		//reset to start from new position i
		if (j == i)
		{
			j = ft_strlen(str) - 1;
			i++;
		}	
	}
	ft_printstr(&str[a], a, b);
}
