// Assignment name  : ft_atoi_base
// Expected files   : ft_atoi_base.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str (base N <= 16)
// to an integer (base 10) and returns it.

// The characters recognized in the input are: 0123456789abcdef
// Those are, of course, to be trimmed according to the requested base. For
// example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

// Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

// Minus signs ('-') are interpreted only if they are the first character of the
// string.

// Your function must be declared as follows:


// int	ft_atoi_base(const char *str, int str_base)
// {
//     int i;
//     int sign;
//     int number;
//     int digit;

//     i = 0;
//     sign = 1;
//     while (str[i])
//     if (str[0] == '-')
//     {
//         sign = sign * -1;
//         i++;
//     }
//     if (str[i] <= 32)
//         i++;
//     while (str[i] && input_check(str[i]) == 0)
//     {
//         if (str[i] && (str[i] >= 'a' && str[i] <= 'f'))
//             digit = str[i] - 'a' + 10;
//         else if (str[i] && (str[i] >= 'A' && str[i] <= 'F'))
//             digit = str[i] - 'A' + 10;
//         else if (str[i] && (str[i] >= '0' && str[i] <= '9'))
//             digit = str[i] - '0';
//         number = number * str_base + digit;//first convert the single char then turn into the number got to the next.
//         i++; // str_base want we willen ruimte maken voor andere cijfers als ze er zijn
//         //daarna digit toevoegen
//     }
//     return (number * sign);
// }

int input_check(char c) 
{   
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
        return (0);
    else 
        return (1);
}

int ft_atoi_base(const char *str, int base) 
{
    int i;
    int nbr;
    int sign;
    int digit;

    i = 0;
    nbr = 0;
    sign = 1;
    digit = 0;
    if (str[i] == '-' || str[i] == '+') 
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] != '\0' && input_check(str[i]) == 0)
    {
        if (str[i] >= 'a' && str[i] <= 'f')
            digit = str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'F')
            digit = str[i] - 'A' + 10;
        else if (str[i] >= '0' && str[i] <= '9')
            digit = str[i] - '0';
        nbr = nbr * base + digit;
        i++;
    }
    return (nbr * sign);
}