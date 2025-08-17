/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:18:02 by mal-moha          #+#    #+#             */
/*   Updated: 2025/07/21 10:18:02 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	push(t_stack *s1, t_stack *s2)
{
	t_stack	temp;

	if (!(*s2))
		return (0);
	temp = *s2;
	*s2 = (*s2)->next;
	temp->next = *s1;
	*s1 = temp;
	return (1);
}

void	pa(t_stack *a, t_stack *b)
{
	if (push(a, b))
		ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (push(b, a))
		ft_printf("pb\n");
}
