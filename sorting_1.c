/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:08:41 by vbeech            #+#    #+#             */
/*   Updated: 2021/06/01 13:08:46 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_false(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->flag == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	sa_reset_flags(t_all *stacks)
{
	sa(stacks);
	set_flags(stacks, find_best_markup(stacks));
}

void	to_stack_b(t_all *stacks)
{
	int	count0;
	int	count1;

	while (find_false(stacks->a) == 1)
	{
		count0 = count_flags(stacks->a);
		sa_reset_flags(stacks);
		count1 = count_flags(stacks->a);
		if (count1 > count0)
		{
			if (stacks->flag == 1)
				ft_putstr("sa\n");
			stacks->operations_ct++;
		}
		else
		{
			sa_reset_flags(stacks);
			if (stacks->a->flag == 0)
				pb(stacks);
			else
				ra(stacks);
		}
	}
}

void	align_a(t_all *stacks)
{
	int		num;
	t_stack	*tmp;

	num = 0;
	tmp = stacks->a;
	while (tmp->order != 0)
	{
		num++;
		tmp = tmp->next;
	}
	if (num > (stack_len(stacks->a) / 2))
	{
		while (stacks->a->order != 0)
			rra(stacks);
	}
	else
	{
		while (stacks->a->order != 0)
			ra(stacks);
	}
}

int	sorting(t_all *stacks, int argc)
{
	set_flags(stacks, find_best_markup(stacks));
	to_stack_b(stacks);
	to_stack_a(stacks, argc);
	align_a(stacks);
	return (stacks->operations_ct);
}
