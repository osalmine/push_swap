/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:15:17 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/05 15:31:32 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_ps *a_stack)
{
	int tmp;

//	ft_printf("val[0]: %d\n", a_stack->values[0]);
	tmp = a_stack->values[0];
	push_up(a_stack);
	a_stack->values[a_stack->amount - 1] = tmp;
}

void	rb(t_ps *b_stack)
{
	int tmp;

	tmp = b_stack->values[0];
	push_up(b_stack);
	b_stack->values[b_stack->amount - 1] = tmp;
}

void	rr(t_ps *a_stack, t_ps *b_stack)
{
	ra(a_stack);
	rb(b_stack);
}
