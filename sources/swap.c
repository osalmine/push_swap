/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:01:19 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/10 14:28:21 by osalmine         ###   ########.fr       */
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
			ft_lstadd(&cmds, ft_lstnew("sa", sizeof(char*)));
			// ft_printf("Cmds head: ");
			// ft_printf("%s\n", cmds->content);
			// ft_printf("a stack:\n");
			// for (int a = 0; a < a_stack->amount; a++) {
			// 	ft_printf("[%d]: %d\n", a, a_stack->values[a]);
			// }
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
		{
			ft_lstadd(&cmds, ft_lstnew("sb", sizeof(char*)));
			// ft_printf("b stack:\n");
			// for (int j = 0; j < b_stack->amount; j++) {
			// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
			// }
		}
	}
	return (cmds);
}

t_list	*ss(t_ps *a_stack, t_ps *b_stack, t_list *cmds)
{
	sa(a_stack, NULL);
	sb(b_stack, NULL);
	if (a_stack->print == TRUE && cmds)
	{
		ft_lstadd(&cmds, ft_lstnew("ss", sizeof(char*)));
		// ft_printf("a stack:\n");
		// for (int a = 0; a < a_stack->amount; a++) {
		// 	ft_printf("[%d]: %d\n", a, a_stack->values[a]);
		// }
		// ft_printf("b stack:\n");
		// for (int j = 0; j < b_stack->amount; j++) {
		// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
		// }
	}
	return (cmds);
}
