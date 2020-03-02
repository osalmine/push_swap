/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:14:57 by osalmine          #+#    #+#             */
/*   Updated: 2020/03/02 19:24:51 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_split(t_ps *a_stack, t_ps *b_stack, t_list *cmds)
{
	while (a_stack->amount > 3)
	{
		while (a_stack->values[0] != a_stack->largest \
			&& a_stack->values[0] != a_stack->smallest && a_stack->amount > 3)
			cmds = pb(a_stack, b_stack, cmds);
		if (a_stack->amount > 3)
			cmds = ra(a_stack, cmds);
	}
	cmds = solve_3(a_stack, cmds);
	cmds = ft_insert(a_stack, b_stack, cmds);
	return (cmds);
}

t_list	*ft_insert(t_ps *a_stack, t_ps *b_stack, t_list *cmds)
{
	int *optimal;

	while (!is_in_order(*a_stack, 1) && b_stack->amount > 0)
	{
		optimal = prefer_index_b(a_stack, b_stack);
		cmds = fast_rotate_top(b_stack, optimal[0], 'b', cmds);
		cmds = fast_rotate_top(a_stack, optimal[1], 'a', cmds);
		cmds = pa(a_stack, b_stack, cmds);
		free(optimal);
	}
	cmds = fast_rotate_bot(a_stack, find_in_stack(a_stack->values, \
					a_stack->amount, a_stack->largest), 'a', cmds);
	return (cmds);
}

int		main(int argc, char **argv)
{
	t_ps	*a_stack;
	t_ps	*b_stack;
	t_list	*cmds;

	cmds = cmds_init();
	if (argc < 2)
		return (0);
	if (!(a_stack = parse(argc, argv)))
		ft_exit("Parse error");
	a_stack->print = TRUE;
	if (is_in_order(*a_stack, 1))
		return (0);
	b_stack = b_init(a_stack);
	ft_small_big(a_stack);
	if (a_stack->size > 5)
		cmds = ft_split(a_stack, b_stack, cmds);
	else
		cmds = solve_small(a_stack, b_stack, cmds);
	free_struct(a_stack);
	free_struct(b_stack);
	cmds = combine_cmds(cmds);
	cmds = print_cmds(cmds);
	cmds = free_lst(cmds);
	return (0);
}
