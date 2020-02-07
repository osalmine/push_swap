/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:25:05 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/07 12:03:23 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_with_ref(t_ps *ref, t_ps *stack)
{
	int amount;
	int i;

	amount = stack->amount - 1;
	i = find_in_stack(ref, stack->values[amount]);
	while (i)
		if (ref->values[i--] != stack->values[amount--])
			return (0);
	return (1);
}

int		next_in_order(t_ps *ref, t_ps *stack)
{
	int stack_print_copy;

	stack_print_copy = stack->print;
	if (check_with_ref(ref, stack))
	{
		stack->print = FALSE;
		ra(stack);
		if (check_with_ref(ref, stack))
		{
			rra(stack);
			stack->print = stack_print_copy;
			return (1);
		}
		rra(stack);
		stack->print = stack_print_copy;
	}
	return (0);
}

int		count_nbs_under_med(t_ps *stack, int med)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < stack->amount)
	{
		if (stack->values[i] <= med)
			count++;
		i++;
	}
	return (count);
}
