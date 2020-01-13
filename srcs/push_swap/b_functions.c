/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:17:36 by hopham            #+#    #+#             */
/*   Updated: 2020/01/13 13:30:32 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	special_median_b(t_stack *b)
{
	t_lstnum	*tmp;
	int			arr[7];
	int			i;
	int			j[2];

	tmp = b->head;
	i = 0;
	while (tmp != b->p[b->top])
	{
		arr[i++] = tmp->n;
		tmp = tmp->next;
	}
	j[0] = -1;
	while (j[0]++ < i)
	{
		j[1] = j[0];
		while (++j[1] < i)
			if (arr[j[0]] > arr[j[1]])
			{
				arr[6] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[6];
			}
	}
	return ((!b->p[b->top]) ? arr[2] : arr[1]);
}

int		deal_lower_b(t_stack *b, char *solution, int med, int count[2])
{
	int			skips;
	t_lstnum	*tmp;

	skips = 0;
	tmp = b->head;
	while (tmp != b->p[b->top] && tmp->n <= med)
	{
		skips++;
		tmp = tmp->next;
	}
	if (tmp == b->p[b->top])
		return (0);
	count[0] += skips;
	while (skips--)
	{
		ft_rotate(&b->head, &b->end);
		ft_strcat(solution, "rb\n");
	}
	return (1);
}

void	split_round_median_b(t_stack *a, t_stack *b, int med, char *cmnds)
{
	int		count[2];

	count[0] = 0;
	count[1] = 0;
	while (b->head != b->p[b->top])
	{
		if (b->head->n > med)
		{
			push(&b->head, &a->head, &a->end);
			ft_strcat(cmnds, "pa\n");
		}
		else if (!(deal_lower_b(b, cmnds, med, count)))
			break ;
	}
	while (b->p[b->top] && --count[0] >= 0)
	{
		ft_reverse_rotate(&b->head, &b->end);
		ft_strcat(cmnds, "rrb\n");
	}
}

void	three_caseb(t_stack *a, char *tmp)
{
	while (!(a->head->next->n > a->head->next->next->n
	&& a->head->n > a->head->next->next->n))
	{
		if (a->head->next->n < a->head->next->next->n
		&& a->head->next->n < a->head->n)
		{
			ft_reverse_rotate(&a->head, &a->end);
			ft_strcat(tmp, "rrb\n");
		}
		else
		{
			ft_rotate(&a->head, &a->end);
			ft_strcat(tmp, "rb\n");
		}
	}
	if (!(a->head->next->n > a->head->n))
		return ;
	swap(&a->head);
	ft_strcat(tmp, "sb\n");
}

void	sort_b(t_stack *b, int count, char *tmp)
{
	if (b->top)
		b->top--;
	if (count == 1 || !count)
		return ;
	if (count == 2)
	{
		if (b->head->next && b->head->next->n > b->head->n)
		{
			swap(&b->head);
			ft_strcat(tmp, "sb\n");
		}
		return ;
	}
	three_caseb(b, tmp);
}
