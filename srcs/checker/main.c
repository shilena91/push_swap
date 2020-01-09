/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:09:19 by hopham            #+#    #+#             */
/*   Updated: 2020/01/09 19:12:17 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*line;
	t_test	test;
	/*
	int	fd;
	int	bytes;
	char	buf[1000];

	fd = 0;
	while ((bytes = read(0, buf, 1)))
	{
		
	}
	*/
	build_stack(&a, &b, ac, av);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb") || !ft_strcmp(line, "ss"))
			swapper(&a, &b, line);
		else if (!ft_strcmp(line, "pa"))
			push(&a.head, &b.head, &a.end);
	}
	

	return (0);
}
