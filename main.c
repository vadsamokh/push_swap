/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:23:32 by vbeech            #+#    #+#             */
/*   Updated: 2021/05/17 12:23:34 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(char *str)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (i == 0)
		{
			if (str[i] == '-' && ft_strlen(str) < 2)
				return (-1);
			if (str[i] != '-' && (str[i] < '0' || str[i] > '9'))
				return (-1);
		}
		else if ((i > 0) && (str[i] < '0' || str[i] > '9'))
			return (-1);
		i++;
	}
	return (0);
}

int	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (i < (argc - 1))
	{
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (-1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	init_list(int argc, char **argv, t_all *stacks)
{
	int		i;
	int		num;
	t_stack	*tmp;

	stacks->a = NULL;
	stacks->b = NULL;
	stacks->operations_ct = 0;
	i = 1;
	while (i < argc)
	{
		if (check_input(argv[i]) < 0)
			return (-1);
		num = ft_atoi(argv[i]);
		if (overflow_check(argv[i]) < 0)
			error_msg();
		tmp = create_elem(num);
		if (tmp == NULL)
			error_msg();
		add_elem_back(&(stacks->a), tmp);
		i++;
	}
	set_order(stacks);
	return (0);
}

void	error_msg(void)
{
	ft_putstr("Error\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_all	stacks1;
	t_all	stacks2;
	t_all	stacks3;
	int		count0;
	int		count1;

	if (argc == 1)
		return (0);
	stacks1.flag = 0;
	stacks2.flag = 0;
	stacks3.flag = 1;
	stacks1.algo = 0;
	stacks2.algo = 1;
	if ((check_duplicates(argc, argv) < 0)
		|| (init_list(argc, argv, &stacks1) < 0)
		|| (init_list(argc, argv, &stacks2) < 0)
		|| (init_list(argc, argv, &stacks3) < 0))
		error_msg();
	count0 = sorting(&stacks1, argc);
	count1 = sorting(&stacks2, argc);
	if (count1 < count0)
		stacks3.algo = 1;
	else
		stacks3.algo = 0;
	sorting(&stacks3, argc);
}
