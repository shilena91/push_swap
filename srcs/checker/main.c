/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:09:19 by hopham            #+#    #+#             */
/*   Updated: 2020/01/12 23:05:51 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_a(t_lstnum **a)
{
	t_lstnum *tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->next->n < tmp->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

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
		free(line);
	}
	if (check_a(&a.head) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
