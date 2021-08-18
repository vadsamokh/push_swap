/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:23:50 by vbeech            #+#    #+#             */
/*   Updated: 2021/05/17 12:23:52 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				num;
	int				order;
	int				flag;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_all
{
	t_stack	*a;
	t_stack	*b;
	int		algo;
	int		operations_ct;
	int		flag;
	int		ct_a;
	int		ct_b;
}			t_all;

void	error_msg(void);
int		init_list(int argc, char **argv, t_all *stacks);
int		check_input(char *str);
int		check_duplicates(int argc, char **argv);
int		overflow_check(char *argv);
t_stack	*create_elem(int num);
void	add_elem_back(t_stack **stack, t_stack *new);
void	add_elem_front(t_stack **stack, t_stack *new);
void	sa(t_all *stacks);
void	sb(t_all *stacks);
void	ss(t_all *stacks);
void	pa(t_all *stacks);
void	pb(t_all *stacks);
void	ra(t_all *stacks);
void	rb(t_all *stacks);
void	ra_no_record(t_all *stacks);
void	rb_no_record(t_all *stacks);
void	rra_no_record(t_all *stacks);
void	rrb_no_record(t_all *stacks);
void	rr(t_all *stacks);
void	rra(t_all *stacks);
void	rrb(t_all *stacks);
void	rrr(t_all *stacks);
void	set_order(t_all *stacks);
int		count_flags(t_stack *a);
int		check_algo(t_all *stacks, t_stack *markup_head, int best_flg,
			int *best_ord);
int		find_best_markup(t_all *stacks);
void	set_flags(t_all *stacks, int best_ord);
void	greater_than(t_stack *a, t_stack *markup_head);
void	by_index(t_stack *a, t_stack *markup_head);
int		sorting(t_all *stacks, int argc);
int		find_false(t_stack *stack);
void	sa_reset_flags(t_all *stacks);
void	to_stack_b(t_all *stacks);
void	to_stack_a(t_all *stacks, int argc);
void	to_stack_a_2(t_all *stacks);
void	align_a(t_all *stacks);
int		stack_len(t_stack *stack);
int		next_order(int order, t_stack *stack, int argc);
int		min_order(t_stack *stack);
void	count_shifts(t_all *stacks, int argc);
int		up_up(t_all *stacks, int num_a, int num_b, int min_shifts);
int		down_down(t_all *stacks, int num_a, int num_b, int min_shifts);
int		up_down(t_all *stacks, int num_a, int num_b, int min_shifts);
int		down_up(t_all *stacks, int num_a, int num_b, int min_shifts);
void	print_flags(t_stack *stack);
void	print_stack(t_stack *stack);

#endif