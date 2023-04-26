/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mypalindromec.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 12:28:21 by djoyke        #+#    #+#                 */
/*   Updated: 2023/04/26 14:15:29 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(const char *str)
{
    int i;
    
    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return(i);
}

void ft_pal(const char *str)
{
    int i;
    int len;
    int high;
    int low;
    int maxlen;
    int start;
    
    len = ft_strlen(str);
    if (len < 2)
    {
        write(1, str, 1);
        return ;
    }
    i = 1;
    maxlen = 1;
    while (str[i])
    {
        high = i + 1;
        low = i - 1;
        len = ft_strlen(str);
        while (low >= 0 && str[i] == str[low])
            low--;
        while (high < len && str[i] == str[high])
            high++;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            high++;
            low--;
        }
        len = high - low - 1;
        if (len >= maxlen)
        {
            maxlen = len;
            start = low + 1;
        }
        i++;
    }
    write (1, &str[start], maxlen);
}
