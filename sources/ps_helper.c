/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:09:16 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/12 15:27:53 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		nbs_under_med(t_ps *stack, int med)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < stack->amount)
	{
		if (stack->values[i] <= med)
			count++;
		i++;
	}
	return (count);
}

void		ft_small_big(t_ps *stack)
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
		// ft_printf("sorted_max: %d\n", stack->sorted_max);
	}
}

void	next_nb_under_med(t_ps *ref, t_ps *a_stack, t_ps *b_stack, int med)
{
	int top;
	int bottom;
	int i;

	top = 0;
	// ft_printf(UNDERLINE RED"\n\nNEXT NB UNDER MEDIAN\n\n"RESET);
	// ft_printf("a stack:\n");
	// for (int i = 0; i < a_stack->amount; i++) {
	// 	ft_printf("[%d]: %d\n", i, a_stack->values[i]);
	// }
	// ft_printf("b stack:\n");
	// for (int j = 0; j < b_stack->amount; j++) {
	// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
	// }
	bottom = a_stack->amount - 1;
	// ft_printf("Median is %d\n", med);
	// ft_printf("Bottom start pos: %d\n", bottom);
	// ft_printf("Amount of numbers currently sorted: %d\n", a_stack->sorted_amount);
	while (top <= a_stack->amount / 2)
	{
		// ft_printf("CURRENT TOP (%d) VALUE INSPECTED: %d\n", top, a_stack->values[top]);
		// ft_printf("%s and %s\n", a_stack->values[top] <= med ? "top val is under med" : "top val isn't under med", find_in_stack(a_stack->sorted, a_stack->sorted_amount, a_stack->values[top]) == -1 ? "Find in stack didn't find inspected val in sorted arr" : "Find in stack found the inspected val in the sorted arr");
		if (a_stack->values[top] <= med && find_in_stack(a_stack->sorted, a_stack->sorted_amount, a_stack->values[top]) == -1)
		{
			// ft_printf(CYAN"Top found top most number under median : %d in index %d\n"RESET, a_stack->values[top], top);
			break ;
		}
		top++;
	}
	while (bottom > a_stack->amount / 2)
	{
		// ft_printf("CURRENT BOT (%d) VALUE INSPECTED: %d\n", bottom, a_stack->values[bottom]);
		if (a_stack->values[bottom] <= med && find_in_stack(a_stack->sorted, a_stack->sorted_amount, a_stack->values[bottom]) == -1)
		{
			// ft_printf(CYAN"Bottom found bottom most number under median : %d in index %d\n"RESET, a_stack->values[bottom], bottom);
			break ;
		}
		bottom--;
	}
	// ft_printf("Bottom: %d\n", bottom);
	if (bottom <= 0)
		return ;
	// ft_printf("Top first found nb at index:\t%d\n", top);
	// ft_printf("Bottom first found nb at index:\t%d\n", bottom);
	i = (a_stack->amount - bottom) < top ? bottom : top;
	// ft_printf("next nb under median is in index: %d\n", i);
	fast_rotate(a_stack, i, 'a');
	if ((next_in_order(ref, a_stack) \
		|| a_stack->values[0] == a_stack->smallest)
		&& !is_in_order(*a_stack, 1))
	{
		// ft_printf("printable: %d, %d next nb und med ra\n", a_stack->print, b_stack->print);
		ra(a_stack);
		add_sorted(a_stack, a_stack->values[a_stack->amount - 1]);
	}
	else if (!is_in_order(*a_stack, 1))
	{
		// ft_printf("printable: %d, %d next nb und med pb\n", a_stack->print, b_stack->print);
		pb(a_stack, b_stack);
	}
}

void	b_fast_rot(t_ps *a_stack, t_ps *b_stack)
{
	int top;
	int bottom;
	int i;

	top = 0;
	bottom = b_stack->amount - 1;
	// ft_printf("b stack smallest : %d, largest : %d\n", b_stack->smallest, b_stack->largest);
	// ft_printf("a stack:\n");
	// for (int a = 0; a < a_stack->amount; a++) {
	// 	ft_printf("[%d]: %d\n", a, a_stack->values[a]);
	// }
	// ft_printf("b stack:\n");
	// for (int j = 0; j < b_stack->amount; j++) {
	// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
	// }
	while (top <= b_stack->amount / 2)
	{
		// ft_printf("CURRENT TOP (%d) VALUE INSPECTED: %d\n", top, b_stack->values[top]);
		if (b_stack->values[top] == b_stack->smallest || b_stack->values[top] == b_stack->largest)
		{
			// ft_printf(CYAN"Top found top most smallest or largest number : %d in index %d\n"RESET, b_stack->values[top], top);
			break ;
		}
		top++;
	}
	while (bottom > b_stack->amount / 2)
	{
		// ft_printf("CURRENT BOT (%d) VALUE INSPECTED: %d\n", bottom, b_stack->values[bottom]);
		if (b_stack->values[bottom] == b_stack->smallest || b_stack->values[bottom] == b_stack->largest)
		{
			// ft_printf(CYAN"Bottom found bottom most smallest or largest number : %d in index %d\n"RESET, b_stack->values[bottom], bottom);
			break ;
		}
		bottom--;
	}
//	ft_printf("Bottom: %d\n", bottom);
	if (bottom <= 0)
		return ;
	i = (b_stack->amount - bottom) < top ? bottom : top;
	fast_rotate(b_stack, i, 'b');
	// ft_printf("printable: %d, %d pa\n", a_stack->print, b_stack->print);
	pa(a_stack, b_stack);
}

void	fast_rotate(t_ps *stack, int pos, char ab)
{
	int nb;
	// char s[1];

	// ft_printf("pos in fast rot: %d\n", pos);
	// ft_printf("stack amount: %d\n", stack->amount);
	if (pos > stack->amount)
		ft_exit("Error: index doesn't exist");
	nb = stack->values[pos];
	// ft_printf("nb in fast rot: %d\n", nb);
	if (stack->amount / 2 < pos)
		while (stack->values[0] != nb)
		{
			// ft_printf("printable: %d rra fast rot\n", stack->print);
			if (ab == 'a')
				rra(stack);
			else
				rrb(stack);
			// ft_printf(RED BOLD "RRAAAAAAAA\n"RESET);
			// read(0, s, 1);
		}
	else
		while (stack->values[0] != nb)
		{
			// ft_printf("printable: %d ra fast rot\n", stack->print);
			if (ab == 'a')
				ra(stack);
			else
				rb(stack);
			// ft_printf(RED BOLD "RAAAAAAAAA\n"RESET);
			// read(0, s, 1);
		}
}
