/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:09:19 by hopham            #+#    #+#             */
/*   Updated: 2020/01/08 16:49:33 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	/*
	int	fd;
	int	bytes;
	char	buf[1000];

	fd = 0;
	while ((bytes = read(0, buf, 1)))
	{
		
	}
	*/
	build_stack(&a, &b, av, ac);

	return (0);
}
