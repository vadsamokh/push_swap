/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:00:43 by vbeech            #+#    #+#             */
/*   Updated: 2021/05/19 14:00:45 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_all *stacks)
{
	t_stack	*tmp;

	if (stacks->a->next != NULL)
	{
		tmp = stacks->a;
		stacks->a = tmp->next;
		add_elem_back(&(stacks->a), tmp);
		tmp = stacks->a;
		while (tmp != NULL)
			tmp = tmp->next;
	}
	stacks->operations_ct++;
	if (stacks->flag == 1)
		ft_putstr("ra\n");
}

void	rb(t_all *stacks)
{
	t_stack	*tmp;

	if (stacks->b->next != NULL)
	{
		tmp = stacks->b;
		stacks->b = tmp->next;
		add_elem_back(&(stacks->b), tmp);
		tmp = stacks->b;
		while (tmp != NULL)
			tmp = tmp->next;
	}
	stacks->operations_ct++;
	if (stacks->flag == 1)
		ft_putstr("rb\n");
}

void	ra_no_record(t_all *stacks)
{
	t_stack	*tmp;

	if (stacks->a->next != NULL)
	{
		tmp = stacks->a;
		stacks->a = tmp->next;
		add_elem_back(&(stacks->a), tmp);
		tmp = stacks->a;
		while (tmp != NULL)
			tmp = tmp->next;
	}
}

void	rb_no_record(t_all *stacks)
{
	t_stack	*tmp;

	if (stacks->b->next != NULL)
	{
		tmp = stacks->b;
		stacks->b = tmp->next;
		add_elem_back(&(stacks->b), tmp);
		tmp = stacks->b;
		while (tmp != NULL)
			tmp = tmp->next;
	}
}

void	rr(t_all *stacks)
{
	ra_no_record(stacks);
	rb_no_record(stacks);
	stacks->operations_ct++;
	if (stacks->flag == 1)
		ft_putstr("rr\n");
}
