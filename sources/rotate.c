/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:15:17 by osalmine          #+#    #+#             */
/*   Updated: 2020/03/02 10:29:14 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ra(t_ps *a_stack, t_list *cmds)
{
	int tmp;

	tmp = a_stack->values[0];
	push_up(a_stack);
	a_stack->values[a_stack->amount - 1] = tmp;
	if (a_stack->print == TRUE && cmds)
		ft_lstadd(&cmds, ft_lstnew("ra", sizeof(char*)));
	return (cmds);
}

t_list	*rb(t_ps *b_stack, t_list *cmds)
{
	int tmp;

	tmp = b_stack->values[0];
	push_up(b_stack);
	b_stack->values[b_stack->amount - 1] = tmp;
	if (b_stack->print == TRUE && cmds)
		ft_lstadd(&cmds, ft_lstnew("rb", sizeof(char*)));
	return (cmds);
}

t_list	*rr(t_ps *a_stack, t_ps *b_stack, t_list *cmds)
{
	ra(a_stack, NULL);
	rb(b_stack, NULL);
	if (a_stack->print == TRUE && cmds)
		ft_lstadd(&cmds, ft_lstnew("rr", sizeof(char*)));
	return (cmds);
}
