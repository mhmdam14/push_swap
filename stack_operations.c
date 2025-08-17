/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:08:39 by mal-moha          #+#    #+#             */
/*   Updated: 2025/07/21 10:08:39 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack s)
{
	if (!s)
		return (1);
	return (0);
}

int	push_op(t_stack *s, int e)
{
	t_stack	new_node;
	t_stack	temp;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->content = e;
	new_node->index = 0;
	new_node->pos = 0;
	new_node->target_pos = 0;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->next = NULL;
	if (!(*s))
		(*s) = new_node;
	else if (!(*s)->next)
		(*s)->next = new_node;
	else
	{
		temp = (*s);
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	return (1);
}

int	pop(t_stack *s)
{
	t_stack	temp;

	if (is_empty(*s))
		return (0);
	temp = *s;
	*s = (*s)->next;
	free(temp);
	return (1);
}
