/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:39:40 by osalmine          #+#    #+#             */
/*   Updated: 2020/03/02 15:51:23 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_lstrev(t_list **list)
{
	t_list *cur;
	t_list *next;
	t_list *prev;

	prev = NULL;
	cur = *list;
	while (cur != NULL && ft_strlen((char*)cur->content) < 4)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*list = prev;
}

int		check_dups(t_ps *stack)
{
	int i;
	int j;

	i = 0;
	while (i < stack->amount)
	{
		j = i + 1;
		while (j < stack->amount)
		{
			if (stack->values[i] == stack->values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_list	*print_cmds(t_list *cmds)
{
	t_list *head;

	head = cmds;
	while (cmds && ft_strlen((char*)cmds->content) < 4)
	{
		if ((char*)cmds->content != NULL)
			ft_printf("%s\n", (char*)cmds->content);
		cmds = cmds->next;
	}
	return (head);
}

int		find_in_stack(int *arr, int amount, int value)
{
	int i;

	i = 0;
	while (i < amount)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
