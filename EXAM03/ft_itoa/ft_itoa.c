// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:

int how_much(long a)
{
    int i;

    i = 0;
    if (a <= 0)
        i++;
    while (a != 0)
    {
        a = a / 10;
        i++;
    }
    return (i);
}

char	*ft_itoa(int nbr)
{
    long num;
    int len;
    char *str;

    num = nbr;
    len = how_much(num);
    str = (char *)malloc(sizeof (char) * (len + 1));
    str[len] = '\0';
    len --;
    if (num < 0)
    {
        str[0] = '-';
        num = num * -1;//turn to positive
    }
    else if (num == 0)
        str[0] = '0';
    while (num != 0)
    {
        str[len] = (num % 10) + 48;//make into char
        num = num / 10;
        len--; 
    }
    return (str);
}