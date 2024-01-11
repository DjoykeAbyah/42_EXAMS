/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   myinter.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 21:06:49 by djoyke        #+#    #+#                 */
/*   Updated: 2023/04/26 14:15:19 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int j;
    char temp[255];
    char *str1 = argv[1];
    char *str2 = argv[2];

    i = 0;
    if (argc == 3)
    {
        while (str1[i])
        {    
            j = 0;
            while (str2[j])
            {
                if (temp[(int)str1[i]] != 1 && str1[i] == str2[j])
                {
                    write(1, &str1[i], 1);
                    temp[(int)str1[i]] = 1;
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}
