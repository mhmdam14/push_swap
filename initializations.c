/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:32:38 by mal-moha          #+#    #+#             */
/*   Updated: 2025/07/21 10:32:38 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stack(t_stack *s, char **argv, bool flag)
{
	int		i;
	long	number;
	bool	flag1;

	i = -1;
	if (!flag)
		i = 0;
	*s = NULL;
	flag1 = true;
	while (argv[++i])
	{
		number = ft_atol(argv[i], &flag1);
		if (number > INT_MAX || number < INT_MIN || flag1 == false)
		{
			write(2, "Error\n", 6);
			free_stack(*s);
			*s = NULL;
			if (flag)
				free_argv(argv);
			return ;
		}
		push_op(s, (int)number);
	}
	if (flag)
		free_argv(argv);
}

void	assign_index(t_stack *s)
{
	t_stack	current;
	t_stack	compare;
	int		index;

	current = *s;
	while (current)
	{
		index = 0;
		compare = *s;
		while (compare)
		{
			if (compare->content < current->content)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	assign_both(t_stack *a, t_stack *b)
{
	assign_position(a);
	assign_position(b);
}

void	assign_position(t_stack *s)
{
	t_stack	temp;
	int		i;

	temp = *s;
	i = 0;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}
