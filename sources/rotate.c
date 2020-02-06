/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:15:17 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/06 11:17:02 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_ps *a_stack)
{
	int tmp;

	tmp = a_stack->values[0];
	push_up(a_stack);
	a_stack->values[a_stack->amount - 1] = tmp;
	if (a_stack->print == TRUE)
		ft_printf("ra\n");
}

void	rb(t_ps *b_stack)
{
	int tmp;

	tmp = b_stack->values[0];
	push_up(b_stack);
	b_stack->values[b_stack->amount - 1] = tmp;
	if (b_stack->print == TRUE)
		ft_printf("rb\n");
}

void	rr(t_ps *a_stack, t_ps *b_stack)
{
	ra(a_stack);
	rb(b_stack);
	if (a_stack->print == TRUE)
		ft_printf("rr\n");
}
