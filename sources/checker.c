/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:15:13 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/01 15:39:04 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	is_in_order(t_ps *stack, int check_size)
{
	if (check_size && stack->size != stack->amount)
		ft_exit("Error");
	while (stack->amount - 1 > 0)
	{
		if (stack->values[stack->amount - 1] < stack->values[stack->amount - 2])
			ft_exit("KO");
		stack->amount--;
	}
	ft_putendl("Order OK");
}

void	check(t_ps *a_stack)
{
	char	*str;
	t_ps	*b_stack;
	int		size;

	str = NULL;
	b_stack = b_init(a_stack);
	printf("a_stack:\n");
	for (int j = 0; j < a_stack->amount; j++) {
		printf("%d: %d\n", j, a_stack->values[j]);
	}
	printf("a_stack amount: %d, size: %d\n", a_stack->amount, a_stack->size);
	printf("b_stack:\n");
	for (int k = 0; k < b_stack->amount; k++) {
		printf("%d: %d\n", k, b_stack->values[k]);
	}
	printf("b_stack amount: %d, size: %d\n", b_stack->amount, b_stack->size);
	while ((size = get_next_line(0, &str)) > 0)
	{
		do_command(a_stack, b_stack, str);
		free(str);
	}
	if (size <= -1)
		ft_exit("Error");
	is_in_order(a_stack, 1);
}

int		main(int argc, char **argv)
{
	t_ps *a_stack;

	a_stack = parse(argc, argv);
	if (a_stack != NULL)
		ft_putendl("OK");
	else
		ft_exit("Error");
	check(a_stack);
}
