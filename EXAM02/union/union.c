char *stringcopy(char *dest, char *src, int len)
{
    int i;

    i = 0;
    while (src[i] && (i < len))
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int wordcount(char *str)
{
    int i;
    int wc;

    i = 0;
    wc = 0;
    while (str[i])
    {
        while (str[i] && (str[i] == '\n' || str[i] == '\t' || str[i] == ' '))
            i++;
        if (str[i])
            wc++;
        while (str[i] && (str[i] != '\n' && str[i] != '\t' && str[i] != ' '))
            i++;
    }
    return (wc);

}

char **ft_split(char *str)
{
    int i;
    int j;
    int k;
    int wc;
    int len;
    char **split_string;

    i = 0;
    j = 0;
    k = 0;
    wc = wordcount(str);
    split_string = NULL;
    split_string = (char **)malloc(sizeof (char *) * (wc + 1));
    if (split_string = NULL)
        return (NULL);
    while (str[i])
    {
        while (str[i] && (str[i] == '\n' || str[i] == '\t' || str[i] == ' '))
            i++;
        j = i;
        while (str[i] && (str[i] != '\n' && str[i] != '\t' && str[i] != ' '))
            i++;
        len = i - j;
        if (i > j)
        {
            split_string[k] = (char *)malloc(sizeof (char) * len + 1);
            split_string[k] = stringcopy(split_string[k], &str[j], len);
            k++;
        }
    }
    split_string[k] = NULL;
    return (split_string);
}