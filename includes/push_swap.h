/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:15:39 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/27 15:05:39 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct	s_ps
{
	int *values;
	int	amount;
}				t_ps;

t_ps	*parse(int ac, char **av);
void	ft_exit(char *str);
void	free_strsplit(char ***str);

#endif
