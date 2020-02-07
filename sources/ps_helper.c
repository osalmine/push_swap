/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:09:16 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/07 19:43:33 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	next_nb_under_med(t_ps *ref, t_ps *a_stack, t_ps *b_stack, int med)
{
	int top;
	int bottom;
	int ordered;
	int i;

	top = 0;
	// ft_printf(UNDERLINE RED"\n\nNEXT NB UNDER MEDIAN\n\n"RESET);
	ordered = amount_in_order(ref, a_stack);
	// ft_printf("\nAmount of numbers ordered in the bottom of the stack: %d\n", ordered);
	bottom = a_stack->amount - 1 - ordered;
	// ft_printf("Median is %d\n", med);
	// ft_printf("Bottom start pos: %d\n", bottom);
	while (top < a_stack->amount)
	{
		// ft_printf("CURRENT TOP (%d) VALUE INSPECTED: %d\n", top, a_stack->values[top]);
		if (a_stack->values[top] <= med)
			break ;
		top++;
	}
	while (bottom > 0)
	{
		// ft_printf("CURRENT BOT (%d) VALUE INSPECTED: %d\n", bottom, a_stack->values[bottom]);
		if (a_stack->values[bottom] <= med)
			break ;
		bottom--;
	}
	// ft_printf("Top first found nb at index:\t%d\n", top);
	// ft_printf("Bottom first found nb at index:\t%d\n", bottom);
	i = (a_stack->amount - bottom) < top ? bottom : top;
	// ft_printf("next nb under median is in index: %d\n", i);
	fast_rotate(a_stack, i);
	pb(a_stack, b_stack);
	// ft_printf("AFTER PB. Ordered: %d, (a_stack->amount (%d) - bottom (%d)) = %d < top (%d)\n", ordered, a_stack->amount, bottom, a_stack->amount - bottom, top);
//	while (ordered-- && (a_stack->amount - bottom) < top)
//		ra(a_stack);
}

void	fast_rotate(t_ps *stack, int pos)
{
	int nb;
	// char s[1];

	// ft_printf("pos in fast rot: %d\n", pos);
	nb = stack->values[pos];
	// ft_printf("nb in fast rot: %d\n", nb);
	if (stack->amount / 2 < pos)
		while (stack->values[0] != nb)
		{
			rra(stack);
			// ft_printf(RED BOLD "RRAAAAAAAA\n"RESET);
			// read(0, s, 1);
		}
	else
		while (stack->values[0] != nb)
		{
			ra(stack);
			// ft_printf(RED BOLD "RAAAAAAAAA\n"RESET);
			// read(0, s, 1);
		}
}
