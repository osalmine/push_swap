/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:02:48 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/10 15:34:06 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ps	*b_init(t_ps *a_stack)
{
	t_ps	*b_stack;

	if (!(b_stack = (t_ps*)malloc(sizeof(t_ps))))
		ft_exit("B init malloc error");
	if (!(b_stack->values = (int*)malloc(sizeof(int) * a_stack->size)))
		ft_exit("B init malloc error");
	if (!(b_stack->sorted = (int*)malloc(sizeof(int) * a_stack->size)))
		ft_exit("B init malloc error");
	b_stack->amount = 0;
	b_stack->size = a_stack->size;
	b_stack->print = a_stack->print;
	b_stack->sorted_amount = a_stack->sorted_amount;
	return (b_stack);
}
