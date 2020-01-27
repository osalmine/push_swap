/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:15:13 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/27 17:12:03 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	check(t_ps *a_stack)
{
	char	*str;
	t_ps	*b_stack;
	ssize_t	size;

	str = NULL;
	if (!(b_stack = (t_ps*)malloc(sizeof(t_ps))))
		ft_exit("Error");
	if (!(b_stack->values = (int*)malloc(sizeof(int) * a_stack->amount)))
		ft_exit("Error");
	printf("a_stack:\n");
	for (int j = 0; j < a_stack->amount; j++) {
		printf("%d: %d\n", j, a_stack->values[j]);
	}
	printf("b_stack:\n");
	for (int k = 0; k < b_stack->amount; k++) {
		printf("%d: %d\n", k, b_stack->values[k]);
	}
	while ((size = get_next_line(0, &str)) > 0)
	{
		do_command(a_stack, b_stack, str);
		free(str);
	}
	printf("out\n");
	if (size <= -1)
		ft_exit("Error");
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
