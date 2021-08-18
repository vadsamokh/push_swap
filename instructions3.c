/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:17:52 by vbeech            #+#    #+#             */
/*   Updated: 2021/05/19 14:17:54 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_all *stacks)
{
	t_stack	*tmp;

	if (stacks->a->next != NULL)
	{
		tmp = stacks->a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		add_elem_front(&(stacks->a), tmp);
		tmp = stacks->a;
		while (tmp != NULL)
			tmp = tmp->next;
	}
	stacks->operations_ct++;
	if (stacks->flag == 1)
		ft_putstr("rra\n");
}

void	rrb(t_all *stacks)
{
	t_stack	*tmp;

	if (stacks->b->next != NULL)
	{
		tmp = stacks->b;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		add_elem_front(&(stacks->b), tmp);
		tmp = stacks->b;
		while (tmp != NULL)
			tmp = tmp->next;
	}
	stacks->operations_ct++;
	if (stacks->flag == 1)
		ft_putstr("rrb\n");
}

void	rra_no_record(t_all *stacks)
{
	t_stack	*tmp;

	if (stacks->a->next != NULL)
	{
		tmp = stacks->a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		add_elem_front(&(stacks->a), tmp);
		tmp = stacks->a;
		while (tmp != NULL)
			tmp = tmp->next;
	}
}

void	rrb_no_record(t_all *stacks)
{
	t_stack	*tmp;

	if (stacks->b->next != NULL)
	{
		tmp = stacks->b;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		add_elem_front(&(stacks->b), tmp);
		tmp = stacks->b;
		while (tmp != NULL)
			tmp = tmp->next;
	}
}

void	rrr(t_all *stacks)
{
	rra_no_record(stacks);
	rrb_no_record(stacks);
	stacks->operations_ct++;
	if (stacks->flag == 1)
		ft_putstr("rrr\n");
}
