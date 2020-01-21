/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:29:02 by hopham            #+#    #+#             */
/*   Updated: 2020/01/21 18:32:45 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

static int		check_double(t_stack *a)
{
	t_lstnum	*tmp1;
	t_lstnum	*tmp2;
	int			num;

	tmp1 = a->head;
	while (tmp1)
	{
		num = tmp1->n;
		tmp2 = tmp1;
		while (tmp2->next)
		{
			if (num == tmp2->next->n)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

void			build_stack(t_stack *a, t_stack *b, int ac, char **av)
{
	int	i;

	a->head = ft_memalloc(sizeof(t_lstnum));
	parse_nb_from_first_str(a, av[1]);
	i = 2;
	while (i < ac)
	{
		parse_nb_from_second_str(a, av[i]);
		i++;
	}
	if (!(check_double(a)))
		ft_error();
	b->head = NULL;
	b->end = NULL;
}
