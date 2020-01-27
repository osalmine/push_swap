/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_frees.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:02:52 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/27 16:58:45 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_struct(t_ps *stack)
{
	free(stack->values);
	free(stack);
}

void	free_strsplit(char ***str)
{
	char **curr;

	if (str && *str)
	{
		curr = (*str);
		while (*curr)
			free(*(curr++));
		free(*str);
		str = NULL;
	}
}