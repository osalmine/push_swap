/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:14:57 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/12 15:26:57 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_split(t_ps *a_stack, t_ps *b_stack, int med, t_ps *ref)
{
	// int numb = a_stack->values[a_stack->amount - 1];
	int nbs_und_med;
	// char s[1];

	// ft_printf(GREEN"\n\nFT_SPLIT\n\n"RESET);
	nbs_und_med = nbs_under_med(a_stack, med) - a_stack->sorted_amount;
	// ft_printf("\nMed : %d\n", med);
	// ft_printf("nbs_under_med: %d, a_stack sorted amount: %d\n", nbs_under_med(a_stack, med), a_stack->sorted_amount);
	// ft_printf("Nbs und med (counter): %d\n", nbs_und_med);
	// ft_printf("median is: %d, j (stack amount (%d) - 1) is: %d\n", med, a_stack->amount, j);
	//read (0, s, 1);

	while (!is_in_order(*a_stack, 1) && nbs_und_med >= 0)
	{
		ft_small_big(a_stack);
		nbs_und_med = nbs_under_med(a_stack, med) - a_stack->sorted_amount;
		// ft_printf("\n\nNew loop\n\nb_und_med : %d. If either hits 0, while loop stops\n", nbs_und_med);
		// ft_printf("a_stack->smallest: %d\n", a_stack->smallest);
		// ft_printf("a_stack sorted amount: %d\n", a_stack->sorted_amount);
		// ft_printf("a stack:\n");
		// for (int i = 0; i < a_stack->amount; i++) {
		// 	ft_printf("[%d]: %d\n", i, a_stack->values[i]);
		// }
		// ft_printf("b stack:\n");
		// for (int j = 0; j < b_stack->amount; j++) {
		// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
		// }
		// ft_printf("Sorted arr\n");
		// for (int i = 0; i < a_stack->sorted_amount; i++) {
		// 	ft_printf("[%d]: %d\n", i, a_stack->sorted[i]);
		// }
		// read (0, s, 1);
		if ((next_in_order(ref, a_stack) \
			|| a_stack->values[0] == a_stack->smallest)
			&& !is_in_order(*a_stack, 1) && find_in_stack(a_stack->sorted, a_stack->sorted_amount, a_stack->values[0]) == -1)
		{
			ra(a_stack);
			add_sorted(a_stack, a_stack->values[a_stack->amount - 1]);
			// ft_printf(BOLD RED"YEET\n"RESET);
			// read (0, s, 1);
		}
		else if (b_next_int_order(ref, a_stack, b_stack))
		{
			pa(a_stack, b_stack);
			ra(a_stack);
			add_sorted(a_stack, a_stack->values[a_stack->amount - 1]);
			// ft_printf(BOLD RED"NOOOO\n"RESET);
			// read (0, s, 1);
		}
		else if (!is_in_order(*a_stack, 1) && aft_next_in_order(ref, a_stack) &&
				a_stack->amount - a_stack->sorted_amount <= 2)
			sa(a_stack);
		else
		{
			next_nb_under_med(ref, a_stack, b_stack, med);
			nbs_und_med--;
		}
	}
	// ft_printf(RED"\nSTACKS BEFORE RA ROTATION\n"RESET);
	// ft_printf("largest sorted nb: %d\n", a_stack->sorted_max);
	// ft_printf("a_stack->amount : %d\n", a_stack->amount);
	// ft_printf("a stack:\n");
	// for (int i = 0; i < a_stack->amount; i++) {
	// 	if (a_stack->values[i] == numb)
	// 		ft_printf(RED"[%d]: %d\n"RESET, i, a_stack->values[i]);
	// 	else
	// 		ft_printf("[%d]: %d\n", i, a_stack->values[i]);
	// }
	// ft_printf("b stack:\n");
	// for (int j = 0; j < b_stack->amount; j++) {
	// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
	// }
	// ft_printf("Checking if it's faster to ra or rra to get sorted part to bottom:\n");
	// ft_printf("a_stack->amount - 1 (%d) - find_in_stack (: %d) = %d. a_stack->amount (%d) / 2 = %d\n", a_stack->amount - 1, find_in_stack(a_stack->values, a_stack->amount, a_stack->sorted_max), (a_stack->amount - 1) - find_in_stack(a_stack->values, a_stack->amount, a_stack->sorted_max), a_stack->amount - 1, (a_stack->amount - 1) / 2);
	if ((a_stack->amount - 1) - find_in_stack(a_stack->values, a_stack->amount, a_stack->sorted_max) < (a_stack->amount - 1) / 2 && !is_in_order(*a_stack, 1))
		while (a_stack->values[a_stack->amount - 1] != a_stack->sorted_max && a_stack->sorted_max != 0)
			rra(a_stack);
	else if (!is_in_order(*a_stack, 1))
		while (a_stack->values[a_stack->amount - 1] != a_stack->sorted_max && a_stack->sorted_max != 0)
			ra(a_stack);
	// ft_printf(RED"\nSTACKS AFTER SPLITTING\n"RESET);
	// ft_printf("a stack:\n");
	// for (int i = 0; i < a_stack->amount; i++) {
	// 	ft_printf("[%d]: %d\n", i, a_stack->values[i]);
	// }
	// ft_printf("b stack:\n");
	// for (int j = 0; j < b_stack->amount; j++) {
	// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
	// }
	// ft_printf("Returned limit from split: %d\n", limit);
}

void	ft_insert(t_ps *a_stack, t_ps *b_stack, t_ps *ref)
{
	// char s[1];

	// ft_printf(GREEN"\n\nFT_INSERT\n\n"RESET);
	// read (0, s, 1);
	// ft_printf("a stack:\n");
	// for (int a = 0; a < a_stack->amount; a++) {
	// 	ft_printf("[%d]: %d\n", a, a_stack->values[a]);
	// }
	// ft_printf("b stack:\n");
	// for (int j = 0; j < b_stack->amount; j++) {
	// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
	// }
	while (b_stack->amount != 0 && !is_in_order(*a_stack, 1))
	{
		ft_small_big(b_stack);
		ft_small_big(a_stack);
		if (b_stack->amount > 1)
			b_fast_rot(a_stack, b_stack);
		else
			pa(a_stack, b_stack);
		// while (b_stack->values[0] != b_stack->largest \
		// 		&& b_stack->values[0] != b_stack->smallest)
		// {
		// 	rb(b_stack);
		// 	// ft_printf("b stack:\n");
		// 	// for (int i = 0; i < b_stack->amount; i++) {
		// 	// 	ft_printf("[%d]: %d\n", i, b_stack->values[i]);
		// 	// }
		// }
		// pa(a_stack, b_stack);
		// ft_printf(BLUE"stack amount (%d)\n"RESET, b_stack->amount);
		// ft_printf(BLUE"is in order : %s\n"RESET, !is_in_order(*a_stack, 1) ? "no" : "yes");
		if (a_stack->amount - a_stack->sorted_amount == 2 && !is_in_order(*a_stack, 1) && b_stack->amount == 0)
			sa(a_stack);
		while (next_in_order(ref, a_stack) && !is_in_order(*a_stack, 1))
		{
			ra(a_stack);
			add_sorted(a_stack, a_stack->values[a_stack->amount - 1]);
			// ft_printf(BOLD RED"AAAAAAAAAAA\n"RESET);
			// read (0, s, 1);
		}
		// ft_printf("a stack:\n");
		// for (int k = 0; k < a_stack->amount; k++) {
		// 	ft_printf("[%d]: %d\n", k, a_stack->values[k]);
		// }
		// ft_printf("b stack:\n");
		// for (int l = 0; l < b_stack->amount; l++) {
		// 	ft_printf("[%d]: %d\n", l, b_stack->values[l]);
		// }
		// read (0, s, 1);
	}
	// ft_printf(BLUE"\nEXITING INSERT WITH SORTED BOT: %d\n"RESET, a_stack->sorted_max);
}

void	solve(t_ps *a_stack, t_ps *b_stack)
{
	int		med;
	t_ps	*ref;
	// char s[1];

	med = median(a_stack, 0);
	// ft_printf("a stack:\n");
	// for (int i = 0; i < a_stack->amount; i++) {
	// 	ft_printf("[%d]: %d\n", i, a_stack->values[i]);
	// }
	// ft_printf("b stack:\n");
	// for (int j = 0; j < b_stack->amount; j++) {
	// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
	// }
	ref = ref_stack(a_stack);
	add_sorted(a_stack, a_stack->smallest);
	// ft_printf("a stack amount: %d\n", a_stack->amount);
	while (!is_in_order(*a_stack, 1))
	{
		ft_split(a_stack, b_stack, med, ref);
		ft_insert(a_stack, b_stack, ref);
		med = median(a_stack, 1);
		// ft_printf("median : %d\n", med);
		// ft_printf("a stack:\n");
		// for (int i = 0; i < a_stack->amount; i++) {
		// 	ft_printf("[%d]: %d\n", i, a_stack->values[i]);
		// }
		// ft_printf("b stack:\n");
		// for (int j = 0; j < b_stack->amount; j++) {
		// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
		// }
		// read (0, s, 1);
		// ft_printf(RED BOLD"\n\nNEW ROUND\n\n"RESET);
	}
	free_struct(ref);
	// ft_printf(BG_WHITE BLACK"FINAL STACKS:"RESET);
	// ft_printf("\na stack:\n");
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
	a_stack->print = TRUE;
	b_stack = b_init(a_stack);
	ft_small_big(a_stack);
	if (a_stack->size > 5)
		solve(a_stack, b_stack);
	else
		solve_small(a_stack, b_stack);
	free_struct(a_stack);
	free_struct(b_stack);
	return (0);
}
