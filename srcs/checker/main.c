/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:09:19 by hopham            #+#    #+#             */
/*   Updated: 2020/01/11 12:35:19 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*line;

	build_stack(&a, &b, ac, av);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb") || !ft_strcmp(line, "ss"))
			swapper(&a, &b, line);
		else if (!ft_strcmp(line, "pa"))
			push(&b.head, &a.head, &a.end);
		else if (!ft_strcmp(line, "pb"))
			push(&a.head, &b.head, &b.end);
		else if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rb") || !ft_strcmp(line, "rr"))
			rotater(&a, &b, line);
		else if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb") || !ft_strcmp(line, "rrr"))
			reverse_rotater(&a, &b, line);
		else
			ft_error();
	}
	return (0);
}
