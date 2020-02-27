/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:49:48 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/12 15:27:05 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_in_order(t_ps stack, int check_size)
{
	if (check_size && stack.size != stack.amount)
		return (0);
	while (stack.amount - 1 > 0)
	{
		if (stack.values[stack.amount - 1] < stack.values[stack.amount - 2])
			return (0);
		stack.amount--;
	}
	// ft_printf("Is in order!\n");
	return (1);
}

void	do_command(t_ps *a_stack, t_ps *b_stack, char *str)
{
	// ft_printf("Command: %s\n", str);
	if (ft_strequ("sa", str))
		sa(a_stack, NULL);
	else if (ft_strequ("sb", str))
		sb(b_stack, NULL);
	else if (ft_strequ("ss", str))
		ss(a_stack, b_stack, NULL);
	else if (ft_strequ("pa", str))
		pa(a_stack, b_stack, NULL);
	else if (ft_strequ("pb", str))
		pb(a_stack, b_stack, NULL);
	else if (ft_strequ("ra", str))
		ra(a_stack, NULL);
	else if (ft_strequ("rb", str))
		rb(b_stack, NULL);
	else if (ft_strequ("rr", str))
		rr(a_stack, b_stack, NULL);
	else if (ft_strequ("rra", str))
		rra(a_stack, NULL);
	else if (ft_strequ("rrb", str))
		rrb(b_stack, NULL);
	else if (ft_strequ("rrr", str))
		rrr(a_stack, b_stack, NULL);
	else
		ft_exit("Command error");
	// ft_printf("a_stack:\n");
	// for (int j = 0; j < a_stack->amount; j++) {
	// 	ft_printf("%d: %d\n", j, a_stack->values[j]);
	// }
	// ft_printf("b_stack:\n");
	// for (int k = 0; k < b_stack->amount; k++) {
	// 	ft_printf("%d: %d\n", k, b_stack->values[k]);
	// }
}
