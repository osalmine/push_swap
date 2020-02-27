/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:25:05 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/10 15:20:09 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int		check_with_ref(t_ps *ref, t_ps *stack)
// {
// 	int amount;
// 	int i;
//
// 	amount = stack->amount - 1;
// 	i = find_in_stack(ref->values, ref->amount, stack->values[amount]);
// 	while (i)
// 		if (ref->values[i--] != stack->values[amount--])
// 			return (0);
// 	return (1);
// }
//
int		amount_in_order(t_ps *ref, t_ps *stack)
{
	int amount;
	int i;
	int count;

	count = 0;
	amount = stack->amount - 1;
	// ft_printf("amount in order stack amount: %d, ref stack am: %d\n", stack->amount, ref->amount);
	// ft_printf("value in the bottom (%d) of the stack : %d\n", amount, stack->values[amount]);
	i = find_in_stack(ref->values, ref->amount, stack->values[amount]);
	// ft_printf("i: %d\n", i);
	while (i >= 0)
	{
		// ft_printf("Amnt while, stack->values[%d]: %d\n", amount, stack->values[amount]);
		if (ref->values[i] != stack->values[amount])
			return (0);
		count++;
		i--;
		amount--;
	}
	if (count == 0 && stack->values[stack->amount - 1] == stack->smallest)
		return (1);
	return (count);
}
//
// int		next_in_order(t_ps *ref, t_ps *stack)
// {
// 	int stack_print_copy;
//
// 	stack_print_copy = stack->print;
// 	if (check_with_ref(ref, stack) && stack->amount > 1)
// 	{
// 		stack->print = FALSE;
// 		ra(stack);
// 		if (check_with_ref(ref, stack))
// 		{
// 			rra(stack);
// 			stack->print = stack_print_copy;
// 			return (1);
// 		}
// 		rra(stack);
// 		stack->print = stack_print_copy;
// 	}
// 	return (0);
// }
//
// int		aft_next_in_order(t_ps *ref, t_ps *stack)
// {
// 	int stack_print_copy;
//
// 	stack_print_copy = stack->print;
// 	if (check_with_ref(ref, stack) && stack->amount > 1)
// 	{
// 		stack->print = FALSE;
// 		sa(stack);
// 		if (next_in_order(ref, stack))
// 		{
// 			sa(stack);
// 			stack->print = stack_print_copy;
// 			return (1);
// 		}
// 		sa(stack);
// 		stack->print = stack_print_copy;
// 	}
// 	return (0);
// }
//
// int		b_next_int_order(t_ps *ref, t_ps* a_stack, t_ps *b_stack)
// {
// 	int stack_print_copy;
//
// 	stack_print_copy = a_stack->print;
// 	if (check_with_ref(ref, a_stack) && a_stack->amount >= 1 \
// 		&& b_stack->amount >= 1)
// 	{
// 		a_stack->print = FALSE;
// 		b_stack->print = FALSE;
// 		pa(a_stack, b_stack);
// 		ra(a_stack);
// 		if (check_with_ref(ref, a_stack))
// 		{
// 			rra(a_stack);
// 			pb(a_stack, b_stack);
// 			a_stack->print = stack_print_copy;
// 			b_stack->print = stack_print_copy;
// 			return (1);
// 		}
// 		rra(a_stack);
// 		pb(a_stack, b_stack);
// 		a_stack->print = stack_print_copy;
// 		b_stack->print = stack_print_copy;
// 	}
// 	return (0);
// }
