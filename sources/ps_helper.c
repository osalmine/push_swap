/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:09:16 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/28 18:42:49 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int		nbs_under_med(t_ps *stack, int med)
// {
// 	int i;
// 	int count;
//
// 	i = 0;
// 	count = 0;
// 	while (i < stack->amount)
// 	{
// 		if (stack->values[i] <= med)
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

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
	}
}

t_list	*combine_cmds(t_list *cmds)
{
	t_list *ptr;
	t_list *prev;
	t_list *head;

	ft_lstrev(&cmds);
	head = cmds;
	ft_printf("Combining commands\nCurrent command list:\n");
	print_cmds(cmds);
	ft_printf("Starting to combine\n");
	while (cmds->next)
	{
		prev = cmds;
		cmds = cmds->next;
		while (cmds && ft_strequ((char*)(cmds->content), "ra"))
		{
			ptr = cmds;
			while (ptr && (ft_strequ(ptr->content, "ra") || ft_strequ(ptr->content, "rr")))
			{
				ft_printf("IN RA WHILE: ptr: %s\n", ptr->content);
				ptr = ptr->next;
			}
			ft_printf("Next is: %s\n", ptr->content);
			if (ptr && !ft_strequ(ptr->content, "ra") && !ft_strequ(ptr->content, "rr") && ft_strequ(ptr->content, "rb"))
			{
				free((char*)(ptr->content));
				ptr->content = ft_strdup("rr");
				prev = cmds->next;
				free((char*)(cmds->content));
				free(cmds);
				cmds = prev;
			}
			else
				break ;
		}
 		while (cmds && ft_strequ((char*)(cmds->content), "rb"))
		{
			ft_printf("Cmds: %s\n", cmds->content);
			ptr = cmds;
			while (ptr && (ft_strequ(ptr->content, "rb") || ft_strequ(ptr->content, "rr")))
			{
				ft_printf("IN RB WHILE: ptr: %s\n", ptr->content);
				ptr = ptr->next;
			}
			ft_printf("Next is: %s\n", ptr->content);
			if (ptr && !ft_strequ(ptr->content, "rb") && !ft_strequ(ptr->content, "rr") && ft_strequ(ptr->content, "ra"))
			{
				ft_printf("Freeing ptr cont: %s\n", ptr->content);
				free((char*)(ptr->content));
				ptr->content = ft_strdup("rr");
				prev = cmds->next;
				ft_printf("Changed ptr cont to: %s\n", ptr->content);
				ft_printf("prev->content: %s\n", prev->content);
				ft_printf("cmds->content: %s, cmds->next->content: %s\n", cmds->content, cmds->next->content);
				ft_printf("Freeing cmds->content: %s\n", cmds->content);
				free((char*)(cmds->content));
				free(cmds);
				ft_printf("Freed cmds\n");
				cmds = prev;
				ft_printf("Cmds cont after frees: %s\n", cmds->content);
			}
			else
				break ;
		}
		while (cmds && ft_strequ((char*)(cmds->content), "rra"))
		{
			ft_printf("RRA: cmds->content: %s\n", cmds->content);
			ptr = cmds;
			while (ptr->next && (ft_strequ(ptr->content, "rra") || ft_strequ(ptr->content, "rrr")))
			{
				ft_printf("IN RRA WHILE: ptr: %s\n", ptr->content);
				ptr = ptr->next;
			}
			ft_printf("Next is: %s\n", ptr->content);
			if (ptr && !ft_strequ(ptr->content, "rra") && !ft_strequ(ptr->content, "rrr") && ft_strequ(ptr->content, "rrb"))
			{
				free((char*)(ptr->content));
				ptr->content = ft_strdup("rrr");
				prev = cmds->next;
				free((char*)(cmds->content));
				free(cmds);
				cmds = prev;
			}
			else
				break ;
		}
		while (cmds && ft_strequ((char*)(cmds->content), "rrb"))
		{
			ptr = cmds;
			while (ptr && (ft_strequ(ptr->content, "rrb") || ft_strequ(ptr->content, "rrr")))
			{
				ft_printf("IN RRB WHILE: ptr: %s\n", ptr->content);
				ptr = ptr->next;
			}
			ft_printf("Next is: %s\n", ptr->content);
			if (ptr && !ft_strequ(ptr->content, "rrb") && !ft_strequ(ptr->content, "rrr") && ft_strequ(ptr->content, "rra"))
			{
				free((char*)(ptr->content));
				ptr->content = ft_strdup("rrr");
				prev = cmds->next;
				free((char*)(cmds->content));
				free(cmds);
				cmds = prev;
			}
			else
				break ;
		}
	}
	ft_printf(RED"\n\nCOMBINE IS DONE, CURRENT LIST:\n\n"RESET);
	print_cmds(cmds);
	return (head);
}

int		*prefer_index_b(t_ps *a_stack, t_ps *b_stack)
{
	int *ind;
	int	opt_moves;
	int	cur_moves;
	int	i;

	if (!(ind = (int*)malloc(sizeof(int) * 2)))
		ft_exit("Error");
	ind[0] = 0;
	ind[1] = ft_abs(next_spot(a_stack, b_stack, b_stack->values[0], 'n'));
	if (b_stack->amount == 1)
		return(ind);
	i = 0;
	opt_moves = ft_abs(moves_to_top(b_stack, b_stack->values[0])) + ft_abs(next_spot(a_stack, b_stack, b_stack->values[0], 'm'));
	// ft_printf(GREEN"opt_moves before counting optimal rotation: %d\n"RESET, opt_moves);
	// ft_printf(BLUE"OPTIMAL ROTATION: %d\n"RESET, opt_rot(next_spot(a_stack, b_stack, b_stack->values[i], 'm'), moves_to_top(b_stack, b_stack->values[i])));
	opt_moves -= opt_rot(next_spot(a_stack, b_stack, b_stack->values[i], 'm'), moves_to_top(b_stack, b_stack->values[i]));
	// ft_printf(GREEN"opt_moves after counting optimal rotation: %d\n"RESET, opt_moves);
	// ft_printf(BLUE"\nSTARTING OPT_MOVES: %d\n"RESET, opt_moves);
	i = 1;
	while (i < b_stack->amount)
	{
		// ft_printf(YELLOW"\nNEW ROUND\n\n"RESET);
		cur_moves = ft_abs(moves_to_top(b_stack, b_stack->values[i])) + ft_abs(next_spot(a_stack, b_stack, b_stack->values[i], 'm'));
		// ft_printf(GREEN"cur_moves before counting optimal rotation: %d\n"RESET, cur_moves);
		// ft_printf(BLUE"OPTIMAL ROTATION: %d\n"RESET, opt_rot(next_spot(a_stack, b_stack, b_stack->values[i], 'm'), moves_to_top(b_stack, b_stack->values[i])));
		if (opt_rot(next_spot(a_stack, b_stack, b_stack->values[i], 'm'), moves_to_top(b_stack, b_stack->values[i])) != 0)
			cur_moves = opt_rot(next_spot(a_stack, b_stack, b_stack->values[i], 'm'), moves_to_top(b_stack, b_stack->values[i]));
		// ft_printf(GREEN"cur_moves after counting optimal rotation: %d\n"RESET, cur_moves);
		// ft_printf(RED"Moves for %d are %d\n"RESET, b_stack->values[i], cur_moves);
		if (opt_moves > cur_moves)
		{
			// ft_printf(BLUE"Opt_moves : %d is more then cur_moves: %d\n"RESET, opt_moves, cur_moves);
			ind[0] = i;
			ind[1] = next_spot(a_stack, b_stack, b_stack->values[i], 'n');
			opt_moves = cur_moves;
		}
		i++;
	}
	return(ind);
}

int		opt_rot(int a_moves, int b_moves)
{
	// ft_printf(RED"\nIN OPTIMAL ROT:\nif a is neg, rra else ra: a: %d\nif b is neg, rrb else rb: %d\nIf they aren't the same type, nothing is done\n\n"RESET, a_moves, b_moves);
	if ((a_moves < 0 && b_moves < 0) || (a_moves > 0 && b_moves > 0))
	{
		if (ft_abs(a_moves) > ft_abs(b_moves))
		{
			// ft_printf("A (%d) > B (%d), so combined moves substracted from current moves is: a - b = %d\n", ft_abs(a_moves), ft_abs(b_moves), (ft_abs(a_moves)) - (ft_abs(b_moves)));
			return (ft_abs(a_moves));
		}
		else
		{
			// ft_printf("B (%d) > A (%d), so combined moves substracted from current moves is: b - a = %d\n", ft_abs(b_moves), ft_abs(a_moves), ft_abs(b_moves) - ft_abs(a_moves));
			return (ft_abs(b_moves));
		}
	}
	return (0);
}

int		moves_to_top(t_ps *stack, int nb)
{
	int moves;

	moves = find_in_stack(stack->values, stack->amount, nb);
	// ft_printf("\nMOVE TO B TOP:\n");
	// ft_printf("%d is in b_stack at index %d (= moves)\n", nb, moves);
	moves = (stack->amount / 2) < moves ? -(stack->amount - moves) : moves;
	// ft_printf(GREEN"b_stack rot amount to get nb %d to top: %d\n"RESET, nb, moves);
	return (moves);
}

int		next_spot(t_ps *a_stack, t_ps *b_stack, int nb, char move)
{
	int top;
	int bottom;
	int moves;

	top = 0;
	bottom = a_stack->amount - 1;
	while (top <= a_stack->amount / 2)
	{
		// ft_printf("CURRENT TOP (%d) VALUE INSPECTED IN A: %d\n", top, a_stack->values[top]);
		if (top == 0 && a_stack->values[top] > nb && a_stack->values[a_stack->amount - 1] < nb)
		{
			// ft_printf("Stack values[%d] : %d > %d && stack values at the bottom: %d < %d\n", top, a_stack->values[top], nb, a_stack->values[a_stack->amount - 1], nb);
			// ft_printf("Top preference: %d\n", top);
			break ;
		}
		else if (a_stack->values[top] < nb && a_stack->values[top + 1] > nb)
		{
			// ft_printf("Stack values[%d] : %d < %d && stack->values[%d + 1] : %d > %d\n", top, a_stack->values[top], nb, top, a_stack->values[top + 1], nb);
			top++;
			// ft_printf("Top preference: %d\n", top);
			break ;
		}
		top++;
	}
	while (bottom >= a_stack->amount / 2)
	{
		// ft_printf("CURRENT BOT (%d) VALUE INSPECTED IN A: %d\n", bottom, a_stack->values[bottom]);
		if (bottom == a_stack->amount - 1 && a_stack->values[bottom] < nb && a_stack->values[0] > nb)
		{
			// ft_printf("Stack values[%d] : %d < %d && stack values at the top: %d > %d\n", bottom, a_stack->values[bottom], nb, a_stack->values[0], nb);
			// ft_printf("Bottom preference: %d\n", bottom);
			break ;
		}
		if (a_stack->values[bottom] > nb && a_stack->values[bottom - 1] < nb)
		{
			// ft_printf("Stack values[%d] : %d > %d && stack values[%d - 1]: %d < %d\n", bottom, a_stack->values[bottom], nb, bottom, a_stack->values[bottom - 1], nb);
			// ft_printf("Bottom preference: %d\n", bottom);
			break ;
		}
		bottom--;
	}
	b_stack->values = b_stack->values;
	// if (bottom < 0)
	// 	return (-1);
	// ft_printf("Top first found nb at index:\t%d\n", top);
	// ft_printf("Bottom first found nb at index:\t%d\n", bottom);
	if (move == 'm')
	{
		// ft_printf("Move is true, calculating if rra is faster then ra\n");
		// (a_stack->amount - bottom) < top ? ft_printf("It is faster to rra\n") : ft_printf("It is faster to ra\n");
		moves = (a_stack->amount - bottom) < top ? -(a_stack->amount - bottom) : top;
		// (a_stack->amount - bottom) < top ? ft_printf("Moves to a stack top: a_stack->amount (%d) - bottom (%d) = %d -> negative\n", a_stack->amount, bottom, a_stack->amount - bottom) : ft_printf("Moves to a stack top: %d\n", moves);
	}
	else
		moves = (a_stack->amount - bottom) < top ? bottom : top;
	// ft_printf(GREEN"\nNEXT SPOT IN A STACK\nmoves: %d with nb being: %d\n"RESET, ft_abs(moves), nb);
	return (moves);
}

// void	next_nb_under_med(t_ps *ref, t_ps *a_stack, t_ps *b_stack, int med)
// {
// 	int top;
// 	int bottom;
// 	int i;
//
// 	top = 0;
// 	// ft_printf(UNDERLINE RED"\n\nNEXT NB UNDER MEDIAN\n\n"RESET);
// 	// ft_printf("a stack:\n");
// 	// for (int i = 0; i < a_stack->amount; i++) {
// 	// 	ft_printf("[%d]: %d\n", i, a_stack->values[i]);
// 	// }
// 	// ft_printf("b stack:\n");
// 	// for (int j = 0; j < b_stack->amount; j++) {
// 	// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
// 	// }
// 	bottom = a_stack->amount - 1;
// 	// ft_printf("Median is %d\n", med);
// 	// ft_printf("Bottom start pos: %d\n", bottom);
// 	// ft_printf("Amount of numbers currently sorted: %d\n", a_stack->sorted_amount);
// 	while (top < a_stack->amount / 2)
// 	{
// 		// ft_printf("CURRENT TOP (%d) VALUE INSPECTED: %d\n", top, a_stack->values[top]);
// 		// ft_printf("%s and %s\n", a_stack->values[top] <= med ? "top val is under med" : "top val isn't under med", find_in_stack(a_stack->sorted, a_stack->sorted_amount, a_stack->values[top]) == -1 ? "Find in stack didn't find inspected val in sorted arr" : "Find in stack found the inspected val in the sorted arr");
// 		if (a_stack->values[top] <= med && find_in_stack(a_stack->sorted, a_stack->sorted_amount, a_stack->values[top]) == -1)
// 		{
// 			// ft_printf(CYAN"Top found top most number under median : %d in index %d\n"RESET, a_stack->values[top], top);
// 			break ;
// 		}
// 		top++;
// 	}
// 	while (bottom > a_stack->amount / 2)
// 	{
// 		// ft_printf("CURRENT BOT (%d) VALUE INSPECTED: %d\n", bottom, a_stack->values[bottom]);
// 		if (a_stack->values[bottom] <= med && find_in_stack(a_stack->sorted, a_stack->sorted_amount, a_stack->values[bottom]) == -1)
// 		{
// 			// ft_printf(CYAN"Bottom found bottom most number under median : %d in index %d\n"RESET, a_stack->values[bottom], bottom);
// 			break ;
// 		}
// 		bottom--;
// 	}
// 	// ft_printf("Bottom: %d\n", bottom);
//
//
// 	if (bottom < 0 || (find_in_stack(a_stack->sorted, a_stack->sorted_amount, a_stack->values[bottom]) > 1 && find_in_stack(a_stack->sorted, a_stack->sorted_amount, a_stack->values[top]) > -1))
// 		return ;
// 	// ft_printf("Top first found nb at index:\t%d\n", top);
// 	// ft_printf("Bottom first found nb at index:\t%d\n", bottom);
// 	i = (a_stack->amount - bottom) < top ? bottom : top;
// 	// ft_printf("next nb under median is in index: %d\n", i);
// 	fast_rotate(a_stack, i, 'a', 't');
// 	if ((next_in_order(ref, a_stack) \
// 		|| a_stack->values[0] == a_stack->smallest)
// 		&& !is_in_order(*a_stack, 1))
// 	{
// 		// ft_printf("printable: %d, %d next nb und med ra\n", a_stack->print, b_stack->print);
// 		ra(a_stack);
// 		add_sorted(a_stack, a_stack->values[a_stack->amount - 1]);
// 	}
// 	else if (!is_in_order(*a_stack, 1))
// 	{
// 		// ft_printf("printable: %d, %d next nb und med pb\n", a_stack->print, b_stack->print);
// 		pb(a_stack, b_stack);
// 	}
// }
//
// void	b_fast_rot(t_ps *a_stack, t_ps *b_stack)
// {
// 	int top;
// 	int bottom;
// 	int i;
//
// 	top = 0;
// 	bottom = b_stack->amount - 1;
// 	// ft_printf("b stack smallest : %d, largest : %d\n", b_stack->smallest, b_stack->largest);
// 	// ft_printf("a stack:\n");
// 	// for (int a = 0; a < a_stack->amount; a++) {
// 	// 	ft_printf("[%d]: %d\n", a, a_stack->values[a]);
// 	// }
// 	// ft_printf("b stack:\n");
// 	// for (int j = 0; j < b_stack->amount; j++) {
// 	// 	ft_printf("[%d]: %d\n", j, b_stack->values[j]);
// 	// }
// 	while (top <= b_stack->amount / 2)
// 	{
// 		// ft_printf("CURRENT TOP (%d) VALUE INSPECTED: %d\n", top, b_stack->values[top]);
// 		if (b_stack->values[top] == b_stack->smallest || b_stack->values[top] == b_stack->largest)
// 		{
// 			// ft_printf(CYAN"Top found top most smallest or largest number : %d in index %d\n"RESET, b_stack->values[top], top);
// 			break ;
// 		}
// 		top++;
// 	}
// 	while (bottom > b_stack->amount / 2)
// 	{
// 		// ft_printf("CURRENT BOT (%d) VALUE INSPECTED: %d\n", bottom, b_stack->values[bottom]);
// 		if (b_stack->values[bottom] == b_stack->smallest || b_stack->values[bottom] == b_stack->largest)
// 		{
// 			// ft_printf(CYAN"Bottom found bottom most smallest or largest number : %d in index %d\n"RESET, b_stack->values[bottom], bottom);
// 			break ;
// 		}
// 		bottom--;
// 	}
// //	ft_printf("Bottom: %d\n", bottom);
// 	if (bottom <= 0)
// 		return ;
// 	i = (b_stack->amount - bottom) < top ? bottom : top;
// 	fast_rotate(b_stack, i, 'b', 't');
// 	// ft_printf("printable: %d, %d pa\n", a_stack->print, b_stack->print);
// 	pa(a_stack, b_stack);
// }

t_list	*fast_rotate(t_ps *stack, int pos, char ab, char top_bot, t_list *cmds)
{
	int nb;
	int i;
	// char s[1];

	if (pos > stack->amount)
		ft_exit("Error: index doesn't exist");
	nb = stack->values[pos];
	top_bot == 't' ? (i = 0) : (i = stack->amount - 1);
	if (stack->amount / 2 < pos)
		while (stack->values[i] != nb)
		{
			// ft_printf("printable: %d rra fast rot\n", stack->print);
			if (ab == 'a')
				cmds = rra(stack, cmds);
			else
				cmds = rrb(stack, cmds);
			// ft_printf(RED BOLD "RRAAAAAAAA\n"RESET);
			// read(0, s, 1);
		}
	else
		while (stack->values[i] != nb)
		{
			// ft_printf("printable: %d ra fast rot\n", stack->print);
			if (ab == 'a')
			{
				cmds = ra(stack, cmds);
				// ft_printf(RED BOLD "RAAAAAAAAA\n"RESET);
				// read(0, s, 1);
			}
			else
				cmds = rb(stack, cmds);
			// ft_printf(RED BOLD "RAAAAAAAAA\n"RESET);
			// read(0, s, 1);
		}
	return (cmds);
}
