/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:29:02 by hopham            #+#    #+#             */
/*   Updated: 2020/01/08 18:49:21 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int		check_only_num(int ac, char **av)
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

int		check_doubles(t_stack *a, int ac)
{
	t_lstnum *tmp;
	int		i;
	int		j;
	int		k;
	int		arr[ac + 1];

	tmp = a->head;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->n;
		tmp = tmp->next;
	}
	j = -1;
	while (j++ < i)
	{
		k = j;
		while (++k < i)
			if (arr[j] == arr[k])
				return (0);
	}
	return (1);
}

void	lst_addend_fast(t_lstnum **back, char *str)
{
	t_lstnum	*tmp;
	int			num;

	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		ft_error();
	if (*back == NULL)
		return ;
	tmp = malloc(sizeof(t_lstnum));
	tmp->n = (int)num;
	tmp->next = NULL;
	(*back)->next = tmp;
	tmp->prev = *back;
	*back = tmp;
}

void	build_stack(t_stack *a, t_stack *b, int ac, char **av)
{
	int			i;
	t_lstnum	*tmp;

	i = 1;
	if (!check_only_num(ac, av) || !(a->head = malloc(sizeof(t_lstnum))))
		ft_error();
	a->head->n = ft_atoi(av[i]);
	i++;
	a->head->prev = NULL;
	a->end = a->head;
	while (i < ac)
	{
		lst_addend_fast(av[i], &a->end);
		i++;
	}
	if (!check_doubles(a, ac))
	{
		while (a->head)
		{
			tmp = a->head;
			a->head = a->head->next;
			free(tmp);
		}
		ft_error();
	}
	b->head = NULL;
	b->end = NULL;
}
