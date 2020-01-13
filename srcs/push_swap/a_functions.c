/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:22:05 by hopham            #+#    #+#             */
/*   Updated: 2020/01/13 13:31:02 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	special_median_a(t_stack *a)
{
	t_lstnum	*tmp;
	int			arr[12];
	int			i;
	int			j[2];

	tmp = a->head;
	i = 0;
	while (tmp != a->p[a->top])
	{
		arr[i++] = tmp->n;
		tmp = tmp->next;
	}
	j[0] = -1;
	while (j[0]++ < i)
	{
		j[1] = j[0];
		while (++j[1] < i)
			if (arr[j[0]] < arr[j[1]])
			{
				arr[11] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[11];
			}
	}
	return ((!a->p[a->top]) ? arr[3] : arr[2]);
}

int		deal_higher_a(t_stack *a, char *cmnds, int med, int *t_rewind)
{
	int			skips;
	t_lstnum	*tmp;

	skips = 0;
	tmp = a->head;
	while (tmp != a->p[a->top] && tmp->n > med)
	{
		skips++;
		tmp = tmp->next;
	}
	if (tmp == a->p[a->top])
		return (0);
	*t_rewind = *t_rewind + skips;
	while (skips--)
	{
		ft_rotate(&a->head, &a->end);
		ft_strcat(cmnds, "ra\n");
	}
	return (1);
}

void	split_round_median_a(t_stack *a, t_stack *b, int med, char *cmnds)
{
	int		rewind;

	rewind = 0;
	if (b->head)
		b->p[++(b->top)] = b->head;
	while (a->head != a->p[a->top])
	{
		if (a->head->n <= med)
		{
			push(&a->head, &b->head, &b->end);
			ft_strcat(cmnds, "pb\n");
		}
		else if (!(deal_higher_a(a, cmnds, med, &rewind)))
			break ;
	}
	while (a->p[a->top] && --rewind >= 0)
	{
		ft_reverse_rotate(&a->head, &a->end);
		ft_strcat(cmnds, "rra\n");
	}
}

void	three_case(t_stack *a, char *tmp)
{
	while (!(a->head->next->n < a->head->next->next->n
	&& a->head->n < a->head->next->next->n))
	{
		if (a->head->next->n > a->head->next->next->n
		&& a->head->next->n > a->head->n)
		{
			ft_reverse_rotate(&a->head, &a->end);
			ft_strcat(tmp, "rra\n");
		}
		else
		{
			ft_rotate(&a->head, &a->end);
			ft_strcat(tmp, "ra\n");
		}
	}
	if (!(a->head->next->n < a->head->n))
		return ;
	swap(&a->head);
	ft_strcat(tmp, "sa\n");
}

void	sort_a(t_stack *a, int count, char *tmp)
{
	if (count == 1)
		return ;
	if (count == 2)
	{
		if (a->head->next->n < a->head->n)
		{
			swap(&a->head);
			ft_strcat(tmp, "sa\n");
		}
		return ;
	}
	three_case(a, tmp);
}
