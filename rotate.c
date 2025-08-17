/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:12:25 by mal-moha          #+#    #+#             */
/*   Updated: 2025/07/21 10:12:25 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	rotate(t_stack *s)
{
	t_stack	temp;

	if (!(*s) || !(*s)->next)
		return (0);
	temp = *s;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = (*s);
	(*s) = (*s)->next;
	temp->next->next = NULL;
	return (1);
}

void	ra(t_stack *a)
{
	if (rotate(a))
		ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	if (rotate(b))
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate(a);
	rotated_b = rotate(b);
	if (rotated_a || rotated_b)
		ft_printf("rr\n");
}
