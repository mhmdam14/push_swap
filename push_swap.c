/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:25:10 by mal-moha          #+#    #+#             */
/*   Updated: 2025/07/21 10:25:10 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lowest_index_pos(t_stack s)
{
	int	lowest_index;
	int	lowest_pos;
	int	current_pos;

	lowest_index = INT_MAX;
	lowest_pos = 0;
	current_pos = 0;
	while (s)
	{
		if (s->index < lowest_index)
		{
			lowest_index = s->index;
			lowest_pos = current_pos;
		}
		current_pos++;
		s = s->next;
	}
	return (lowest_pos);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (stack_size(*a) != 3)
		return ;
	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third && first > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_five_helper(t_stack *a, int lowest_pos, int stack_len, bool flag)
{
	if (flag)
	{
		while (lowest_pos > 0)
		{
			ra(a);
			lowest_pos--;
		}
	}
	else
	{
		while (lowest_pos < stack_len)
		{
			rra(a);
			lowest_pos++;
		}
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	size;
	int	lowest_pos;
	int	stack_len;

	size = stack_size(*a);
	while (size > 3)
	{
		lowest_pos = get_lowest_index_pos(*a);
		stack_len = stack_size(*a);
		if (lowest_pos <= stack_len / 2)
			sort_five_helper(a, lowest_pos, stack_len, true);
		else
			sort_five_helper(a, lowest_pos, stack_len, false);
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	size;

	if (!a || !(*a))
		return ;
	size = stack_size(*a);
	assign_index(a);
	if (size == 2)
		sa(a);
	else if (size <= 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		turk_sort(a, b);
}
