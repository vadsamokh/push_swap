/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:08:50 by vbeech            #+#    #+#             */
/*   Updated: 2021/06/01 13:08:52 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_order(t_stack *stack)
{
	t_stack	*tmp;
	int		i;
	int		count;
	int		order;

	tmp = stack;
	i = 0;
	count = 0;
	order = tmp->order;
	while (tmp != NULL)
	{
		if (tmp->order < order)
		{
			order = tmp->order;
			count = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (count);
}

int	next_order(int order, t_stack *stack, int argc)
{
	t_stack	*tmp;
	int		count;
	int		i;

	tmp = stack;
	count = 0;
	i = 1;
	while ((tmp->order) != (order + i))
	{
		count++;
		tmp = tmp->next;
		if (tmp == NULL)
		{
			tmp = stack;
			count = 0;
			i++;
		}
		if ((order + i) == argc)
			return (min_order(stack));
	}
	return (count);
}

void	count_shifts(t_all *stacks, int argc)
{
	t_stack	*tmp;
	int		num;
	int		min_shifts;

	tmp = stacks->b;
	num = 0;
	min_shifts = argc;
	while (tmp != NULL)
	{
		min_shifts = up_up(stacks, next_order(tmp->order, stacks->a, argc),
				num, min_shifts);
		min_shifts = down_down(stacks, next_order(tmp->order, stacks->a, argc),
				num, min_shifts);
		min_shifts = up_down(stacks, next_order(tmp->order, stacks->a, argc),
				num, min_shifts);
		min_shifts = down_up(stacks, next_order(tmp->order, stacks->a, argc),
				num, min_shifts);
		tmp = tmp->next;
		num++;
	}
}

void	to_stack_a(t_all *stacks, int argc)
{
	while (stacks->b != NULL)
	{
		count_shifts(stacks, argc);
		while (stacks->ct_a < 0 && stacks->ct_b < 0)
		{
			rr(stacks);
			(stacks->ct_a)++;
			(stacks->ct_b)++;
		}
		while (stacks->ct_a > 0 && stacks->ct_b > 0)
		{
			rrr(stacks);
			(stacks->ct_a)--;
			(stacks->ct_b)--;
		}
		to_stack_a_2(stacks);
		pa(stacks);
	}
}

void	to_stack_a_2(t_all *stacks)
{
	while (stacks->ct_a < 0)
	{
		ra(stacks);
		(stacks->ct_a)++;
	}
	while (stacks->ct_b < 0)
	{
		rb(stacks);
		(stacks->ct_b)++;
	}
	while (stacks->ct_a > 0)
	{
		rra(stacks);
		(stacks->ct_a)--;
	}
	while (stacks->ct_b > 0)
	{
		rrb(stacks);
		(stacks->ct_b)--;
	}
}
