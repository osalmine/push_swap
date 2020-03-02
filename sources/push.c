/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:01:19 by osalmine          #+#    #+#             */
/*   Updated: 2020/03/02 10:35:44 by osalmine         ###   ########.fr       */
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

	i = stack->amount - 1;
	while (i > 0 && stack->amount > 0)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
}

void	push_down(t_ps *stack)
{
	int		i;

	i = stack->amount;
	while (i > 0 && stack->amount > 0)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
}

t_list	*pa(t_ps *a_stack, t_ps *b_stack, t_list *cmds)
{
	if (b_stack->amount > 0)
	{
		push_down(a_stack);
		a_stack->values[0] = b_stack->values[0];
		push_up(b_stack);
		a_stack->amount++;
		b_stack->amount--;
		if (a_stack->print == TRUE && cmds)
			ft_lstadd(&cmds, ft_lstnew("pa", sizeof(char*)));
	}
	return (cmds);
}

t_list	*pb(t_ps *a_stack, t_ps *b_stack, t_list *cmds)
{
	if (a_stack->amount > 0)
	{
		push_down(b_stack);
		b_stack->values[0] = a_stack->values[0];
		push_up(a_stack);
		b_stack->amount++;
		a_stack->amount--;
		if (a_stack->print == TRUE && cmds)
			ft_lstadd(&cmds, ft_lstnew("pb", sizeof(char*)));
	}
	return (cmds);
}
