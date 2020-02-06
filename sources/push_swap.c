/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:14:57 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/06 15:54:17 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_split(t_ps *a_stack, t_ps *b_stack, int med, t_ps *ref)
{
	int num;
	int i;

	ft_small_big(a_stack);
	if (ref->amount == 0)
	{
		ft_printf("ref is NULL, splitting whole stack\n");
		while (a_stack->smallest <= med)
		{
			if (a_stack->values[0] <= med)
				pb(a_stack, b_stack);
			ra(a_stack);
			// ft_printf("a stack bef pb:\n");
			// for (int i = 0; i < a_stack->amount; i++) {
			// 	ft_printf("[%d]: %d\n", i, a_stack->values[i]);
			// }
			// ft_printf("b stack bef pb:\n");
			// for (int j = 0; j < b_stack->amount; j++) {
			// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
			// }
			ft_small_big(a_stack);
			// ft_printf("a stack:\n");
			// for (int i = 0; i < a_stack->amount; i++) {
			// 	ft_printf("[%d]: %d\n", i, a_stack->values[i]);
			// }
			// ft_printf("b stack:\n");
			// for (int j = 0; j < b_stack->amount; j++) {
			// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
			// }
		}
	}
	else
	{
		ft_printf("ref is not NULL, splitting part stack\n");
		ft_printf("ref->smallest: %d, median: %d\n", ref->smallest, med);
		ft_printf("ref stack in split:\n", ref->amount);
		for (int k = 0; k < ref->amount; k++) {
			ft_printf("[%d]: %d\n", k, ref->values[k]);
		}
		while (ref->smallest <= med)
		{
			ft_printf("num : %d (i : %d)\n", num, i);
			if (a_stack->values[0] <= med &&
				find_in_stack(ref, a_stack->values[0] != -1))
				pb(a_stack, b_stack);
			ra(a_stack);
//			else
//				while (a_stack->values[0] != num)
//					rra(a_stack);
			// ft_printf("a stack bef pb:\n");
			// for (int i = 0; i < a_stack->amount; i++) {
			// 	ft_printf("[%d]: %d\n", i, a_stack->values[i]);
			// }
			// ft_printf("b stack bef pb:\n");
			// for (int j = 0; j < b_stack->amount; j++) {
			// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
			// }
			while (ref->values[0] != ref->smallest)
				ra(ref);
			push_up(ref);
			ref->amount--;
			ft_small_big(ref);
			ft_printf("\na stack after splitting:\n");
			for (int a = 0; a < a_stack->amount; a++) {
				ft_printf("[%d]: %d\n", a, a_stack->values[a]);
			}
			ft_printf("b stack after splpitting:\n");
			for (int b = 0; b < b_stack->amount; b++) {
				ft_printf("[%d]: %d\n", b, b_stack->values[b]);
			}
			ft_printf("\n");
		}
		free_struct(ref);
	}
}

void	ft_insert(t_ps *a_stack, t_ps *b_stack, t_ps *ref)
{
	int i;
	int num;

	// ft_printf("a stack:\n");
	// for (int a = 0; a < a_stack->amount; a++) {
	// 	ft_printf("[%d]: %d\n", a, a_stack->values[a]);
	// }
	// ft_printf("b stack:\n");
	// for (int j = 0; j < b_stack->amount; j++) {
	// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
	// }
	ft_small_big(b_stack);
	ft_small_big(a_stack);
	
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
	int		med;
	int		i;
	t_ps	*ref;
	char s[1];

	med = median(a_stack);
	if (a_stack->amount <= 3)
		solve_3(a_stack);
	i = a_stack->smallest;

	// ft_printf("a stack:\n");
	// for (int i = 0; i < a_stack->amount; i++) {
	// 	ft_printf("[%d]: %d\n", i, a_stack->values[i]);
	// }
	// ft_printf("b stack:\n");
	// for (int j = 0; j < b_stack->amount; j++) {
	// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
	// }
	ref = b_init(a_stack);
	while (!is_in_order(*a_stack, 1) && i < a_stack->largest)
	{
		ft_split(a_stack, b_stack, med, ref);
		med = median(a_stack);
		ft_insert(a_stack, b_stack, ref);
		ft_printf("i: %d, med: %d\n", i, med);
		ft_printf("a stack:\n");
		for (int i = 0; i < a_stack->amount; i++) {
			ft_printf("[%d]: %d\n", i, a_stack->values[i]);
		}
		ft_printf("b stack:\n");
		for (int j = 0; j < b_stack->amount; j++) {
			ft_printf("[%d]: %d\n", j, b_stack->values[j]);
		}
		read (0, s, 1);
		ft_printf("\n\nNEW ROUND\n\n");
	}
	// ft_printf("a stack:\n");
	// for (int i = 0; i < a_stack->amount; i++) {
	// 	ft_printf("[%d]: %d\n", i, a_stack->values[i]);
	// }
	// ft_printf("b stack:\n");
	// for (int j = 0; j < b_stack->amount; j++) {
	// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
	// }
}

int		main(int argc, char **argv)
{
	t_ps	*a_stack;
	t_ps	*b_stack;

	if (argc < 2)
		return (0);
	a_stack = parse(argc, argv);
	a_stack->print = TRUE;
	if (is_in_order(*a_stack, 1))
		return (0);
	b_stack = b_init(a_stack);
	// ft_printf("stack size (%d) / 2 = %d\n", a_stack->size, a_stack->size / 2);
	solve(a_stack, b_stack);
	free_struct(a_stack);
	free_struct(b_stack);
	return (0);
}
