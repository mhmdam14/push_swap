/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:29:32 by mal-moha          #+#    #+#             */
/*   Updated: 2025/07/31 10:29:33 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printhex(unsigned int nb, int uppercase);
int	ft_printhex_long(unsigned long nb);
int	ft_printaddress(void *address);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putstr(char *str);
int	ft_printf_helper(const char **format, va_list args);
int	ft_printf(const char *format, ...);

#endif