/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:25:51 by osalmine          #+#    #+#             */
/*   Updated: 2020/03/02 19:22:44 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*rra(t_ps *a_stack, t_list *cmds)
{
	int tmp;

	tmp = a_stack->values[a_stack->amount - 1];
	rra_push_down(a_stack);
	a_stack->values[0] = tmp;
	if (a_stack->print == TRUE && cmds)
		ft_lstadd(&cmds, ft_lstnew("rra", sizeof(char*)));
	return (cmds);
}

t_list	*rrb(t_ps *b_stack, t_list *cmds)
{
	int tmp;

	tmp = b_stack->values[b_stack->amount - 1];
	push_down(b_stack);
	b_stack->values[0] = tmp;
	if (b_stack->print == TRUE && cmds)
		ft_lstadd(&cmds, ft_lstnew("rrb", sizeof(char*)));
	return (cmds);
}

t_list	*rrr(t_ps *a_stack, t_ps *b_stack, t_list *cmds)
{
	rra(a_stack, NULL);
	rrb(b_stack, NULL);
	if (a_stack->print == TRUE && cmds)
		ft_lstadd(&cmds, ft_lstnew("rrr", sizeof(char*)));
	return (cmds);
}
