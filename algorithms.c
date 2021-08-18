/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:10:49 by vbeech            #+#    #+#             */
/*   Updated: 2021/05/26 15:10:51 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	greater_than(t_stack *a, t_stack *markup_head)
{
	int		prev;
	t_stack	*tmp;

	prev = markup_head->num;
	tmp = markup_head->next;
	markup_head->flag = 1;
	if (tmp == NULL)
		tmp = a;
	while (tmp != markup_head)
	{
		if (tmp->num > prev)
		{
			tmp->flag = 1;
			prev = tmp->num;
		}
		else
			tmp->flag = 0;
		tmp = tmp->next;
		if (tmp == NULL)
			tmp = a;
	}
}

void	by_index(t_stack *a, t_stack *markup_head)
{
	int		prev;
	t_stack	*tmp;

	prev = markup_head->order;
	tmp = markup_head->next;
	markup_head->flag = 1;
	if (tmp == NULL)
		tmp = a;
	while (tmp != markup_head)
	{
		if ((tmp->order - prev) == 1)
		{
			tmp->flag = 1;
			prev++;
		}
		else
			tmp->flag = 0;
		tmp = tmp->next;
		if (tmp == NULL)
			tmp = a;
	}
}
