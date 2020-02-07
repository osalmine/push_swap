/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:15:39 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/07 18:46:12 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0

/*
**	Struct:
**	Values holds all of the numbers in the stack
**	Amount is the current amount of numbers in the a_stack
**	Size is the allocated size of the a_stack
**	Smallest is the smallest checked number in the stack
**	Largest is the same as smallest but largest
**	Print can be set to TRUE (=1) so the command executed is printed
*/

typedef struct	s_ps
{
	int *values;
	int	amount;
	int size;
	int smallest;
	int largest;
	int print;
}				t_ps;

t_ps			*parse(int ac, char **av);
void			ft_exit(char *str);
void			free_strsplit(char ***str);
void			do_command(t_ps *a_stack, t_ps *b_stack, char *str);
t_ps			*b_init(t_ps *a_stack);
void			sa(t_ps *a_stack);
void			sb(t_ps *b_stack);
void			ss(t_ps *a_stack, t_ps *b_stack);
void			pa(t_ps *a_stack, t_ps *b_stack);
void			pb(t_ps *a_stack, t_ps *b_stack);
void			ra(t_ps *a_stack);
void			rb(t_ps *b_stack);
void			rr(t_ps *a_stack, t_ps *b_stack);
void			push_up(t_ps *stack);
void			push_down(t_ps *stack);
void			rra(t_ps *a_stack);
void			rra_push_down(t_ps *stack);
void			rrb(t_ps *b_stack);
void			rrr(t_ps *a_stack, t_ps *b_stack);
int				median(t_ps *stack, int no_limit);
int				is_in_order(t_ps stack, int check_size);
void			free_struct(t_ps *stack);
void			ft_small_big(t_ps *stack);
void			solve(t_ps *a_stack, t_ps *b_stack);
void			solve_3(t_ps *a_stack);
int				ft_split(t_ps *a_stack, t_ps *b_stack, int med, t_ps *ref);
int				find_in_stack(t_ps *stack, int value);
void			ft_insert(t_ps *a_stack, t_ps *b_stack, t_ps *ref, int limit);
t_ps			*ref_stack(t_ps *a_stack);
int				check_with_ref(t_ps *ref, t_ps *stack);
int				next_in_order(t_ps *ref, t_ps *stack);
int				nbs_under_med(t_ps *stack, int med);
int				b_next_int_order(t_ps *ref, t_ps* a_stack, t_ps *b_stack);
int				amount_in_order(t_ps *ref, t_ps *stack);
void			next_nb_under_med(t_ps *ref, t_ps *a_stack, t_ps *b_stack,
				int med);
void			fast_rotate(t_ps *stack, int pos);

#endif
