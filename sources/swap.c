/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:01:19 by osalmine          #+#    #+#             */
/*   Updated: 2020/03/03 13:17:11 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*sa(t_ps *a_stack, t_list *cmds)
{
	int temp;

	if (a_stack->amount > 1)
	{
		temp = a_stack->values[0];
		a_stack->values[0] = a_stack->values[1];
		a_stack->values[1] = temp;
		if (a_stack->print == TRUE && cmds)
		{
			if (cmds->content == NULL)
			{
				free(cmds);
				cmds = NULL;
			}
			ft_lstadd(&cmds, ft_lstnew("sa", sizeof(char*)));
		}
	}
	return (cmds);
}

t_list	*sb(t_ps *b_stack, t_list *cmds)
{
	int temp;

	if (b_stack->amount > 1)
	{
		temp = b_stack->values[0];
		b_stack->values[0] = b_stack->values[1];
		b_stack->values[1] = temp;
		if (b_stack->print == TRUE && cmds)
			ft_lstadd(&cmds, ft_lstnew("sb", sizeof(char*)));
	}
	return (cmds);
}

t_list	*ss(t_ps *a_stack, t_ps *b_stack, t_list *cmds)
{
	sa(a_stack, NULL);
	sb(b_stack, NULL);
	if (a_stack->print == TRUE && cmds)
		ft_lstadd(&cmds, ft_lstnew("ss", sizeof(char*)));
	return (cmds);
}
