/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:30:02 by mal-moha          #+#    #+#             */
/*   Updated: 2025/07/21 10:30:02 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else if ((argc == 2 && !argv[1][0]) || !handler(argv))
		return (error_msg());
	else if (argc == 2)
		argv = ft_split(argv[1]);
	initialize_stack(&a, argv, argc == 2);
	if (!a)
		return (1);
	if (has_duplicates(a))
	{
		free_stack(a);
		return (error_msg());
	}
	if (!is_sorted(a))
		push_swap(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
