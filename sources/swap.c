/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:01:19 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/27 17:14:11 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	sa(t_ps *a_stack)
{
	int temp;

	printf("ok\n");
	printf("amount: %d\n", a_stack->amount);
	printf("a_stack->values[1]: %d\n", a_stack->values[1]);
	temp = a_stack->values[1];
	printf("temp: %d\n", temp);
	a_stack->values[1] = a_stack->values[0];
	a_stack->values[0] = temp;
}

void	sb(t_ps *b_stack)
{
	int temp;

	temp = b_stack->values[1];
	b_stack->values[1] = b_stack->values[0];
	b_stack->values[0] = temp;
}

void	ss(t_ps *a_stack, t_ps *b_stack)
{
	sa(a_stack);
	sb(b_stack);
}
