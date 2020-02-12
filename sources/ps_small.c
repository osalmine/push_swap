/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:49:45 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/12 13:42:23 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	b_next_sm(t_ps* a_stack, t_ps *b_stack)
{
	int stack_print_copy;

	stack_print_copy = a_stack->print;
	if (!is_in_order(*a_stack, 1) && a_stack->amount >= 1 \
		&& b_stack->amount >= 1)
	{
		a_stack->print = FALSE;
		b_stack->print = FALSE;
		pa(a_stack, b_stack);
		if (is_in_order(*a_stack, 1))
		{
			pb(a_stack, b_stack);
			a_stack->print = stack_print_copy;
			b_stack->print = stack_print_copy;
			return (1);
		}
		pb(a_stack, b_stack);
		a_stack->print = stack_print_copy;
		b_stack->print = stack_print_copy;
	}
	return (0);
}

static void	sm_nb_under_med(t_ps *ref, t_ps *a_stack, t_ps *b_stack, int med)
{
	int top;
	int bottom;
	int ordered;
	int i;

	top = 0;
	ordered = amount_in_order(ref, a_stack);
	bottom = a_stack->amount - 1 - ordered;
	while (top < a_stack->amount)
	{
		if (a_stack->values[top] < med)
			break ;
		top++;
	}
	while (bottom > 0)
	{
		if (a_stack->values[bottom] < med)
			break ;
		bottom--;
	}
	i = (a_stack->amount - bottom) < top ? bottom : top;
	fast_rotate(a_stack, i, 'a');
	if (b_next_sm(a_stack, b_stack))
		pa(a_stack, b_stack);
	else if (!is_in_order(*a_stack, 1))
		pb(a_stack, b_stack);
}

void		solve_3(t_ps *a_stack)
{
	int i;

	if (a_stack->amount <= 1)
		return ;
	i = a_stack->amount - 1;
	if (is_in_order(*a_stack, 1))
		return ;
	if (a_stack->amount == 2)
		sa(a_stack);
	ft_small_big(a_stack);
	while (!is_in_order(*a_stack, 0))
	{
		if (a_stack->largest == a_stack->values[i])
			sa(a_stack);
		else if (a_stack->smallest == a_stack->values[0])
		{
			sa(a_stack);
			ra(a_stack);
		}
		else
			ra(a_stack);
	}
}

void		solve_small(t_ps *a_stack, t_ps *b_stack)
{
	int		med;
	t_ps	*ref;
	// char s[1];

	med = median(a_stack, 0);
	ref = ref_stack(a_stack);
	// ft_printf("Solve small\n");
	if (a_stack->amount > 3)
	{
		while (a_stack->smallest < med && !is_in_order(*a_stack, 1))
		{
			// read (0, s, 1);
			if (b_next_sm(a_stack, b_stack))
				pa(a_stack, b_stack);
			else
				sm_nb_under_med(ref, a_stack, b_stack, med);
			ft_small_big(a_stack);
			// ft_printf("median: %d, a stack smallest: %d\n", med, a_stack->smallest);
			// read (0, s, 1);
		}
		solve_3(a_stack);
		while (b_stack->amount)
			pa(a_stack, b_stack);
		if (!is_in_order(*a_stack, 1))
			sa(a_stack);
	}
	else
		solve_3(a_stack);
}
