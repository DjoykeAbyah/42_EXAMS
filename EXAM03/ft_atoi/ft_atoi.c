// Assignment name  : ft_atoi
// Expected files   : ft_atoi.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str to an integer (type int)
// and returns it.

// It works much like the standard atoi(const char *str) function, see the man.

// Your function must be declared as follows:

int	ft_atoi(const char *str)
{
    int i;
    long nbr;
    int sign;

    i = 0;
    nbr = 0;
    sign = 1;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
    if (str[0] == '+' || str[0] == '-')
    {
        if (str[0] == '-')
            sign = sign * -1;
        i++;
    }
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        nbr = nbr * 10 + str[i] - 48;
        i++;
    }
    return (nbr * sign);
}

// * 10 want we wilen ruimte maken voor de andere cijfers als die er zijn