/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:15:39 by osalmine          #+#    #+#             */
/*   Updated: 2020/03/02 16:08:49 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0

/*
**	Struct:
**	- Values holds all of the numbers in the stack
**	- Amount is the current amount of numbers in the a_stack
**	- Size is the allocated size of the a_stack
**	- Smallest is the smallest checked number in the stack
**	- Largest is the same as smallest but largest
**	- Print can be set to TRUE (=1) so the command executed is printed.
**	- If visual is TRUE, visual mode for checker is triggered
**	- Sorted array has the list of sorted numbers in it
**	- Sorted amount is the nuber of sorted numbers
*/

typedef struct	s_ps
{
	int *values;
	int	amount;
	int size;
	int smallest;
	int largest;
	int print;

	int visual;
	int cmd_nb;

	int *sorted;
	int sorted_amount;
	int sorted_max;
}				t_ps;

t_ps			*parse(int ac, char **av);
void			ft_exit(char *str);
void			ft_usage(void);
void			free_strsplit(char ***str);
void			do_command(t_ps *a_stack, t_ps *b_stack, char *str);
t_ps			*b_init(t_ps *a_stack);

/*
**	Mover functions and their helper functions
*/

t_list			*sa(t_ps *a_stack, t_list *cmds);
t_list			*sb(t_ps *b_stack, t_list *cmds);
t_list			*ss(t_ps *a_stack, t_ps *b_stack, t_list *cmds);
t_list			*pa(t_ps *a_stack, t_ps *b_stack, t_list *cmds);
t_list			*pb(t_ps *a_stack, t_ps *b_stack, t_list *cmds);
t_list			*ra(t_ps *a_stack, t_list *cmds);
t_list			*rb(t_ps *b_stack, t_list *cmds);
t_list			*rr(t_ps *a_stack, t_ps *b_stack, t_list *cmds);
t_list			*rra(t_ps *a_stack, t_list *cmds);
t_list			*rrb(t_ps *b_stack, t_list *cmds);
t_list			*rrr(t_ps *a_stack, t_ps *b_stack, t_list *cmds);
void			push_up(t_ps *stack);
void			push_down(t_ps *stack);
void			rra_push_down(t_ps *stack);

int				median(t_ps *stack, int no_limit);
int				is_in_order(t_ps stack, int check_size);
void			free_struct(t_ps *stack);
void			ft_small_big(t_ps *stack);
t_list			*solve(t_ps *a_stack, t_ps *b_stack);
t_list			*solve_3(t_ps *a_stack, t_list *cmds);
t_list			*solve_small(t_ps *a_stack, t_ps *b_stack, t_list *cmds);
t_list			*ft_split(t_ps *a_stack, t_ps *b_stack, t_list *cmds);
t_list			*ft_insert(t_ps *a_stack, t_ps *b_stack, t_list *cmds);
int				find_in_stack(int *arr, int amount, int value);
t_ps			*ref_stack(t_ps *a_stack);
int				amount_in_order(t_ps *ref, t_ps *stack);
t_list			*fast_rotate_bot(t_ps *stack, int pos, char ab, t_list *cmds);
t_list			*fast_rotate_top(t_ps *stack, int pos, char ab, t_list *cmds);
void			visual(t_ps *a_stack, t_ps *b_stack, t_list *cmds);

int				*prefer_index_b(t_ps *a_stack, t_ps *b_stack);
int				moves_to_top(t_ps *stack, int nb);
int				next_spot(t_ps *a_stack, t_ps *b_stack, int nb, char moves);
t_list			*print_cmds(t_list *cmds);
t_list			*free_lst(t_list *lst);
void			ft_lstrev(t_list **list);
t_list			*combine_cmds(t_list *cmds);
int				opt_rot(int a_moves, int b_moves);
int				check_dups(t_ps *stack);
void			swap(int *a, int *b);

#endif
