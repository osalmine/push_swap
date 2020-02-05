/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:14:57 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/05 15:59:37 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_split(t_ps *a_stack, t_ps *b_stack, int med)
{
	int num;
	int i;

	while (a_stack->smallest <= med)
	{
		i = find_in_stack(a_stack, a_stack->smallest);
		num = a_stack->values[i];
		if (i < a_stack->size / 2)
			while (a_stack->values[0] != num)
				ra(a_stack);
		else
			while (a_stack->values[0] != num)
				rra(a_stack);
		pb(a_stack, b_stack);
		ft_small_big(a_stack);
		ft_printf("a stack:\n");
		for (int i = 0; i < a_stack->amount; i++) {
			ft_printf("[%d]: %d\n", i, a_stack->values[i]);
		}
		ft_printf("b stack:\n");
		for (int j = 0; j < b_stack->amount; j++) {
			ft_printf("[%d]: %d\n", j, b_stack->values[j]);
		}
	}
}

void	ft_insert(t_ps *a_stack, t_ps *b_stack)
{
	int i;
	int num;

	ft_printf("a stack:\n");
	for (int a = 0; a < a_stack->amount; a++) {
		ft_printf("[%d]: %d\n", a, a_stack->values[a]);
	}
	ft_printf("b stack:\n");
	for (int j = 0; j < b_stack->amount; j++) {
		ft_printf("[%d]: %d\n", j, b_stack->values[j]);
	}
	ft_small_big(a_stack);
	i = find_in_stack(a_stack, a_stack->smallest);
	num = a_stack->values[i];
	if (i < a_stack->size / 2)
		while (a_stack->values[0] != num)
			ra(a_stack);
	else
		while (a_stack->values[0] != num)
			rra(a_stack);
	while (b_stack->amount)
		pa(a_stack, b_stack);
	ft_printf("a stack:\n");
	for (int k = 0; k < a_stack->amount; k++) {
		ft_printf("[%d]: %d\n", k, a_stack->values[k]);
	}
	ft_printf("b stack:\n");
	for (int l = 0; l < b_stack->amount; l++) {
		ft_printf("[%d]: %d\n", l, b_stack->values[l]);
	}
}

void	solve_3(t_ps *a_stack)
{
	int i;

	if (a_stack->amount <= 1)
		return ;
	i = a_stack->size - 1;
	while (i--)
	{

	}
}

void	solve(t_ps *a_stack, t_ps *b_stack)
{
	int med;

	med = median(a_stack);
	if (a_stack->amount <= 3)
		solve_3(a_stack);
	ft_printf("a stack:\n");
	for (int i = 0; i < a_stack->amount; i++) {
		ft_printf("[%d]: %d\n", i, a_stack->values[i]);
	}
	ft_printf("b stack:\n");
	for (int j = 0; j < b_stack->amount; j++) {
		ft_printf("[%d]: %d\n", j, b_stack->values[j]);
	}
	while (!is_in_order(*a_stack, 1))
	{
		ft_split(a_stack, b_stack, med);
		med = median(a_stack);
		ft_insert(a_stack, b_stack);
	}
}

int		main(int argc, char **argv)
{
	t_ps	*a_stack;
	t_ps	*b_stack;

	if (argc < 2)
		return (0);
	a_stack = parse(argc, argv);
	if (is_in_order(*a_stack, 1))
	{
		ft_printf("OK\n");
		return (0);
	}
	b_stack = b_init(a_stack);
	ft_printf("stack size (%d) / 2 = %d\n", a_stack->size, a_stack->size / 2);
	solve(a_stack, b_stack);
	free_struct(a_stack);
	free_struct(b_stack);
	return (0);
}
