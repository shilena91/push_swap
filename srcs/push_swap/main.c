/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:05:21 by hopham            #+#    #+#             */
/*   Updated: 2020/01/21 18:24:54 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(t_stack *a, t_list *solution)
{
	t_lstnum	*tmp;
	t_list		*tmp_solution;

	while (a->head)
	{
		tmp = a->head;
		a->head = a->head->next;
		free(tmp);
	}
	while (solution)
	{
		tmp_solution = solution;
		solution = solution->next;
		ft_memdel((void**)solution);
	}
}

static int	count_numbers(t_stack *a)
{
	t_lstnum	*tmp;
	int			i;

	i = 0;
	tmp = a->head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static void	print_solution(t_list *solution)
{
	while (solution)
	{
		ft_putstr((char*)solution->content);
		solution = solution->next;
	}
}

int			main(int ac, char **av)
{
	t_stack a;
	t_stack	b;
	t_list	*solution;
	t_list	*tmp;
	int		count;

	if (ac < 2)
		return (0);
	build_stack(&a, &b, ac, av);
	count = count_numbers(&a);
	if (!(a.p = malloc(sizeof(t_lstnum*) * count)) ||
	!(b.p = malloc(sizeof(t_lstnum*) * count)))
		exit(1);
	a.ac = count;
	b.ac = count;
	a.top = 0;
	b.top = 0;
	a.p[a.top] = NULL;
	b.p[a.top] = NULL;
	solution = solve(&a, &b);
	tmp = solution;
	print_solution(solution);
	free_all(&a, tmp);
}
