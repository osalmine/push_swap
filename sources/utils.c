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
	ft_printf("find in stack stack:\n");
	for (int j = 0; j < stack->amount; j++) {
		ft_printf("[%d]: %d\n", j, stack->values[j]);
	}
	while (i < stack->amount)
	{
		ft_printf("stack val at i (%d) is %d and value is %d\n", i, stack->values[i], value);
		if (stack->values[i] == value)
			return (i);
		i--;
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

static void sort(t_ps stack)
{
	int		i;
	int		j;
	t_ps	copy;

	copy = stack;
	i = 0;
	while (i < copy.size - 1)
	{
		j = 0;
		while (j < copy.size - i - 1)
		{
			if (copy.values[j] > copy.values[j + 1])
				swap(&copy.values[j], &copy.values[j + 1]);
			j++;
		}
		i++;
	}
}

int			median(t_ps *stack)
{
	int n;

	sort(*stack);
	n = stack->size;
	n = (n + 1) / 2 - 1;
	ft_printf("Median : %d\n", stack->values[n]);
	return (stack->values[n]);
}
