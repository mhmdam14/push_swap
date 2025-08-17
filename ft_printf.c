/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:27:26 by mal-moha          #+#    #+#             */
/*   Updated: 2025/07/31 10:28:28 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf_helper(const char **format, va_list args)
{
	int	count;

	count = 0;
	if (**format == 'd' || **format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (**format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (**format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (**format == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (**format == 'p')
		count += ft_printaddress(va_arg(args, void *));
	else if (**format == 'x')
		count += ft_printhex(va_arg(args, unsigned int), 0);
	else if (**format == 'X')
		count += ft_printhex(va_arg(args, unsigned int), 1);
	else if (**format == '%')
		count += ft_putchar('%');
	(*format)++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_printf_helper(&format, args);
		}
		else
		{
			count += ft_putchar(*format);
			format++;
		}
	}
	va_end(args);
	return (count);
}
