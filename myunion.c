/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   myunion.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 14:36:38 by djoyke        #+#    #+#                 */
/*   Updated: 2023/04/21 17:18:29 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	temp[255];
	int		i;
	int		j;
	char	*str1;
	char	*str2;

	i = 0;
	j = 0;
	str1 = argv[1];
	str2 = argv[2];
	if (argc == 3)
	{
		while (str1[i] && temp[(int)str1[i]] != 1)
		{
			temp[(int)str1[i]] = 1;
			write(1, &str1[i], 1);
			i++;
		}
		while (str2[j])
		{
			if (temp[(int)str2[j]] != 1)
			{
				temp[(int)str2[j]] = 1;
				write(1, &str2[j], 1);
			}
		}
		j++;
	}
	write(1, "\n", 1);
	else
		write(1, "\n", 1);
	return (0);
}