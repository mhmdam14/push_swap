/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:20:27 by mal-moha          #+#    #+#             */
/*   Updated: 2025/07/21 10:20:27 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	t_list;

typedef t_list	*t_stack;

int		is_empty(t_stack s);
int		push_op(t_stack *s, int e);
int		pop(t_stack *s);
char	**ft_split(char *str);
long	ft_atol(char *str, bool *flag1);
int		handler(char **argv);
int		error_msg(void);
int		swap(t_stack *s);
int		rotate(t_stack *s);
int		reverse_rotate(t_stack *s);
int		push(t_stack *s1, t_stack *s2);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	free_stack(t_stack s);
void	free_argv(char **argv);
int		stack_size(t_stack s);
int		is_sorted(t_stack s);
int		has_duplicates(t_stack s);
void	assign_index(t_stack *s);
int		get_lowest_index_pos(t_stack s);
void	initialize_stack(t_stack *s, char **argv, bool flag);
void	push_swap(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_small(t_stack *a, t_stack *b);
void	turk_sort(t_stack *a, t_stack *b);
int		ft_abs(int n);
void	execute_move_helper(t_stack *a, t_stack *b, int cost_a, int cost_b);
void	execute_move(t_stack *a, t_stack *b, int cost_a, int cost_b);
void	execute_cheapest_move(t_stack *a, t_stack *b);
void	assign_index(t_stack *s);
void	assign_position(t_stack *stack);
void	assign_both(t_stack *a, t_stack *b);

#endif