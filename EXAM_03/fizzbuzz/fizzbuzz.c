/*
Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$> 

*/

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnumber(int n)
{
    if (n < 10)
        ft_putchar(n + '0');
    else
    {
        ft_putnumber(n / 10);
        ft_putnumber(n % 10);
    }
}

int main(void)
{
    int i;

    i = 1;
    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 != 0)
            write (1, "fizz\n", 5);
        if (i % 5 == 0 && i % 3 != 0)
            write (1, "buzz\n", 5);
        if (i % 5 == 0 && i % 3 == 0)
            write (1, "fizzbuzz\n", 9);
        if (i % 5 != 0 && i % 3 != 0)
        {
            ft_putnumber(i);
            ft_putchar('\n');
        }
        i++;
    }
    return (i);
}