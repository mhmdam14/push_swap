/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:04:04 by mal-moha          #+#    #+#             */
/*   Updated: 2025/07/21 10:04:04 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str, bool *flag)
{
	int		i;
	long	number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			*flag = false;
			return (0);
		}
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number * sign);
}

int	stack_size(t_stack s)
{
	int	size;

	size = 0;
	while (s)
	{
		size++;
		s = s->next;
	}
	return (size);
}

int	is_sorted(t_stack s)
{
	if (!s)
		return (1);
	while (s->next)
	{
		if (s->content > s->next->content)
			return (0);
		s = s->next;
	}
	return (1);
}

int	has_duplicates(t_stack s)
{
	t_stack	temp;

	while (s)
	{
		temp = s->next;
		while (temp)
		{
			if (s->content == temp->content)
				return (1);
			temp = temp->next;
		}
		s = s->next;
	}
	return (0);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
