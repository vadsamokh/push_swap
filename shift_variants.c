/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_variants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:56:11 by vbeech            #+#    #+#             */
/*   Updated: 2021/06/01 11:56:15 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	up_up(t_all *stacks, int num_a, int num_b, int min_shifts)
{
	int		ct_a;
	int		ct_b;
	int		shifts;

	ct_a = -num_a;
	ct_b = -num_b;
	shifts = -(ft_min(ct_a, ct_b));
	if (shifts < min_shifts)
	{
		min_shifts = shifts;
		stacks->ct_a = ct_a;
		stacks->ct_b = ct_b;
	}
	return (min_shifts);
}

int	down_down(t_all *stacks, int num_a, int num_b, int min_shifts)
{
	int		ct_a;
	int		ct_b;
	int		shifts;

	ct_a = stack_len(stacks->a) - num_a;
	ct_b = stack_len(stacks->b) - num_b;
	if (num_a == 0)
		ct_a = 0;
	if (num_b == 0)
		ct_b = 0;
	shifts = ft_max(ct_a, ct_b);
	if (shifts < min_shifts)
	{
		min_shifts = shifts;
		stacks->ct_a = ct_a;
		stacks->ct_b = ct_b;
	}
	return (min_shifts);
}

int	up_down(t_all *stacks, int num_a, int num_b, int min_shifts)
{
	int		ct_a;
	int		ct_b;
	int		shifts;

	ct_a = -num_a;
	ct_b = stack_len(stacks->b) - num_b;
	if (num_b == 0)
		ct_b = 0;
	shifts = -ct_a + ct_b;
	if (shifts < min_shifts)
	{
		min_shifts = shifts;
		stacks->ct_a = ct_a;
		stacks->ct_b = ct_b;
	}
	return (min_shifts);
}

int	down_up(t_all *stacks, int num_a, int num_b, int min_shifts)
{
	int		ct_a;
	int		ct_b;
	int		shifts;

	ct_a = stack_len(stacks->a) - num_a;
	ct_b = -num_b;
	if (num_a == 0)
		ct_a = 0;
	shifts = ct_a - ct_b;
	if (shifts < min_shifts)
	{
		min_shifts = shifts;
		stacks->ct_a = ct_a;
		stacks->ct_b = ct_b;
	}
	return (min_shifts);
}
