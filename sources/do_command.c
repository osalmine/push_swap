/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:49:48 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/27 17:01:05 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	do_command(t_ps *a_stack, t_ps *b_stack, char *str)
{
	a_stack = NULL;
	b_stack = NULL;
	if (ft_strequ("sa", str))
		sa(a_stack);
	else if (ft_strequ("sb", str))
		sb(b_stack);
	else if (ft_strequ("ss", str))
		ss(a_stack, b_stack);
	else
		ft_exit("Error");
}
