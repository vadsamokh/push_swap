/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markups.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:10:14 by vbeech            #+#    #+#             */
/*   Updated: 2021/05/26 15:10:19 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_order(t_all *stacks)
{
	t_stack	*tmp;
	int		i;
	int		min;

	i = 0;
	tmp = stacks->a;
	while (tmp != NULL)
	{
		tmp = stacks->a;
		min = INT_MAX;
		while (tmp != NULL)
		{
			if (tmp->num <= min && tmp->order == -1)
				min = tmp->num;
			tmp = tmp->next;
		}
		tmp = stacks->a;
		while (tmp != NULL && tmp->num != min)
			tmp = tmp->next;
		if (tmp != NULL)
			tmp->order = i;
		if (tmp != NULL && tmp->num == INT_MAX)
			break ;
		i++;
	}
}

int	count_flags(t_stack *a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	while (tmp != NULL)
	{
		if (tmp->flag == 1)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	check_algo(t_all *stacks, t_stack *markup_head, int best_flg, int *best_ord)
{
	if (stacks->algo == 0)
		greater_than(stacks->a, markup_head);
	else
		by_index(stacks->a, markup_head);
	if ((count_flags(stacks->a) > best_flg)
		|| ((count_flags(stacks->a) == best_flg)
			&& (markup_head->order < *best_ord)))
	{
		best_flg = count_flags(stacks->a);
		*best_ord = markup_head->order;
	}
	return (best_flg);
}

int	find_best_markup(t_all *stacks)
{
	t_stack	*markup_head;
	int		i;
	int		best_flg;
	int		best_ord;
	int		tmp;

	i = 0;
	best_flg = 0;
	best_ord = -1;
	markup_head = stacks->a;
	while (markup_head != NULL)
	{
		tmp = check_algo(stacks, markup_head, best_flg, &best_ord);
		if (best_flg < tmp)
			best_flg = tmp;
		markup_head = markup_head->next;
		i++;
	}
	return (best_ord);
}

void	set_flags(t_all *stacks, int best_ord)
{
	t_stack	*markup_head;

	markup_head = stacks->a;
	while (markup_head->order != best_ord)
		markup_head = markup_head->next;
	if (stacks->algo == 0)
		greater_than(stacks->a, markup_head);
	else
		by_index(stacks->a, markup_head);
}
