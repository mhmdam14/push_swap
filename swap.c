/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:04:32 by mal-moha          #+#    #+#             */
/*   Updated: 2025/07/21 10:04:32 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	swap(t_stack *s)
{
	t_stack	temp;

	if (!(*s) || !(*s)->next)
		return (0);
	temp = (*s)->next;
	(*s)->next = temp->next;
	temp->next = *s;
	*s = temp;
	return (1);
}

void	sa(t_stack *a)
{
	if (swap(a))
		ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	if (swap(b))
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int	swapped_a;
	int	swapped_b;

	swapped_a = swap(a);
	swapped_b = swap(b);
	if (swapped_a || swapped_b)
		ft_printf("ss\n");
}
