/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:15:13 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/10 18:39:39 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check(t_ps *a_stack)
{
	char	*str;
	t_ps	*b_stack;
	int		size;

	str = NULL;
	if (is_in_order(*a_stack, 1))
	{
		ft_printf("OK\n");
		return ;
	}
	b_stack = b_init(a_stack);
	ft_printf("a_stack bef visual:\n");
	for (int j = 0; j < a_stack->amount; j++) {
		ft_printf("%d: %d\n", j, a_stack->values[j]);
	}
	ft_printf("a_stack amount: %d, size: %d\n", a_stack->amount, a_stack->size);
	ft_printf("b_stack:\n");
	for (int k = 0; k < b_stack->amount; k++) {
		ft_printf("%d: %d\n", k, b_stack->values[k]);
	}
	ft_printf("b_stack amount: %d, size: %d\n", b_stack->amount, b_stack->size);
	if (a_stack->visual == TRUE)
		visual(a_stack, b_stack, str);
	while ((size = get_next_line(0, &str)) > 0)
	{
//		ft_printf("command: %s\n", str);
		do_command(a_stack, b_stack, str);
		if (a_stack->visual == TRUE)
			visual(a_stack, b_stack, str);
		free(str);
	}
	if (size <= -1)
		ft_exit("Checker: fd error");
	if (!is_in_order(*a_stack, 1))
		ft_exit("KO");
	ft_printf("OK\n");
	free_struct(b_stack);
}

int		main(int argc, char **argv)
{
	t_ps *a_stack;

	if (argc < 2)
		return (0);
	a_stack = parse(argc, argv);
	if (a_stack->print != TRUE)
		a_stack->print = FALSE;
	check(a_stack);
	free_struct(a_stack);
	return (0);
}
