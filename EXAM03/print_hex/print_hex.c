// Assignment name  : print_hex
// Expected files   : print_hex.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a positive (or zero) number expressed in base 10,
// and displays it in base 16 (lowercase letters) followed by a newline.

// If the number of parameters is not 1, the program displays a newline.

// Examples:

// $> ./print_hex "10" | cat -e
// a$
// $> ./print_hex "255" | cat -e
// ff$
// $> ./print_hex "5156454" | cat -e
// 4eae66$
// $> ./print_hex | cat -e
// $

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + str[i] - 48;
		i++;
	}
	return (num); 
}

void	print_char(char c)
{
	write (1, &c, 1);
}

/* 	1. check if the number is not above 16 
	do number / 16 to make sure it's 16 or below 16
	so we can work with it.
	2. check if the number is smaller
	print modulo % 16 + 48 (turn into char)
	3. else print the lowercase alphabet
	print modulo % 16 + 87 (turn into char)
*/
static int	print_hex(int num)
{
	unsigned int	n;

	n = num;
	if ((n / 16) != 0)
		print_hex(n / 16);
	if ((n % 16) < 10)
		print_char((n % 16) + 48);
	else
		print_char((n % 16) + 87);
	return (n);
}

int	main(int argc, char **argv)
{
	int	num;

	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		print_hex(num);
	}
	write(1, "\n", 1);
}