/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:25:05 by osalmine          #+#    #+#             */
/*   Updated: 2020/03/02 19:25:14 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				opt_rot(int a_moves, int b_moves)
{
	if ((a_moves < 0 && b_moves < 0) || (a_moves > 0 && b_moves > 0))
	{
		if (ft_abs(a_moves) > ft_abs(b_moves))
			return (ft_abs(a_moves));
		else
			return (ft_abs(b_moves));
	}
	return (0);
}

int				moves_to_top(t_ps *stack, int nb)
{
	int moves;

	moves = find_in_stack(stack->values, stack->amount, nb);
	moves = (stack->amount / 2) < moves ? -(stack->amount - moves) : moves;
	return (moves);
}

static t_list	*replace(t_list *cmds, char *current, char *to_find, \
															char *to_replace)
{
	t_list *ptr;
	t_list *prev;

	prev = cmds;
	cmds = cmds->next;
	while (cmds && ft_strequ((char*)(cmds->content), current))
	{
		ptr = cmds;
		while (ptr && (ft_strequ(ptr->content, current) || \
										ft_strequ(ptr->content, to_replace)))
			ptr = ptr->next;
		if (ptr && ft_strequ(ptr->content, to_find))
		{
			free((char*)(ptr->content));
			ptr->content = ft_strdup(to_replace);
			prev->next = cmds->next;
			free((char*)(cmds->content));
			free(cmds);
			cmds = prev;
		}
		else
			break ;
	}
	return (cmds);
}

t_list			*combine_cmds(t_list *cmds)
{
	t_list *head;

	ft_lstrev(&cmds);
	head = cmds;
	while (cmds->next)
	{
		if (cmds->next && ft_strequ((char*)(cmds->next->content), "ra"))
			cmds = replace(cmds, "ra", "rb", "rr");
		else if (cmds->next && ft_strequ((char*)(cmds->next->content), "rb"))
			cmds = replace(cmds, "rb", "ra", "rr");
		else if (cmds->next && ft_strequ((char*)(cmds->next->content), "rra"))
			cmds = replace(cmds, "rra", "rrb", "rrr");
		else if (cmds->next && ft_strequ((char*)(cmds->next->content), "rrb"))
			cmds = replace(cmds, "rrb", "rra", "rrr");
		else
			cmds = cmds->next;
	}
	return (head);
}

void			ft_small_big(t_ps *stack)
{
	int smallest;
	int largest;
	int amount;

	amount = stack->amount - 1;
	smallest = stack->values[amount];
	largest = stack->values[amount];
	while (amount-- > 0)
	{
		if (stack->values[amount] < smallest)
			smallest = stack->values[amount];
		if (stack->values[amount] > largest)
			largest = stack->values[amount];
	}
	stack->smallest = smallest;
	stack->largest = largest;
	if (stack->sorted_amount > 0)
	{
		amount = stack->sorted_amount - 1;
		largest = stack->sorted[amount];
		while (amount-- > 0)
			if (stack->sorted[amount] > largest)
				largest = stack->sorted[amount];
		stack->sorted_max = largest;
	}
}
