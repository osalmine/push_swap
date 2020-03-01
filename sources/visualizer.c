/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:43:17 by osalmine          #+#    #+#             */
/*   Updated: 2020/03/01 19:59:18 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_biggest_nb(t_ps *stack)
{
	int i;
	int biggest;

	i = 0;
	biggest = stack->values[i];
	while (i < stack->amount)
	{
		if (stack->values[i] > biggest)
			biggest = stack->values[i];
		i++;
	}
	return (biggest);
}

static void	clearScreen(void)
{
	const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
 	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 10);
}

static void	print_a(t_ps *a_stack, int biggest, int a)
{
	int val;

	if (a < a_stack->amount)
	{
		val = ft_abs(a_stack->values[a]);
		biggest -= val + 1;
		ft_printf(RESET"[%d]: \t"BLUE, a_stack->values[a]);
		while (val--)
			ft_putchar('-');
		ft_putstr(RESET"");
		while (biggest-- > 0)
			ft_putchar(' ');
	}
}

static void	print_b(t_ps *a_stack, t_ps *b_stack, int biggest, int b)
{
	int val;

	if (b < b_stack->amount)
	{
		val = ft_abs(b_stack->values[b]);
		biggest += 7;
		if (b >= a_stack->amount)
		{
			while (biggest--)
				ft_putchar(' ');
		}
		ft_printf(RESET"[%d]: \t"BLUE, b_stack->values[b]);
		while (val--)
			ft_putchar('-');
	}
}


void		visual(t_ps *a_stack, t_ps *b_stack, t_list *cmds)
{
	int a;
	int b;
	int biggest;

	biggest = find_biggest_nb(a_stack) + 5;
	if (a_stack->amount > 80)
		ft_exit("Visualizer max amount is 80");
	while (cmds)
	{
		do_command(a_stack, b_stack, cmds->content);
		system("sleep 0.2");
		clearScreen();
		ft_printf(RESET"\n%s:\na_stack:", cmds->content);
		a = biggest;
		while (a--)
			ft_putchar(' ');
		ft_putstr(" b_stack:\n");
		a = 0;
		b = 0;
		while (a < a_stack->amount || b < b_stack->amount)
		{
			print_a(a_stack, biggest, a++);
			print_b(a_stack, b_stack, biggest, b++);
			ft_putchar('\n');
		}
		cmds = cmds->next;
	}
}
