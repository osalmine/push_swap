/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:14:57 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/01 16:21:30 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_ps	*a_stack;
	int		med;

	a_stack = parse(argc, argv);
	if (a_stack != NULL)
		ft_putendl("OK");
	else
		ft_exit("Error");
	med = median(*a_stack);
	return (0);
}
