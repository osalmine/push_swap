/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:15:13 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/25 15:36:25 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_checker(int ac, char **av)
{
	av = NULL;
	if (ac == 2)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	int check;

	check = ft_checker(argc, argv);
	if (check)
		ft_putendl("OK");
	else
		ft_putendl_fd("ERROR", 2);
}
