/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:09:16 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/25 13:00:40 by osalmine         ###   ########.fr       */
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

// void	opt_rot(t_ps *a_stack, t_ps *b_stack, int *optimal)
// {
//
// }

t_list	*combine_cmds(t_list *cmds)
{
	t_list *ptr;
	t_list *prev;
	t_list *head;

	ft_lstrev(&cmds);
	head = cmds;
	while (cmds->next)
	{
		prev = cmds;
		cmds = cmds->next;
		// ft_printf("Ok ");
		// ft_printf("%s\n", (char*)(cmds->content));
		if (ft_strequ((char*)(cmds->content), "ra"))
		{
			ptr = cmds;
			while (ptr && ft_strequ(ptr->content, "ra"))
				ptr = ptr->next;
			if (ptr && !ft_strequ(ptr->content, "ra") && ft_strequ(ptr->content, "rb"))
			{
				free((char*)(ptr->content));
				ptr->content = ft_strdup("rr");
				free((char*)(prev->next->content));
				free(prev->next);
				prev->next = cmds->next;
			}
		}
		else if (ft_strequ((char*)(cmds->content), "rb"))
		{
			ptr = cmds;
			while (ptr && ft_strequ(ptr->content, "rb"))
				ptr = ptr->next;
			if (ptr && !ft_strequ(ptr->content, "rb") && ft_strequ(ptr->content, "ra"))
			{
				free((char*)(ptr->content));
				ptr->content = ft_strdup("rr");
				free((char*)(prev->next->content));
				free(prev->next);
				prev->next = cmds->next;
			}
		}
		else if (ft_strequ((char*)(cmds->content), "rra"))
		{
			ptr = cmds;
			while (ptr && ft_strequ(ptr->content, "rra"))
				ptr = ptr->next;
			if (ptr && !ft_strequ(ptr->content, "rra") && ft_strequ(ptr->content, "rrb"))
			{
				free((char*)(ptr->content));
				ptr->content = ft_strdup("rrr");
				free((char*)(prev->next->content));
				free(prev->next);
				prev->next = cmds->next;
			}
		}
		else if (ft_strequ((char*)(cmds->content), "rrb"))
		{
			ptr = cmds;
			while (ptr && ft_strequ(ptr->content, "rrb"))
				ptr = ptr->next;
			if (ptr && !ft_strequ(ptr->content, "rrb") && ft_strequ(ptr->content, "rra"))
			{
				free((char*)(ptr->content));
				ptr->content = ft_strdup("rrr");
				free((char*)(prev->next->content));
				free(prev->next);
				prev->next = cmds->next;
			}
		}
	}
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
	ind[1] = next_spot(a_stack, b_stack->values[0], 'n');
	if (b_stack->amount == 1)
		return(ind);
	opt_moves = moves_to_top(b_stack, b_stack->values[0]) + next_spot(a_stack, b_stack->values[0], 'm');
	// ft_printf(BLUE"\nSTARTING OPT_MOVES: %d\n"RESET, opt_moves);
	i = 1;
	while (i < b_stack->amount)
	{
		cur_moves = moves_to_top(b_stack, b_stack->values[i]) + next_spot(a_stack, b_stack->values[i], 'm');
		// ft_printf(RED"Moves for %d are %d\n"RESET, b_stack->values[i], cur_moves);
		if (opt_moves > cur_moves)
		{
			// ft_printf(BLUE"Opt_moves : %d is more then cur_moves: %d\n"RESET, opt_moves, cur_moves);
			ind[0] = i;
			ind[1] = next_spot(a_stack, b_stack->values[i], 'n');
			opt_moves = cur_moves;
		}
		i++;
	}
	return(ind);
}

int		moves_to_top(t_ps *stack, int nb)
{
	int moves;

	moves = find_in_stack(stack->values, stack->amount, nb);
	// ft_printf("\nMOVE TO TOP:\n");
	// ft_printf("%d is in b_stack at index %d (= moves)\n", nb, moves);
	moves = (stack->amount / 2) < moves ? (stack->amount - moves) : moves;
	// ft_printf("b_stack rot amount: %d\n", moves);
	return (moves);
}

int		next_spot(t_ps *stack, int nb, char move)
{
	int top;
	int bottom;
	int moves;

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
	bottom = stack->amount - 1;
	while (top <= stack->amount / 2)
	{
		// ft_printf("CURRENT TOP (%d) VALUE INSPECTED: %d\n", top, stack->values[top]);
		// ft_printf("%s and %s\n", a_stack->values[top] <= med ? "top val is under med" : "top val isn't under med", find_in_stack(a_stack->sorted, a_stack->sorted_amount, a_stack->values[top]) == -1 ? "Find in stack didn't find inspected val in sorted arr" : "Find in stack found the inspected val in the sorted arr");
		if (top == 0 && stack->values[top] > nb && stack->values[stack->amount - 1] < nb)
		{
			// ft_printf("Stack values[%d] : %d > %d && stack values at the bottom: %d < %d\n", top, stack->values[top], nb, stack->values[stack->amount - 1], nb);
			// ft_printf("Top preference: %d\n", top);
			break ;
		}
		else if (stack->values[top] < nb && stack->values[top + 1] > nb)
		{
			// ft_printf("Stack values[%d] : %d < %d && stack->values[%d + 1] : %d > %d\n", top, stack->values[top], nb, top, stack->values[top + 1], nb);
			top++;
			// ft_printf("Top preference: %d\n", top);
			break ;
		}
		top++;
	}
	while (bottom >= stack->amount / 2)
	{
		// ft_printf("CURRENT BOT (%d) VALUE INSPECTED: %d\n", bottom, stack->values[bottom]);
		if (bottom == stack->amount - 1 && stack->values[bottom] < nb && stack->values[0] > nb)
		{
			// ft_printf("Stack values[%d] : %d < %d && stack values at the top: %d > %d\n", bottom, stack->values[bottom], nb, stack->values[0], nb);
			// ft_printf("Bottom preference: %d\n", bottom);
			break ;
		}
		if (stack->values[bottom] > nb && stack->values[bottom - 1] < nb)
		{
			// ft_printf("Stack values[%d] : %d > %d && stack values[%d - 1]: %d < %d\n", bottom, stack->values[bottom], nb, bottom, stack->values[bottom - 1], nb);
			// ft_printf("Bottom preference: %d\n", bottom);
			break ;
		}
		bottom--;
	}
	// ft_printf("Bottom: %d\n", bottom);


	if (bottom < 0)
		return (-1);
	// ft_printf("Top first found nb at index:\t%d\n", top);
	// ft_printf("Bottom first found nb at index:\t%d\n", bottom);
	if (move == 'm')
		moves = (stack->amount - bottom) < top ? (stack->amount - bottom) + 1 : top;
	moves = (stack->amount - bottom) < top ? bottom : top;
	// ft_printf("\nNEXT SPOT\nmoves: %d with nb being: %d\n", moves, nb);
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
