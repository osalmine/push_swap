/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:43:17 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/10 18:35:35 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

void	visual(t_ps *a_stack, t_ps *b_stack, char *command)
{
	int a;
	int b;
	int s;
	int val;

	a = 0;
	b = 0;
	s = 0;
	val = 0;
	if (a_stack->amount > 80)
		ft_exit("Visualizer max amount is 80");
	system("sleep 0.2");
	clearScreen();
	ft_printf("a stack:\n");
	for (int i = 0; i < a_stack->amount; i++) {
		ft_printf("[%d]: %d\n", i, a_stack->values[i]);
	}
	ft_printf("b stack:\n");
	for (int j = 0; j < b_stack->amount; j++) {
		ft_printf("[%d]: %d\n", j, b_stack->values[j]);
	}
	ft_printf("\n%s:\na_stack:", command);
	while (a < a_stack->amount)
	{
		val = ft_abs(a_stack->values[a]);
	//	ft_printf("Visualizer val: %d\n", val);
		ft_printf(RESET"\n[%d]:\t"BLUE, a);
		ft_printf(" %d", val);
		while (val--)
			ft_putstr("-");
		a++;
	}
	ft_putstr(RESET"\n\nb_stack:\n");
	while (b < b_stack->amount)
	{
		val = ft_abs(b_stack->values[b]);
		// ft_printf("Visualizer val: %d\n", val);
		ft_printf(RESET"[%d]:\t"BLUE, b);
		// ft_printf(" %d", val);
		while (val--)
			ft_putstr("-");
		b++;
		ft_putstr("\n");
	}
	ft_putstr(RESET"\n");
}

void	clearScreen(void)
{
	const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
 	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 10);
}
