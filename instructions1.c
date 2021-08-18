/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:29:58 by vbeech            #+#    #+#             */
/*   Updated: 2021/05/19 12:30:00 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_all *stacks)
{
	t_stack	*tmp;

	if (stacks->a != NULL && stacks->a->next != NULL)
	{
		tmp = stacks->a->next;
		if (stacks->a->next->next != NULL)
		{
			stacks->a->next->next->prev = stacks->a;
			stacks->a->next = stacks->a->next->next;
			stacks->a->prev = tmp;
			stacks->a->prev->prev = NULL;
			stacks->a->prev->next = stacks->a;
			stacks->a = stacks->a->prev;
		}
		else
		{
			stacks->a->next->next = stacks->a;
			stacks->a->next->prev = NULL;
			stacks->a->next = NULL;
			stacks->a->prev = tmp;
			stacks->a = tmp;
		}
	}
}

void	sb(t_all *stacks)
{
	t_stack	*tmp;

	if (stacks->b != NULL && stacks->b->next != NULL)
	{
		tmp = stacks->b->next;
		if (stacks->b->next->next != NULL)
		{
			stacks->b->next->next->prev = stacks->b;
			stacks->b->next = stacks->b->next->next;
			stacks->b->prev = tmp;
			stacks->b->prev->prev = NULL;
			stacks->b->prev->next = stacks->b;
			stacks->b = stacks->b->prev;
		}
		else
		{
			stacks->b->next->next = stacks->b;
			stacks->b->next->prev = NULL;
			stacks->b->next = NULL;
			stacks->b->prev = tmp;
			stacks->b = tmp;
		}
	}
}

void	ss(t_all *stacks)
{
	sa(stacks);
	sb(stacks);
	stacks->operations_ct++;
	if (stacks->flag == 1)
		ft_putstr("ss\n");
}

void	pa(t_all *stacks)
{
	t_stack	*tmp;

	if (stacks->b != NULL)
	{
		tmp = stacks->a;
		while (tmp != NULL)
			tmp = tmp->next;
		tmp = stacks->b->next;
		add_elem_front(&(stacks->a), stacks->b);
		stacks->b = tmp;
		if (stacks->b != NULL)
			stacks->b->prev = NULL;
		while (tmp != NULL)
			tmp = tmp->next;
	}
	stacks->operations_ct++;
	if (stacks->flag == 1)
		ft_putstr("pa\n");
}

void	pb(t_all *stacks)
{
	t_stack	*tmp;

	if (stacks->a != NULL)
	{
		tmp = stacks->b;
		while (tmp != NULL)
			tmp = tmp->next;
		tmp = stacks->a->next;
		add_elem_front(&(stacks->b), stacks->a);
		stacks->a = tmp;
		if (stacks->a != NULL)
			stacks->a->prev = NULL;
		while (tmp != NULL)
			tmp = tmp->next;
	}
	stacks->operations_ct++;
	if (stacks->flag == 1)
		ft_putstr("pb\n");
}
