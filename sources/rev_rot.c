/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:25:51 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/01 15:26:41 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_ps *a_stack)
{
	int tmp;

	tmp = a_stack->values[a_stack->amount - 1];
	push_down(a_stack);
	a_stack->values[0] = tmp;
	if (a_stack->print == TRUE)
		ft_printf("rra\n");
}

void	rrb(t_ps *b_stack)
{
	int tmp;

	tmp = b_stack->values[b_stack->amount - 1];
	push_down(b_stack);
	b_stack->values[0] = tmp;
	if (b_stack->print == TRUE)
		ft_printf("rrb\n");
}

void	rrr(t_ps *a_stack, t_ps *b_stack)
{
	rra(a_stack);
	rrb(b_stack);
	if (a_stack->print == TRUE)
		ft_printf("rrr\n");
}
