/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:14:57 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/10 13:02:59 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_split(t_ps *a_stack, t_ps *b_stack, int med, t_ps *ref)
{
	// int num;
	// int i;
	int j;
	// int numb = a_stack->values[a_stack->amount - 1];
	int limit;
	int nbs_und_med;
	// char s[1];

	// ft_printf(GREEN"\n\nFT_SPLIT\n\n"RESET);
	// i = 0;
	j = a_stack->amount - 1;
	limit = 0;
	// ft_printf("BEFORE COUNT a stack:\n");
	// for (int a = 0; a < a_stack->amount; a++) {
	// 	ft_printf("[%d]: %d\n", a, a_stack->values[a]);
	// }
	nbs_und_med = nbs_under_med(a_stack, med) - amount_in_order(ref, a_stack);
	// ft_printf("\nMed : %d\n", med);
	// ft_printf("nbs_under_med: %d, amount_in_order: %d\n", nbs_under_med(a_stack, med), amount_in_order(ref, a_stack));
	// ft_printf("Nbs und med: %d\n", nbs_und_med);
	// ft_printf("median is: %d, j (stack amount - 1) is: %d\n", med, j);
	while (j-- > 0 && !is_in_order(*a_stack, 1) && nbs_und_med > 0)
	{
		// ft_printf("\nNbs und med: %d\n", nbs_und_med);
		// ft_printf("amount in order: %d\n", amount_in_order(ref, a_stack));
		ft_small_big(a_stack);
		if ((next_in_order(ref, a_stack) \
			|| a_stack->values[0] == a_stack->smallest)
			&& !is_in_order(*a_stack, 1) && !(a_stack->amount - find_in_stack(a_stack, a_stack->sorted_bot) < a_stack->amount / 2))
		{
			ra(a_stack);
			a_stack->sorted_bot = a_stack->values[a_stack->amount - 1];
			limit++;
			nbs_und_med--;
			// ft_printf(BOLD RED"YEET\n"RESET);
			// read (0, s, 1);
		}
		// else if (!is_in_order(*a_stack, 1))
		// 	while (a_stack->values[a_stack->amount - 1] != i && i != 0)
		// 		rra(a_stack);
		else if (b_next_int_order(ref, a_stack, b_stack))
		{
			pa(a_stack, b_stack);
			ra(a_stack);
			a_stack->sorted_bot = a_stack->values[a_stack->amount - 1];
			limit++;
			// ft_printf(BOLD RED"NOOOO\n"RESET);
			// read (0, s, 1);
		}
		else if (!is_in_order(*a_stack, 1) && aft_next_in_order(ref, a_stack) &&
				a_stack->amount - amount_in_order(ref, a_stack) <= 2)
			sa(a_stack);
		else
		{
			next_nb_under_med(ref, a_stack, b_stack, med);
			nbs_und_med--;
			j++;
		}
		// else if (a_stack->values[0] <= med)
		// {
		// 	pb(a_stack, b_stack);
		// 	j++;
		// 	nbs_und_med--;
		// }
		// else if (j > 0)
		// 	ra(a_stack);
		// if (find_in_stack(a_stack, a_stack->smallest))
		// ft_printf("\nj is : %d\n", j);
		// ft_printf("\na stack:\n");
		// for (int k = 0; k < a_stack->amount; k++) {
		// 	ft_printf("[%d]: %d\n", k, a_stack->values[k]);
		// }
		// ft_printf("b stack:\n");
		// for (int j = 0; j < b_stack->amount; j++) {
		// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
		// }
	}
	// if ((next_in_order(ref, a_stack) \
	// 	|| a_stack->values[0] == a_stack->smallest) && nbs_und_med > 0)
	// {
	// 	ra(a_stack);
	// 	i = a_stack->values[a_stack->amount - 1];
	// }
	// ft_printf(RED"\nSTACKS BEFORE RA ROTATION\n"RESET);
	// ft_printf("largest sorted nb: %d\n", a_stack->sorted_bot);
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
	// ft_printf("a_stack->amount - 1 (%d) - find_in_stack (: %d) = %d. a_stack->amount (%d) / 2 = %d\n", a_stack->amount - 1, find_in_stack(a_stack, a_stack->sorted_bot), (a_stack->amount - 1) - find_in_stack(a_stack, a_stack->sorted_bot), a_stack->amount - 1, (a_stack->amount - 1) / 2);
	if ((a_stack->amount - 1) - find_in_stack(a_stack, a_stack->sorted_bot) < (a_stack->amount - 1) / 2)
		while (a_stack->values[a_stack->amount - 1] != a_stack->sorted_bot && a_stack->sorted_bot != 0)
			rra(a_stack);
	else
		while (a_stack->values[a_stack->amount - 1] != a_stack->sorted_bot && a_stack->sorted_bot != 0)
		{
			// ft_printf("a stack, i: %d:\n", i);
			// for (int i = 0; i < a_stack->amount; i++) {
			// 	ft_printf("[%d]: %d\n", i, a_stack->values[i]);
			// }
			ra(a_stack);
			// ft_printf(BOLD RED"fuck\n"RESET);
			// read (0, s, 1);
		}
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
	return (limit);
}

void	ft_insert(t_ps *a_stack, t_ps *b_stack, t_ps *ref, int limit)
{
	// int i;
	// int num;
	// char s[1];

	// ft_printf(GREEN"\n\nFT_INSERT\n\n"RESET);

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
		while (b_stack->values[0] != b_stack->largest \
				&& b_stack->values[0] != b_stack->smallest)
		{
			rb(b_stack);
			// ft_printf("b stack:\n");
			// for (int i = 0; i < b_stack->amount; i++) {
			// 	ft_printf("[%d]: %d\n", i, b_stack->values[i]);
			// }
		}
		pa(a_stack, b_stack);
		// ft_printf(BLUE"stack amount (%d) - limit (%d) = %d\n"RESET, a_stack->amount, limit, a_stack->amount - limit);
		// ft_printf(BLUE"is in order : %s\n"RESET, !is_in_order(*a_stack, 1) ? "no" : "yes");
		if (a_stack->amount - limit == 2 && !is_in_order(*a_stack, 1) && b_stack->amount == 0)
		{
			sa(a_stack);
			// ra(a_stack);
			// ra(a_stack);
			// return ;
			// ft_printf("a stack:\n");
			// for (int k = 0; k < a_stack->amount; k++) {
			// 	ft_printf("[%d]: %d\n", k, a_stack->values[k]);
			// }
			// ft_printf("b stack:\n");
			// for (int l = 0; l < b_stack->amount; l++) {
			// 	ft_printf("[%d]: %d\n", l, b_stack->values[l]);
			// }

		}
		while (next_in_order(ref, a_stack) && !is_in_order(*a_stack, 1))
		{
			ra(a_stack);
			a_stack->sorted_bot = a_stack->values[a_stack->amount - 1];
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
		// ft_printf(BLUE"\nEXITING INSERT WITH SORTED BOT: %d\n"RESET, a_stack->sorted_bot);
	}
}

void	solve(t_ps *a_stack, t_ps *b_stack)
{
	int		med;
	t_ps	*ref;
	t_ps	*order;
	// char s[1];
	int		limit;

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
	order = b_init(a_stack);
	a_stack->sorted_bot = 0;
	while (!is_in_order(*a_stack, 1))
	{
		limit = ft_split(a_stack, b_stack, med, ref);
		ft_insert(a_stack, b_stack, ref, limit);
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
	if (a_stack->size > 5)
		solve(a_stack, b_stack);
	else
		solve_small(a_stack, b_stack);
	free_struct(a_stack);
	free_struct(b_stack);
	return (0);
}
