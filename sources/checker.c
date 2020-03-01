/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:15:13 by osalmine          #+#    #+#             */
/*   Updated: 2020/03/01 19:48:38 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	lst_size(t_list *lst)
{
	int		count;
	t_list	*ptr;

	count = 0;
	ptr = lst;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

void		check(t_ps *a_stack)
{
	char	*str;
	t_ps	*b_stack;
	int		size;
	t_list	*cmds;
	t_list	*head;

	str = NULL;
	cmds = NULL;
	if (is_in_order(*a_stack, 1))
	{
		ft_printf("OK\n");
		return ;
	}
	b_stack = b_init(a_stack);
	// ft_printf("a_stack bef visual:\n");
	// for (int j = 0; j < a_stack->amount; j++) {
	// 	ft_printf("%d: %d\n", j, a_stack->values[j]);
	// }
	// ft_printf("a_stack amount: %d, size: %d\n", a_stack->amount, a_stack->size);
	// ft_printf("b_stack:\n");
	// for (int k = 0; k < b_stack->amount; k++) {
	// 	ft_printf("%d: %d\n", k, b_stack->values[k]);
	// }
	// ft_printf("b_stack amount: %d, size: %d\n", b_stack->amount, b_stack->size);
	while ((size = get_next_line(0, &str)) > 0)
	{
		// ft_printf("command: |%s|\n", str);
		if (a_stack->visual == TRUE || a_stack->cmd_nb == TRUE)
			ft_lstadd(&cmds, ft_lstnew(str, sizeof(char*)));
		if (a_stack->cmd_nb == TRUE && a_stack->visual == FALSE)
			do_command(a_stack, b_stack, str);
		if (a_stack->cmd_nb == FALSE && a_stack->visual == FALSE)
			do_command(a_stack, b_stack, str);
		free(str);
	}
	char s[1];
	read (0, s, 1);
	if (size <= -1)
		ft_exit("Checker: read error");
	ft_lstrev(&cmds);
	head = cmds;
	if (a_stack->visual == TRUE)
	{
		visual(a_stack, b_stack, cmds);
		if (a_stack->cmd_nb == FALSE)
			free_lst(head);
	}
	if (a_stack->cmd_nb == TRUE)
	{
		cmds = head;
		ft_printf(RESET"Number of commands: %d\n", lst_size(cmds));
		free_lst(head);
	}
	if (!is_in_order(*a_stack, 1))
		ft_exit(RESET"KO");
	ft_printf(RESET"OK\n");
	free_struct(b_stack);
}

int			main(int argc, char **argv)
{
	t_ps *a_stack;

	if (argc < 2)
		return (0);
	a_stack = parse(argc, argv);
	check(a_stack);
	free_struct(a_stack);
	return (0);
}
