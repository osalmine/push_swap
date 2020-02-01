/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:01:19 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/01 15:19:37 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_up(t_ps *stack)
{
	t_ps	ref;
	int		i;

	ref = *(stack);
	i = 0;
	while (i < ref.amount) {
		stack->values[i] = ref.values[i + 1];
		i++;
	}
}

void	push_down(t_ps *stack)
{
	t_ps	ref;
	int		i;

	ref = *(stack);
	i = ref.amount;
	while (i > 0 && ref.amount > 0)
	{
		stack->values[i] = ref.values[i - 1];
		i--;
	}
}

void		pa(t_ps *a_stack, t_ps *b_stack)
{
	if (b_stack->amount > 0)
	{
		push_down(a_stack);
		a_stack->values[0] = b_stack->values[0];
		push_up(b_stack);
		a_stack->amount++;
		b_stack->amount--;
	}
}

void		pb(t_ps *a_stack, t_ps *b_stack)
{
	if (a_stack->amount > 0)
	{
		push_down(b_stack);
		b_stack->values[0] = a_stack->values[0];
		push_up(a_stack);
		b_stack->amount++;
		a_stack->amount--;
	}
}
