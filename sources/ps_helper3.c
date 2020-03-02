/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:39:52 by osalmine          #+#    #+#             */
/*   Updated: 2020/03/02 19:19:35 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list			*cmds_init(void)
{
	t_list *cmds;

	cmds = (t_list*)malloc(sizeof(t_list));
	cmds->content = NULL;
	return (cmds);
}

t_list			*fast_rotate_top(t_ps *stack, int pos, char ab, t_list *cmds)
{
	int nb;
	int i;

	if (pos > stack->amount)
		ft_exit("Error: index doesn't exist");
	nb = stack->values[pos];
	i = 0;
	if (stack->amount / 2 < pos)
		while (stack->values[i] != nb)
		{
			if (ab == 'a')
				cmds = rra(stack, cmds);
			else
				cmds = rrb(stack, cmds);
		}
	else
		while (stack->values[i] != nb)
		{
			if (ab == 'a')
				cmds = ra(stack, cmds);
			else
				cmds = rb(stack, cmds);
		}
	return (cmds);
}

t_list			*fast_rotate_bot(t_ps *stack, int pos, char ab, t_list *cmds)
{
	int nb;
	int i;

	if (pos > stack->amount)
		ft_exit("Error: index doesn't exist");
	nb = stack->values[pos];
	i = stack->amount - 1;
	if (stack->amount / 2 < pos)
		while (stack->values[i] != nb)
		{
			if (ab == 'a')
				cmds = rra(stack, cmds);
			else
				cmds = rrb(stack, cmds);
		}
	else
		while (stack->values[i] != nb)
		{
			if (ab == 'a')
				cmds = ra(stack, cmds);
			else
				cmds = rb(stack, cmds);
		}
	return (cmds);
}

int				amount_in_order(t_ps *ref, t_ps *stack)
{
	int amount;
	int i;
	int count;

	count = 0;
	amount = stack->amount - 1;
	i = find_in_stack(ref->values, ref->amount, stack->values[amount]);
	while (i >= 0)
	{
		if (ref->values[i] != stack->values[amount])
			return (0);
		count++;
		i--;
		amount--;
	}
	if (count == 0 && stack->values[stack->amount - 1] == stack->smallest)
		return (1);
	return (count);
}
