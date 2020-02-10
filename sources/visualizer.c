/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:43:17 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/10 14:29:32 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	visual(t_ps *a_stack, t_ps *b_stack, char *command)
{
	int a;
	int b;
	int val;

	a = 0;
	b = 0;
	system("sleep 0.05");
	clearScreen();
	ft_printf("\n%s:\n\na_stack:", command);
	while (a < a_stack->amount)
	{
		val = ft_abs(a_stack->values[a]);
	//	ft_printf("Visualizer val: %d\n", val);
		ft_printf("\n[%d]:\t", a);
		while (val--)
			ft_printf(BLUE"-"RESET);
		a++;
	}
	ft_printf("\n\nb_stack:\n");
	while (b < b_stack->amount)
	{
		val = ft_abs(b_stack->values[b]);
		// ft_printf("Visualizer val: %d\n", val);
		ft_printf("[%d]:\t", b);
		while (val--)
			ft_printf(BLUE"-"RESET);
		b++;
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	clearScreen(void)
{
	const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
 	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 10);
}
