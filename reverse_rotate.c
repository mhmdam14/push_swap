/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:15:39 by mal-moha          #+#    #+#             */
/*   Updated: 2025/07/21 10:15:39 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	reverse_rotate(t_stack *s)
{
	t_stack	temp;
	t_stack	last;

	if (!(*s) || !(*s)->next)
		return (0);
	temp = *s;
	while (temp->next->next != NULL)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *s;
	*s = last;
	return (1);
}

void	rra(t_stack *a)
{
	if (reverse_rotate(a))
		ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	if (reverse_rotate(b))
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	int	rev_rotated_a;
	int	rev_rotated_b;

	rev_rotated_a = reverse_rotate(a);
	rev_rotated_b = reverse_rotate(b);
	if (rev_rotated_a || rev_rotated_b)
		ft_printf("rrr\n");
}
