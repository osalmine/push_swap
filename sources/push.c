/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:01:19 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/10 14:27:47 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_up(t_ps *stack)
{
	t_ps	ref;
	int		i;

	ref = *(stack);
	i = 0;
	while (i < ref.amount)
	{
		stack->values[i] = ref.values[i + 1];
		i++;
	}
}

void	rra_push_down(t_ps *stack)
{
	int		i;
	// char s[1];

//	ft_printf("BEF ANYTHING IN PUSH DOWN\n");
//	read(0, s, 1);
	// ft_printf("RRA PUSH DOWN\n");
	i = stack->amount - 1;
	// ft_printf("i: %d, amount: %d\n", i, stack->amount);
	// ft_printf("stack before pushing:\n");
	// for (int k = 0; k < stack->amount; k++) {
	// 	ft_printf("[%d]: %d\n", k, stack->values[k]);
	// }
	// read(0, s, 1);
	while (i > 0 && stack->amount > 0)
	{
		// ft_printf("i in push down: %d\n", i);
		stack->values[i] = stack->values[i - 1];
		// ft_printf("Check leak in while loop\n");
		// ft_printf("stack->values[%d] = tmp[%d - 1] : %d\n", i, i, stack->values[i - 1]);
		// ft_printf("stack:\n");
		// for (int j = 0; j < stack->amount; j++) {
		// 	ft_printf("[%d]: %d\n", j, stack->values[j]);
		// }
		// read(0, s, 1);
		i--;
	}
	// ft_printf("AFTER PUSHING IN PUSH DOWN\n");
	// read(0, s, 1);
}

void	push_down(t_ps *stack)
{
	int		i;
	// char s[1];

//	ft_printf("BEF ANYTHING IN PUSH DOWN\n");
//	read(0, s, 1);
	// ft_printf("PUSH DOWN\n");
	i = stack->amount;
	// ft_printf("i: %d, amount: %d\n", i, stack->amount);
	// ft_printf("stack before pushing:\n");
	// for (int k = 0; k < stack->amount; k++) {
	// 	ft_printf("[%d]: %d\n", k, stack->values[k]);
	// }
	// read(0, s, 1);
	while (i > 0 && stack->amount > 0)
	{
		// ft_printf("i in push down: %d\n", i);
		stack->values[i] = stack->values[i - 1];
		// ft_printf("Check leak in while loop\n");
		// ft_printf("stack->values[%d] = tmp[%d - 1] : %d\n", i, i, stack->values[i - 1]);
		// ft_printf("stack:\n");
		// for (int j = 0; j < stack->amount; j++) {
		// 	ft_printf("[%d]: %d\n", j, stack->values[j]);
		// }
		// read(0, s, 1);
		i--;
	}
	// ft_printf("AFTER PUSHING IN PUSH DOWN\n");
	// read(0, s, 1);
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
		if (a_stack->print == TRUE)
		{
			ft_printf("pa\n");
			// ft_printf("a stack:\n");
			// for (int a = 0; a < a_stack->amount; a++) {
			// 	ft_printf("[%d]: %d\n", a, a_stack->values[a]);
			// }
			// ft_printf("b stack:\n");
			// for (int j = 0; j < b_stack->amount; j++) {
			// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
			// }
		}
	}
}

void		pb(t_ps *a_stack, t_ps *b_stack)
{
//	char s[1];

//	read(0, s, 1);
	if (a_stack->amount > 0)
	{
		// ft_printf("a_stack->amount: %d\n", a_stack->amount);
		push_down(b_stack);
		// ft_printf("Push down ok\n");
		// ft_printf("\npushing val : %d from a to b\n", a_stack->values[0]);
		// ft_printf("b stack size : %d, amount : %d\n", b_stack->size, b_stack->amount);
		// ft_printf("b stack first val bef push : %d\n", b_stack->values[0]);
		b_stack->values[0] = a_stack->values[0];
		// ft_printf("Pushing to b stack ok\n");
		push_up(a_stack);
		b_stack->amount++;
		a_stack->amount--;
		// ft_printf("b stack after pb:\n");
		// for (int k = 0; k < b_stack->amount; k++) {
		// 	ft_printf("[%d]: %d\n", k, b_stack->values[k]);
		// }
		// ft_printf("\n");
//		read(0, s, 1);
		if (a_stack->print == TRUE)
		{
			ft_printf("pb\n");
			// ft_printf("a stack:\n");
			// for (int a = 0; a < a_stack->amount; a++) {
			// 	ft_printf("[%d]: %d\n", a, a_stack->values[a]);
			// }
			// ft_printf("b stack:\n");
			// for (int j = 0; j < b_stack->amount; j++) {
			// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
			// }
		}
	}
}
