/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   myprintf.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 19:15:09 by djoyke        #+#    #+#                 */
/*   Updated: 2023/04/26 14:15:14 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int i;

	i = 0;
	if(!str)
		return(0);
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int ft_putnbr(int nb)
{
	int len;
	long long n;

	len = 0;
	n = nb;
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else
		len += ft_putchar(n + '0');
	return (len);
}

int ft_puthex(unsigned int hex)
{
	int len;

	len = 0;
	if ((hex / 16) != 0)
		len += ft_puthex(hex / 16);
	if ((hex % 16) < 10)
		len += ft_putchar((hex % 16) + '0');
	else 
		len += ft_putchar((hex % 16) + 87);
	return (len); 
}

int ft_printf(char *format, ...)
{
	int i;
	int len;
	va_list arg;

	i = 0;
	len = 0;
	va_start(arg, format);
	while(format[i])
	{
		if(format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if(format[i] == 's')
				len += ft_putstr(va_arg(arg, char *));
			if(format[i] == 'x')
				len += ft_puthex(va_arg(arg, unsigned int));
			if(format[i] == 'd')
				len += ft_putnbr(va_arg(arg, int));
		}
		else
		{
			if (format[i] != '%')
				len += ft_putchar(format[i]);
		}
		i++;
	}
	return (len);
	va_end(arg);
}
