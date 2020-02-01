/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:15:39 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/01 16:18:06 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct	s_ps
{
	int *values;
	int	amount;
	int size;
}				t_ps;

t_ps	*parse(int ac, char **av);
void	ft_exit(char *str);
void	free_strsplit(char ***str);
void	do_command(t_ps *a_stack, t_ps *b_stack, char *str);
t_ps	*b_init(t_ps *a_stack);
void	sa(t_ps *a_stack);
void	sb(t_ps *b_stack);
void	ss(t_ps *a_stack, t_ps *b_stack);
void	pa(t_ps *a_stack, t_ps *b_stack);
void	pb(t_ps *a_stack, t_ps *b_stack);
void	ra(t_ps *a_stack);
void	rb(t_ps *b_stack);
void	rr(t_ps *a_stack, t_ps *b_stack);
void	push_up(t_ps *stack);
void	push_down(t_ps *stack);
void	rra(t_ps *a_stack);
void	rrb(t_ps *b_stack);
void	rrr(t_ps *a_stack, t_ps *b_stack);
int 	median(t_ps stack);

#endif
