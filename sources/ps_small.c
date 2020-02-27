/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:49:45 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/25 10:27:48 by osalmine         ###   ########.fr       */
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
		pa(a_stack, b_stack, NULL);
		if (is_in_order(*a_stack, 1))
		{
			pb(a_stack, b_stack, NULL);
			a_stack->print = stack_print_copy;
			b_stack->print = stack_print_copy;
			return (1);
		}
		pb(a_stack, b_stack, NULL);
		a_stack->print = stack_print_copy;
		b_stack->print = stack_print_copy;
	}
	return (0);
}

static t_list	*sm_nb_under_med(t_ps *ref, t_ps *a_stack, t_ps *b_stack, int med, t_list *cmds)
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
	cmds = fast_rotate(a_stack, i, 'a', 't', cmds);
	if (b_next_sm(a_stack, b_stack))
		cmds = pa(a_stack, b_stack, cmds);
	else if (!is_in_order(*a_stack, 1))
		cmds = pb(a_stack, b_stack, cmds);
	return (cmds);
}

t_list		*solve_3(t_ps *a_stack, t_list *cmds)
{
	int i;

	if (a_stack->amount <= 1)
		return (cmds);
	i = a_stack->amount - 1;
	if (is_in_order(*a_stack, 1))
		return (cmds);
	if (a_stack->amount == 2)
		cmds = sa(a_stack, cmds);
	ft_small_big(a_stack);
	while (!is_in_order(*a_stack, 0))
	{
		if (a_stack->largest == a_stack->values[i])
			cmds = sa(a_stack, cmds);
		else if (a_stack->smallest == a_stack->values[0])
		{
			cmds = sa(a_stack, cmds);
			cmds = ra(a_stack, cmds);
		}
		else
			cmds = ra(a_stack, cmds);
	}
	return (cmds);
}

t_list		*solve_small(t_ps *a_stack, t_ps *b_stack, t_list *cmds)
{
	int		med;
	t_ps	*ref;
	// char s[1];

	med = median(a_stack, 0);
	ref = ref_stack(a_stack);
	if (a_stack->amount > 3)
	{
		while (a_stack->smallest < med && !is_in_order(*a_stack, 1))
		{
			// read (0, s, 1);
			if (b_next_sm(a_stack, b_stack))
				cmds = pa(a_stack, b_stack, cmds);
			else
				cmds = sm_nb_under_med(ref, a_stack, b_stack, med, cmds);
			ft_small_big(a_stack);
			// ft_printf("median: %d, a stack smallest: %d\n", med, a_stack->smallest);
			// read (0, s, 1);
		}
		cmds = solve_3(a_stack, cmds);
		while (b_stack->amount)
			cmds = pa(a_stack, b_stack, cmds);
		if (!is_in_order(*a_stack, 1))
			cmds = sa(a_stack, cmds);
	}
	else
		cmds = solve_3(a_stack, cmds);
	free_struct(ref);
	return (cmds);
}
