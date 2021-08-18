/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:46:48 by vbeech            #+#    #+#             */
/*   Updated: 2021/05/17 12:46:49 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_elem(int num)
{
	t_stack	*elem;

	elem = (t_stack *)malloc(sizeof(t_stack));
	if (elem == NULL)
		return (NULL);
	elem->num = num;
	elem->flag = 0;
	elem->order = -1;
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}

void	add_elem_back(t_stack **stack, t_stack *new)
{
	t_stack	*copy;

	if (stack != NULL)
	{
		copy = *stack;
		if (copy == NULL)
			*stack = new;
		else
		{
			while (copy->next != NULL)
				copy = copy->next;
			copy->next = new;
			copy->next->prev = copy;
			copy->next->next = NULL;
		}
	}
}

void	add_elem_front(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
	{
		*stack = new;
		(*stack)->next = NULL;
		(*stack)->prev = NULL;
	}
	else
	{
		new->next = *stack;
		new->prev = NULL;
		(*stack)->prev = new;
		*stack = new;
	}
}

int	stack_len(t_stack *stack)
{
	t_stack	*tmp;
	int		count;

	tmp = stack;
	count = 0;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	overflow_check(char *argv)
{
	char	*itoa;

	itoa = ft_itoa(ft_atoi(argv));
	if (ft_strlen(argv) > 11 || ft_strcmp(argv, itoa) != 0)
	{
		free(itoa);
		return (-1);
	}
	free(itoa);
	return (0);
}
