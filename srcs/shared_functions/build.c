/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:29:02 by hopham            #+#    #+#             */
/*   Updated: 2020/01/09 18:06:14 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

static int		check_only_num(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (!ft_isdigit(av[i][j]))
			return (0);
		while (ft_isdigit(av[i][j]))
			j++;
		if (av[i][j])
			return (0);
		i++;
	}
	return (1);
}

static t_lstnum	*add_num_to_struct(char *str)
{
	t_lstnum	*new_num;
	int			num;

	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		return (NULL);
	new_num = (t_lstnum*)ft_memalloc(sizeof(t_lstnum));
	new_num->n = num;
	new_num->next = NULL;
	return (new_num);
}

static void		lst_addend(t_lstnum **backtrack, t_lstnum *new_num)
{
	t_lstnum	*tmp;

	if (*backtrack == NULL)
		return ;
	tmp = *backtrack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_num;
	tmp = tmp->next;
	tmp->prev = *backtrack;
	*backtrack = tmp;
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
	int			i;
	t_lstnum	*new_num;

	if (!check_only_num(ac, av) || !(a->head = ft_memalloc(sizeof(t_lstnum))))
		ft_error();
	a->head->n = ft_atoi(av[1]);
	a->end = a->head;
	i = 2;
	while (i < ac)
	{
		if (!(new_num = add_num_to_struct(av[i])))
			ft_error();
		lst_addend(&a->end, new_num);
		i++;
	}
	if (!(check_double(a)))
		ft_error();
	b->head = NULL;
	b->end = NULL;
}
