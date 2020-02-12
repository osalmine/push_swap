/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:03:29 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/12 14:12:15 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_dups(t_ps *stack)
{
	int i;
	int j;

	i = 0;
	while (i < stack->amount)
	{
		j = i + 1;
		while (j < stack->amount)
		{
			if (stack->values[i] == stack->values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void		ft_parse_nb(char **av, int ac, t_ps *stack)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_strequ(av[1], "-v"))
		i++;
	if (!(stack->values = (int*)malloc(sizeof(int) * (ac - (i + 1)))))
		ft_exit("Parse malloc error");
	if (!(stack->sorted = (int*)malloc(sizeof(int) * (ac - (i + 1)))))
		ft_exit("Parse malloc error");
	while (i < ac - 1)
	{
		if (ft_atoi(av[i + 1]) > 2147483647 || ft_atoi(av[i + 1]) < -2147483648
			|| (!ft_isdigit(av[i + 1][ft_strlen(av[i + 1]) - 1])
			&& av[i + 1][ft_strlen(av[i + 1]) - 1] != 0)
			|| (!ft_isdigit(av[i + 1][0]) && av[i + 1][0] != '-'))
			ft_exit("Number parse error");
		stack->values[j] = ft_atoi(av[i + 1]);
		i++;
		j++;
		stack->amount++;
	}
	stack->size = stack->amount;
}

static void	str_val_alloc(char **tmp, t_ps *stack)
{
	int len;

	len = 0;
	while (tmp[len])
		len++;
	if (!(stack->values = (int*)malloc(sizeof(int) * len)))
		ft_exit("String malloc error");
	if (!(stack->sorted = (int*)malloc(sizeof(int) * len)))
		ft_exit("String malloc error");
}

void		ft_parse_str(char *str, t_ps *stack)
{
	int		amount;
	int		i;
	char	**tmp;

	amount = 0;
	i = 0;
	tmp = ft_strsplit(str, ' ');
	str_val_alloc(tmp, stack);
	while (tmp[i] != NULL)
	{
		if (ft_isdigit(tmp[i][0]) || tmp[i][0] == '-')
		{
			if ((!ft_isdigit(tmp[i][ft_nbs(ft_atoi(tmp[i]))]) &&
				tmp[i][ft_nbs(ft_atoi(tmp[i]))])
			|| ft_atoi(tmp[i]) > 2147483647 || ft_atoi(tmp[i]) < -2147483648)
				ft_exit("String parse error");
			stack->values[i] = ft_atoi(tmp[i]);
			stack->amount++;
		}
		else
			ft_exit("Error: Non-digits in string");
		i++;
	}
	free_strsplit(&tmp);
	stack->size = stack->amount;
}

t_ps		*parse(int ac, char **av)
{
	t_ps	*stack;
	int		i;

	i = 1;
	stack = NULL;
	if (ac >= 2)
	{
		if (!(stack = (t_ps*)malloc(sizeof(t_ps))))
			ft_exit("Parse malloc error");
		stack->amount = 0;
		stack->sorted_amount = 0;
		if (ac >= 2 && ft_strequ(av[1], "-v"))
		{
			stack->visual = TRUE;
			i++;
		}
		if ((long long)ft_strlen(av[i]) > ft_atoi(av[i]))
			ft_parse_str(av[i], stack);
		else
			ft_parse_nb(av, ac, stack);
		if (check_dups(stack))
			ft_exit("Error: Duplicate numbers");
		ft_small_big(stack);
	}
	return (stack);
}
