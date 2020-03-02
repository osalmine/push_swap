/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:09:16 by osalmine          #+#    #+#             */
/*   Updated: 2020/03/02 14:38:34 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*return_ind(int *ind, t_ps *a_stack, t_ps *b_stack, int opt_moves)
{
	int i;
	int	cur_moves;

	i = 1;
	while (i < b_stack->amount)
	{
		cur_moves = ft_abs(moves_to_top(b_stack, b_stack->values[i])) + \
				ft_abs(next_spot(a_stack, b_stack, b_stack->values[i], 'm'));
		if (opt_rot(next_spot(a_stack, b_stack, b_stack->values[i], 'm'), \
								moves_to_top(b_stack, b_stack->values[i])) != 0)
			cur_moves = opt_rot(next_spot(a_stack, b_stack, b_stack->values[i],\
							'm'), moves_to_top(b_stack, b_stack->values[i]));
		if (opt_moves > cur_moves)
		{
			ind[0] = i;
			ind[1] = next_spot(a_stack, b_stack, b_stack->values[i], 'n');
			opt_moves = cur_moves;
		}
		i++;
	}
	return (ind);
}

int			*prefer_index_b(t_ps *a_stack, t_ps *b_stack)
{
	int *ind;
	int	opt_moves;

	if (!(ind = (int*)malloc(sizeof(int) * 2)))
		ft_exit("Error");
	ind[0] = 0;
	ind[1] = ft_abs(next_spot(a_stack, b_stack, b_stack->values[0], 'n'));
	if (b_stack->amount == 1)
		return (ind);
	opt_moves = ft_abs(moves_to_top(b_stack, b_stack->values[0])) + \
				ft_abs(next_spot(a_stack, b_stack, b_stack->values[0], 'm'));
	opt_moves -= opt_rot(next_spot(a_stack, b_stack, b_stack->values[0], 'm'), \
									moves_to_top(b_stack, b_stack->values[0]));
	ind = return_ind(ind, a_stack, b_stack, opt_moves);
	return (ind);
}

static void	get_top(t_ps *a_stack, int nb, int *top)
{
	while (*top <= a_stack->amount / 2)
	{
		if (*top == 0 && a_stack->values[*top] > nb \
								&& a_stack->values[a_stack->amount - 1] < nb)
			break ;
		else if (a_stack->values[*top] < nb && a_stack->values[*top + 1] > nb)
		{
			(*top)++;
			break ;
		}
		(*top)++;
	}
}

static void	get_bottom(t_ps *a_stack, int nb, int *bottom)
{
	while (*bottom >= a_stack->amount / 2)
	{
		if (*bottom == a_stack->amount - 1 && a_stack->values[*bottom] < nb \
													&& a_stack->values[0] > nb)
			break ;
		if (a_stack->values[*bottom] > nb && a_stack->values[*bottom - 1] < nb)
			break ;
		(*bottom)--;
	}
}

int			next_spot(t_ps *a_stack, t_ps *b_stack, int nb, char move)
{
	int top;
	int bottom;
	int moves;

	top = 0;
	bottom = a_stack->amount - 1;
	get_top(a_stack, nb, &top);
	get_bottom(a_stack, nb, &bottom);
	b_stack->values = b_stack->values;
	if (move == 'm')
		moves = (a_stack->amount - bottom) < top ? -(a_stack->amount - bottom) \
																		: top;
	else
		moves = (a_stack->amount - bottom) < top ? bottom : top;
	return (moves);
}
