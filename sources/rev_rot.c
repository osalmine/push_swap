/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:25:51 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/10 14:27:59 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_ps *a_stack)
{
	// char s[1];
	int tmp;

	// ft_printf("BEF ANYTHING IN RRA\n");
	// read(0, s, 1);
	tmp = a_stack->values[a_stack->amount - 1];
	// ft_printf("rra temp: %d\n", tmp);
	rra_push_down(a_stack);
	// ft_printf("AFT PUSH DOWN IN RRA\n");
	// read(0, s, 1);
	a_stack->values[0] = tmp;
	// ft_printf("stack after pushing:\n");
	// for (int k = 0; k < a_stack->amount; k++) {
	// 	ft_printf("[%d]: %d\n", k, a_stack->values[k]);
	// }
	if (a_stack->print == TRUE)
	{
		ft_printf("rra\n");
		// ft_printf("a stack:\n");
		// for (int a = 0; a < a_stack->amount; a++) {
		// 	ft_printf("[%d]: %d\n", a, a_stack->values[a]);
		// }
	}
}

void	rrb(t_ps *b_stack)
{
	int tmp;

	tmp = b_stack->values[b_stack->amount - 1];
	push_down(b_stack);
	b_stack->values[0] = tmp;
	if (b_stack->print == TRUE)
	{
		ft_printf("rrb\n");
		// ft_printf("b stack:\n");
		// for (int j = 0; j < b_stack->amount; j++) {
		// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
		// }
	}
}

void	rrr(t_ps *a_stack, t_ps *b_stack)
{
	rra(a_stack);
	rrb(b_stack);
	if (a_stack->print == TRUE)
	{
		ft_printf("rrr\n");
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
