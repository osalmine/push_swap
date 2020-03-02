/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:36:12 by osalmine          #+#    #+#             */
/*   Updated: 2020/03/02 11:26:47 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exit(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	ft_usage(void)
{
	ft_exit("Usage:\n\
Push swap solves the numbers given to it as an argument and outputs the \
commands it used to solve the numbers in the stacks:\n\
./push_swap 5 1 3 4 2\n\n\
You can pipe the push_swap to checker, that checks if the stacks can be sorted \
using these commands:\n\
./push_swap 5 1 3 4 2 | ./checker 5 1 3 4 2\n\n\
If checker says \"OK\", the commads were right, if checker says \"KO\", the \
commands weren't right.\n\
Options for checker:\n\
\t-v : Visualize the stacks while they are sorted\n\
\t-n : Output the number of operations");
}
