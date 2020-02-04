/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:14:57 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/04 14:19:14 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	solve(t_ps *a_stack, t_ps *b_stack, int med)
{
	a_stack = NULL;
	b_stack = NULL;
	med = 0;
}

int main(int argc, char **argv)
{
	t_ps	*a_stack;
	t_ps	*b_stack;
	int		med;

	if (argc < 2)
		return (0);
	a_stack = parse(argc, argv);
	if (a_stack != NULL)
		ft_putendl("OK");
	else
		ft_exit("Error");
	med = median(*a_stack);
	b_stack = b_init(a_stack);
	return (0);
}
