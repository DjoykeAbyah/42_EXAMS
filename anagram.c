/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   myanagram.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 20:03:50 by djoyke        #+#    #+#                 */
/*   Updated: 2023/04/25 17:41:15 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return(0);
    while(str[i])
        i++;
    return(i);
}

int main(int argc, char **argv)
{
    char temp[127];
    int i;
    char *str1 = argv[1];
    char *str2 = argv[2];

    i = 0;
    if (ft_strlen(str1) != ft_strlen(str2))
    {
        write(1, "error", 5);
        return(0);
    }
    if (argc == 3)
        {
        while (i < 127)
        {
            temp[i] = 0;
            i++;
        }
        i = 0;
        while (str1[i])
        {
            temp[(int)str1[i]]++;
            i++;
        }
        i = 0;
        while (str2[i])
        {
            temp[(int)str2[i]]--;
            i++;
        }
        i = 0;
        while (i < 127)
        {
            if (temp[i])
            {
                write(1, "no", 2);
                return(1);
            }
            i++;
        }
        write(1, "yes", 3);
        return(0);
    }
    return(0);
}
