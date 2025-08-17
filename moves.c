/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:27:58 by mal-moha          #+#    #+#             */
/*   Updated: 2025/07/31 10:30:06 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_move_helper(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
}

void	execute_move(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
	{
		while (cost_a < 0 && cost_b < 0)
		{
			rrr(a, b);
			cost_a++;
			cost_b++;
		}
	}
	else if (cost_a > 0 && cost_b > 0)
	{
		while (cost_a > 0 && cost_b > 0)
		{
			rr(a, b);
			cost_a--;
			cost_b--;
		}
	}
	execute_move_helper(a, b, cost_a, cost_b);
	pa(a, b);
}

int	calculate_total_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(cost_a);
	abs_b = ft_abs(cost_b);
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		else
			return (abs_b);
	}
	else
		return (abs_a + abs_b);
}

void	execute_cheapest_move(t_stack *a, t_stack *b)
{
	t_stack	temp;
	t_stack	cheapest;
	int		min_cost;
	int		current_cost;

	if (!*b)
		return ;
	temp = *b;
	cheapest = temp;
	min_cost = calculate_total_cost(temp->cost_a, temp->cost_b);
	temp = temp->next;
	while (temp)
	{
		current_cost = calculate_total_cost(temp->cost_a, temp->cost_b);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest = temp;
		}
		temp = temp->next;
	}
	execute_move(a, b, cheapest->cost_a, cheapest->cost_b);
}
