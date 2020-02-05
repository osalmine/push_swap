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

void	quicksort(int *data, int n)
{
	int i;
	int j;
	int v;

	if (n <= 1)
		return ;
	v = data[0];
	i = 0;
	j = n;
	while (1)
	{
		while (data[i] < v && i < n)
			i++;
		while (data[j] > v)
			j--;
		if (i >= j)
			break ;
		swap(&data[i], &data[j]);
	}
	swap(&data[i - 1], &data[0]);
	quicksort(data, i - 1);
	quicksort(data + i, n - i);
}

void	ft_split(t_ps *a_stack, t_ps *b_stack, int med)
{
	int i;

	while (a_stack->smallest <= med)
	{
		ft_printf("a_stack smallest: %d\n", a_stack->smallest);
		i = a_stack->values[find_in_stack(a_stack, a_stack->smallest)]aa;
		ft_printf("i: %d, stack size / 2: %d\n", i, a_stack->size / 2);
		ft_printf("a_stack values[0]: %d\n", a_stack->values[0]);
		if (i < a_stack->size / 2)
			while (a_stack->values[0] != i)
				ra(a_stack);
		else
			while (a_stack->values[0] != i)
				rra(a_stack);
		pb(a_stack, b_stack);
		ft_small_big(a_stack);
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

void	solve(t_ps *a_stack, t_ps *b_stack, int med)
{
	if (a_stack->amount <= 3)
		solve_3(a_stack);
	ft_split(a_stack, b_stack, med);
	ft_printf("a stack:\n");
	for (int i = 0; i < a_stack->amount; i++) {
		ft_printf("[%d]: %d\n", i, a_stack->values[i]);
	}
	ft_printf("b stack:\n");
	for (int j = 0; j < b_stack->amount; j++) {
		ft_printf("[%d]: %d\n", j, b_stack->values[j]);
	}
	med = 0;
}

int		main(int argc, char **argv)
{
	t_ps	*a_stack;
	t_ps	*b_stack;
	int		med;

	if (argc < 2)
		return (0);
	a_stack = parse(argc, argv);
	if (is_in_order(*a_stack, 1))
	{
		ft_printf("OK\n");
		return (0);
	}
	ft_printf("a stack before median:\n");
	for (int j = 0; j < a_stack->amount; j++) {
		ft_printf("[%d]: %d\n", j, a_stack->values[j]);
	}
	med = median(a_stack);
	ft_printf("a stack after median:\n");
	for (int i = 0; i < a_stack->amount; i++) {
		ft_printf("[%d]: %d\n", i, a_stack->values[i]);
	}
	b_stack = b_init(a_stack);
	ft_printf("stack size (%d) / 2 = %d\n", a_stack->size, a_stack->size / 2);
	solve(a_stack, b_stack, med);
	free_struct(a_stack);
	free_struct(b_stack);
	return (0);
}
