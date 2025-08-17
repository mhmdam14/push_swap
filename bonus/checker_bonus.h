/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmdam14 <mhmdam14@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:26:48 by mal-moha          #+#    #+#             */
/*   Updated: 2025/08/17 18:47:09 by mhmdam14         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "../push_swap.h"

int		ft_strcmp(const char *s1, const char *s2, size_t n);
void	swap_ab(t_stack *a, t_stack *b);
void	rotate_ab(t_stack *a, t_stack *b);
void	reverse_rotate_ab(t_stack *a, t_stack *b);

#endif