/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:02:02 by osalmine          #+#    #+#             */
/*   Updated: 2020/03/02 15:50:29 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	quicksort(int *data, int n)
{
	int i;
	int j;
	int v;

	if (n <= 1)
		return ;
	v = data[0];
	i = 0;
	j = n - 1;
	while (1)
	{
		while (data[++i] < v)
			if (i >= n)
				break ;
		while (data[j] > v)
			--j;
		if (i >= j)
			break ;
		swap(&(data[i]), &(data[j]));
	}
	swap(&(data[i - 1]), &(data[0]));
	quicksort(data, i - 1);
	quicksort(data + i, n - i);
}

void		add_sorted(t_ps *stack, int nb)
{
	int i;

	i = 0;
	while (i < stack->sorted_amount)
	{
		if (stack->sorted[i] == nb)
			return ;
		i++;
	}
	i = stack->sorted_amount;
	while (i > 0 && stack->sorted_amount > 0)
	{
		stack->sorted[i] = stack->sorted[i - 1];
		i--;
	}
	stack->sorted[0] = nb;
	stack->sorted_amount++;
	quicksort(stack->sorted, stack->sorted_amount);
	ft_small_big(stack);
}

t_ps		*ref_stack(t_ps *a_stack)
{
	t_ps	*ref;
	int		i;

	ref = b_init(a_stack);
	i = 0;
	while (i < a_stack->amount)
	{
		ref->values[i] = a_stack->values[i];
		ref->amount++;
		i++;
	}
	quicksort(ref->values, ref->amount);
	ft_small_big(ref);
	return (ref);
}

static int	get_limit(int no_limit, t_ps *stack)
{
	int limit;

	limit = 0;
	if (no_limit != 0)
		while (stack->values[limit] != stack->smallest)
			limit++;
	else
		limit = stack->amount;
	return (limit);
}

int			median(t_ps *stack, int no_limit)
{
	int n;
	int *arr;
	int med;
	int limit;

	n = 0;
	limit = get_limit(no_limit, stack);
	if (limit == 2 && stack->values[0] > stack->values[1])
		return (stack->values[0]);
	else if (limit == 2)
		return (stack->values[1]);
	if (!(arr = (int*)malloc(sizeof(int) * stack->amount)))
		ft_exit("Median malloc error");
	while (n < stack->amount && (n < limit || !no_limit))
	{
		arr[n] = stack->values[n];
		n++;
	}
	quicksort(arr, limit);
	n = limit;
	n = (n + 1) / 2 - 1;
	med = arr[n];
	free(arr);
	return (med);
}
