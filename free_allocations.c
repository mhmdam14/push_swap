/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:10:42 by mal-moha          #+#    #+#             */
/*   Updated: 2025/07/21 11:10:42 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack s)
{
	t_stack	temp;

	while (s)
	{
		temp = s->next;
		free(s);
		s = temp;
	}
}

void	free_argv(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	error_msg(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	handler(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '+' || argv[i][j] == '-')
				&& (argv[i][j + 1] < '0' || argv[i][j + 1] > '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
