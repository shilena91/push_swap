/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nb_from_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:55:44 by hopham            #+#    #+#             */
/*   Updated: 2020/01/20 17:51:47 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_lstnum	*add_num_to_struct(int num)
{
	t_lstnum	*new_num;

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

static void		add_nb_to_list(t_stack *s, t_lstnum *new_num, char *str, int *i)
{
	while (str[*i])
	{
		while (ft_isblank(str[*i]))
			(*i)++;
		if (str[*i] == '\0')
			break ;
		if (!ft_isdigit(str[*i]) && !ft_isblank(str[*i])
			&& str[*i] != '-' && str[*i] != '+' && str[*i] != '\0')
			ft_error();
		if (ft_isdigit(str[*i]) && !ft_isdigit(str[*i + 1])
			&& !ft_isblank(str[*i + 1]) && str[*i + 1] != '\0')
			ft_error();
		if ((str[*i] == '-' || str[*i] == '+')
			&& !ft_isdigit(str[*i + 1]) && str[*i + 1] != '\0')
			ft_error();
		new_num = add_num_to_struct(ft_atoi(&str[*i]));
		lst_addend(&s->end, new_num);
		if (str[*i] == '-' || str[*i] == '+')
			(*i)++;
		while (ft_isdigit(str[*i]))
			(*i)++;
		if (str[*i] && !ft_isblank(str[*i]))
			ft_error();
	}
}

void			parse_nb_from_first_str(t_stack *a, char *str)
{
	int			i;
	t_lstnum	*new_num;

	new_num = NULL;
	i = 0;
	if (!str[i])
		return ;
	while (ft_isblank(str[i]))
		i++;
	if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
		ft_error();
	a->head->n = ft_atoi(&str[i]);
	a->end = a->head;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] && !ft_isblank(str[i]))
		ft_error();
	add_nb_to_list(a, new_num, str, &i);
}

void			parse_nb_from_second_str(t_stack *a, char *str)
{
	int			i;
	t_lstnum	*new_num;

	new_num = NULL;
	i = 0;
	if (!str[i])
		return ;
	add_nb_to_list(a, new_num, str, &i);
}
