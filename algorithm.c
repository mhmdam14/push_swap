/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:11:46 by mal-moha          #+#    #+#             */
/*   Updated: 2025/07/21 12:48:25 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position_by_index(t_stack stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

void	assign_target_position(t_stack *a, t_stack *b)
{
	t_stack	temp_b;
	t_stack	temp_a;
	int		target_index;
	int		min_index;

	temp_b = *b;
	assign_both(a, b);
	while (temp_b)
	{
		target_index = INT_MAX;
		min_index = INT_MAX;
		temp_a = *a;
		while (temp_a)
		{
			if (temp_a->index > temp_b->index && temp_a->index < target_index)
				target_index = temp_a->index;
			if (temp_a->index < min_index)
				min_index = temp_a->index;
			temp_a = temp_a->next;
		}
		if (target_index == INT_MAX)
			target_index = min_index;
		temp_b->target_pos = get_position_by_index(*a, target_index);
		temp_b = temp_b->next;
	}
}

void	calculate_cost(t_stack *a, t_stack *b)
{
	t_stack	temp_b;
	int		size_a;
	int		size_b;

	temp_b = *b;
	size_a = stack_size(*a);
	size_b = stack_size(*b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->pos;
		if (temp_b->pos > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->pos) * -1;
		temp_b->cost_a = temp_b->target_pos;
		if (temp_b->target_pos > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->target_pos) * -1;
		temp_b = temp_b->next;
	}
}

void	turk_sort_helper(t_stack *a, int lowest_pos, int reverse_rotations)
{
	if (!reverse_rotations)
	{
		while (lowest_pos > 0)
		{
			ra(a);
			lowest_pos--;
		}
	}
	else
	{
		while (reverse_rotations > 0)
		{
			rra(a);
			reverse_rotations--;
		}
	}
}

void	turk_sort(t_stack *a, t_stack *b)
{
	int	lowest_pos;
	int	stack_len;
	int	reverse_rotations;

	while (stack_size(*a) > 3)
		pb(a, b);
	sort_three(a);
	while (*b)
	{
		assign_target_position(a, b);
		calculate_cost(a, b);
		execute_cheapest_move(a, b);
	}
	assign_position(a);
	lowest_pos = get_lowest_index_pos(*a);
	stack_len = stack_size(*a);
	if (lowest_pos <= stack_len / 2)
		turk_sort_helper(a, lowest_pos, 0);
	else
	{
		reverse_rotations = stack_len - lowest_pos;
		turk_sort_helper(a, lowest_pos, reverse_rotations);
	}
}
