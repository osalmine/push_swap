/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:02:02 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/06 15:51:41 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_small_big(t_ps *stack)
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

int		find_in_stack(t_ps *stack, int value)
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

void	sorted_numbers(t_ps *ref, int n)
{
	push_down(ref);
	ref->values[0] = n;
	ref->amount++;
}

void	quicksort(int *data, int n)
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

int		median(t_ps *stack)
{
	int n;
	int *arr;

	if (!(arr = (int*)malloc(sizeof(int) * stack->amount)))
		ft_exit("Error");
	n = 0;
	while (n < stack->amount)
	{
		arr[n] = stack->values[n];
		n++;
	}
	quicksort(arr, stack->amount);
	n = stack->amount;
	n = (n + 1) / 2 - 1;
	// ft_printf("Median : %d\n", arr[n]);
	free(arr);
	return (arr[n]);
}
