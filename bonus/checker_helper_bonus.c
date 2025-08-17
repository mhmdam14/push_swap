/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmdam14 <mhmdam14@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:26:53 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/17 18:47:02 by mhmdam14         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s2[i] == s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	swap_ab(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	rotate_ab(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate_ab(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
