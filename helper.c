/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:28:39 by mal-moha          #+#    #+#             */
/*   Updated: 2025/07/31 10:29:10 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printhex(unsigned int nb, int uppercase)
{
	char	*hex;
	int		count;

	count = 0;
	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (nb >= 16)
		count += ft_printhex(nb / 16, uppercase);
	count += ft_putchar(hex[nb % 16]);
	return (count);
}

int	ft_printhex_long(unsigned long nb)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (nb >= 16)
		count += ft_printhex_long(nb / 16);
	count += ft_putchar(hex[nb % 16]);
	return (count);
}

int	ft_printaddress(void *address)
{
	int	count;

	count = 0;
	if (!address)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += ft_putstr("0x");
	count += ft_printhex_long((unsigned long)address);
	return (count);
}
