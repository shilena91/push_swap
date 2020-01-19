/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:05:21 by hopham            #+#    #+#             */
/*   Updated: 2020/01/19 14:17:01 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack a;
	t_stack	b;
	t_list	*solution;
	
	if (ac < 2)
		return (0);
	build_stack(&a, &b, ac, av);
	if (!(a.p = malloc(sizeof(t_lstnum*) * ac)) ||
	!(b.p = malloc(sizeof(t_lstnum*) * ac)))
		exit(1);
	a.ac = ac;
	b.ac = ac;
	a.top = 0;
	b.top = 0;
	a.p[a.top] = NULL;
	b.p[a.top] = NULL;
	solution = solve(&a, &b);
	while (solution)
	{
		ft_putstr((char*)solution->content);
		solution = solution->next;
	}
}
