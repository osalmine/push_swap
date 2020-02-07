/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:02:02 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/07 15:58:55 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
}

int			find_in_stack(t_ps *stack, int value)
{
	int i;

	i = 0;
	while (i < stack->amount)
	{
//		ft_printf("stack val at i (%d) is %d and value is %d\n", i, stack->values[i], value);
		if (stack->values[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static void	quicksort(int *data, int n)
{
	int i;
	int j;
	int v;
	int t;

	if (n <= 1)
		return ;
	v = data[0];
	i = 0;
	j = n;
	while (1)
	{
		// for some reason while loops work only if ++i & --j is inside it ??
		while (data[++i] < v && i < n) ;
		while (data[--j] > v) ;
		if (i >= j)
			break ;
		t = data[i];
		data[i] = data[j];
		data[j] = t;
	}
	t = data[i - 1];
	data[i - 1] = data[0];
	data[0] = t;
	quicksort(data, i - 1);
	quicksort(data + i, n - i);
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
	// ft_printf("ref stack:\n");
	// for (int j = 0; j < ref->amount; j++) {
	// 	ft_printf("[%d]: %d\n", j, ref->values[j]);
	// }
	return (ref);
}

int			median(t_ps *stack, int no_limit)
{
	int n;
	int *arr;
	int med;
	int limit;


	n = 0;
	limit = 0;
	// ft_printf("stack from wich median is taken:\n");
	// for (int l = 0; l < stack->amount; l++) {
	// 	ft_printf("[%d]: %d\n", l, stack->values[l]);
	// }
	if (no_limit != 0)
		while (stack->values[limit] != stack->smallest)
			limit++;
	else
		limit = stack->amount;
	// ft_printf("Limit: %d\n", limit);
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
	// ft_printf("median arr:\n");
	// for (int j = 0; j < limit; j++) {
	// 	ft_printf("[%d]: %d\n", j, arr[j]);
	// }
	quicksort(arr, limit);
	// ft_printf("quicksorted median arr, limit %d:\n", limit);
	// for (int h = 0; h < limit; h++) {
	// 	ft_printf("[%d]: %d\n", h, arr[h]);
	// }
	n = limit;
	n = (n + 1) / 2 - 1;
	med = arr[n];
	// ft_printf("Median : %d\n", med);
	free(arr);
	return (med);
}
