/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmdam14 <mhmdam14@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:26:39 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/17 18:47:15 by mhmdam14         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "get_next_line_bonus/get_next_line_bonus.h"
#include "checker_bonus.h"

int	check(char *line)
{
	int	flag;

	flag = 0;
	if (!ft_strcmp(line, "pa\n", 3) || !ft_strcmp(line, "pb\n", 3))
		flag = 1;
	else if (!ft_strcmp(line, "sa\n", 3) || !ft_strcmp(line, "sb\n", 3))
		flag = 1;
	else if (!ft_strcmp(line, "ra\n", 3) || !ft_strcmp(line, "rb\n", 3))
		flag = 1;
	else if (!ft_strcmp(line, "rra\n", 4) || !ft_strcmp(line, "rrb\n", 4))
		flag = 1;
	else if (!ft_strcmp(line, "ss\n", 3))
		flag = 1;
	else if (!ft_strcmp(line, "rr\n", 3))
		flag = 1;
	else if (!ft_strcmp(line, "rrr\n", 4))
		flag = 1;
	return (flag);
}

void	execute(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strcmp(line, "pa\n", 3))
		push(a, b);
	else if (!ft_strcmp(line, "pb\n", 3))
		push(b, a);
	else if (!ft_strcmp(line, "sa\n", 3))
		swap(a);
	else if (!ft_strcmp(line, "sb\n", 3))
		swap(b);
	else if (!ft_strcmp(line, "ra\n", 3))
		rotate(a);
	else if (!ft_strcmp(line, "rb\n", 3))
		rotate(b);
	else if (!ft_strcmp(line, "rra\n", 4))
		reverse_rotate(a);
	else if (!ft_strcmp(line, "rrb\n", 4))
		reverse_rotate(b);
	else if (!ft_strcmp(line, "ss\n", 3))
		swap_ab(a, b);
	else if (!ft_strcmp(line, "rr\n", 3))
		rotate_ab(a, b);
	else if (!ft_strcmp(line, "rrr\n", 4))
		reverse_rotate_ab(a, b);
}

void	read_instructions(t_stack *a, t_stack *b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		else if (!check(line))
		{
			free(line);
			write(2, "Error\n", 6);
			free_stack(*a);
			free_stack(*b);
			exit(1);
		}
		else
		{
			execute(a, b, line);
			free(line);
		}
	}
}

void	error_msg_bonus(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	a = NULL;
	b = NULL;
	if ((argc == 2 && !argv[1][0]) || !handler(argv))
		error_msg_bonus();
	else if (argc == 2)
		argv = ft_split(argv[1]);
	initialize_stack(&a, argv, argc == 2);
	if (!a)
		exit(0);
	if (has_duplicates(a))
	{
		free_stack(a);
		error_msg_bonus();
	}
	read_instructions(&a, &b);
	if (is_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(a);
	free_stack(b);
	return (0);
}
