// Assignment name  : ft_split
// Expected files   : ft_split.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes a string, splits it into words, and returns them as
// a NULL-terminated array of strings.

// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.

// Your function must be declared as follows:

#include <stdlib.h>

char *string_copy(char *dest, char *src, int len)
{
    int i;

    i = 0;
    while (src[i] && len != 0)
    {
        dest[i] = src[i];
        i++;
        len--;
    }
    dest[i] == '\0';
    return (dest);
}

int word_count(char *str)
{
    int i;
    int wc;

    i = 0;
    wc = 0;
    while (str[i])
    {
        while (str[i] && str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
            i++;
        if (str[i])
            wc++;
        while (str[i] && str[i] != '\n' && str[i] != '\t' && str[i] != ' ')
            i++;
        return (wc);
    }
}

char    **ft_split(char *str)
{
    int i;
    int j;
    int k;
    int len;
    int wc;
    char **new_string;

    i = 0;
    j = 0;
    k = 0;
    len = 0;
    wc = word_count(str);
    new_string = (char **)malloc(sizeof (char *) * (wc + 1));
    if (new_string == NULL)
        return (NULL);
    while (str[i])
    {
        while (str[i] && str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
            i++;
        j = i;
        while (str[i] && str[i] != '\n' && str[i] != '\t' && str[i] != ' ')
            i++;
        len = i - j;
        if (i > j)
        {
            new_string[k] = (char *)malloc(sizeof (char) * len + 1);
            new_string[k] = string_copy(new_string[k], &str[j], len);
            k++;
        }
    }
    new_string[k] == NULL;
    return (new_string);
}