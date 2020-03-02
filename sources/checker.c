/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:15:13 by osalmine          #+#    #+#             */
/*   Updated: 2020/03/02 11:45:43 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		lst_size(t_list *lst)
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

static void		cmd_lst(t_list *cmds, t_ps *a_stack, t_ps *b_stack)
{
	t_list *head;

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
}

static t_list	*check(t_ps *a_stack, t_ps *b_stack)
{
	char	*str;
	int		size;
	t_list	*cmds;

	str = NULL;
	cmds = NULL;
	while ((size = get_next_line(0, &str)) > 0)
	{
		if (a_stack->visual == TRUE || a_stack->cmd_nb == TRUE)
			ft_lstadd(&cmds, ft_lstnew(str, sizeof(char*)));
		if (a_stack->cmd_nb == TRUE && a_stack->visual == FALSE)
			do_command(a_stack, b_stack, str);
		if (a_stack->cmd_nb == FALSE && a_stack->visual == FALSE)
			do_command(a_stack, b_stack, str);
		free(str);
	}
	if (size <= -1)
		ft_exit("Checker: read error");
	return (cmds);
}

int				main(int argc, char **argv)
{
	t_ps	*a_stack;
	t_ps	*b_stack;
	t_list	*cmds;

	if (argc < 2)
		return (0);
	a_stack = parse(argc, argv);
	b_stack = b_init(a_stack);
	if (is_in_order(*a_stack, 1))
	{
		ft_printf("OK\n");
		return (0);
	}
	if ((cmds = check(a_stack, b_stack)))
		cmd_lst(cmds, a_stack, b_stack);
	if (!is_in_order(*a_stack, 1))
		ft_exit(RESET"KO");
	ft_printf(RESET"OK\n");
	free_struct(b_stack);
	free_struct(a_stack);
	return (0);
}
