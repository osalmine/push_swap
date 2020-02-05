/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:02:02 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/05 15:57:45 by osalmine         ###   ########.fr       */
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
		ft_printf("stack val at i (%d) is %d and value is %d\n", i, stack->values[i], value);
		if (stack->values[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void		swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void quicksort(int* data, int N)
{
  int i, j;
  int v, t;

  if( N <= 1 )
    return;

  v = data[0];
  i = 0;
  j = N;
  for(;;)
  {
    while(data[++i] < v && i < N) { }
    while(data[--j] > v) { }
    if( i >= j )
      break;
    t = data[i];
    data[i] = data[j];
    data[j] = t;
  }
  t = data[i-1];
  data[i-1] = data[0];
  data[0] = t;
  quicksort(data, i-1);
  quicksort(data+i, N-i);
}

int			median(t_ps *stack)
{
	int n;
	int *arr;

	arr = (int*)malloc(sizeof(int) * stack->amount);
	n = 0;
	while (n < stack->amount)
	{
		arr[n] = stack->values[n];
		n++;
	}
	quicksort(arr, stack->amount);
	n = stack->size;
	n = (n + 1) / 2 - 1;
	ft_printf("Median : %d\n", arr[n]);
	free(arr);
	return (arr[n]);
}
