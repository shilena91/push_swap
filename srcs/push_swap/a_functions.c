/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:52:23 by hopham            #+#    #+#             */
/*   Updated: 2020/01/17 18:16:47 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_special_median_a(t_stack *a)
{
	t_lstnum	*tmp;
	int			arr[12];
	int			i;

	tmp = a->head;
	i = 0;
	while (tmp != a->p[a->top])
	{
		arr[i] = tmp->n;
		i++;
		tmp = tmp->next;
	}
	sort_int_tab_des(arr, i);
	if (a->p[a->top])
		return (arr[2]);
	return (arr[3]);
}

void	three_nb_case(t_stack *a, char *solution)
{
	while (a->head->next->n > a->head->next->next->n
			&& a->head->n > a->head->next->next->n)
		{
			if (a->head->next->n > a->head->next->next->n
				&& a->head->next->n > a->head->n)
			{
				ft_reverse_rotate(&a->head, &a->end);
				ft_strcat(solution, "rra\n");
			}
			else
			{
				ft_rotate(&a->head, &a->end);
				ft_strcat(solution, "ra\n");
			}
		}
	if (a->head->n < a->head->next->n)
			return ;
	swap(&a->head);
	ft_strcat(solution, "sa\n");
}

void	sort_a(t_stack *a, int count, char *solution)
{
	if (count == 1)
		return ;
	if (count == 2)
	{
		if (a->head->n > a->head->next->n)
		{
			swap(a->head);
			ft_strcat(solution, "sa");
		}
		return ;
	}
	three_nb_case(a, solution);
}

int		deal_higher_nb_a(t_stack *a, char *solution, int med)
{
	t_lstnum	*tmp;
	int			i;

	tmp = a->head;
	i = 0;
	while (tmp != a->p[a->top] && tmp->next > med)
	{
		i++;
		tmp = tmp->next;
	}
	if (tmp == a->p[a->top])
		return (0);
	while (i > 0)
	{
		ft_rotate(&a->head, &a->end);
		ft_strcat(solution, "ra\n");
		i--;
	}
	return (1);
}

void	split_around_median_a(t_stack *a, t_stack *b, int med, char *solution)
{
	if (b->head)
		b->p[++(b->top)] = b->head;
	while (a->head != a->p[a->top])
	{
		if (a->head->n <= med)
		{
			push(&a->head, &b->head, &b->end);
			ft_strcat(solution, "pb\n");
		}
		else if (deal_higher_nb_a(a, solution, med) == 0)
			break ;
	}
}
