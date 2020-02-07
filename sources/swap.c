/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:01:19 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/07 19:44:24 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_ps *a_stack)
{
	int temp;

	if (a_stack->amount > 1)
	{
		temp = a_stack->values[0];
		a_stack->values[0] = a_stack->values[1];
		a_stack->values[1] = temp;
		if (a_stack->print == TRUE)
		{
			ft_printf("sa\n");
			// ft_printf("a stack:\n");
			// for (int a = 0; a < a_stack->amount; a++) {
			// 	ft_printf("[%d]: %d\n", a, a_stack->values[a]);
			// }
		}
	}
}

void	sb(t_ps *b_stack)
{
	int temp;

	if (b_stack->amount > 1)
	{
		temp = b_stack->values[0];
		b_stack->values[0] = b_stack->values[1];
		b_stack->values[1] = temp;
		if (b_stack->print == TRUE)
		{
			ft_printf("sb\n");
			// ft_printf("b stack:\n");
			// for (int j = 0; j < b_stack->amount; j++) {
			// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
			// }
		}
	}
}

void	ss(t_ps *a_stack, t_ps *b_stack)
{
	sa(a_stack);
	sb(b_stack);
	if (a_stack->print == TRUE)
	{
		ft_printf("ss\n");
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
