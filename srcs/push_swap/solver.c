/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:08:52 by hopham            #+#    #+#             */
/*   Updated: 2020/01/13 18:23:22 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		split_a(t_stack *a, t_stack *b, t_list **solution)
{
	int		count;
	long	median;
	char	tmp[a->ac * 4];

	tmp[0] = '\0';
	count = get_count(a);
	median = NO_MED;
	if (count <= 11 && count > 2)
		median = special_median_a(a);
	else if (count > 11)
		median = get_true_median(a);
	if (median != NO_MED)
		split_round_median_a(a, b, (int)median, tmp);
	else
		sort_a(a, count, tmp);
	if (tmp[0])
		ft_lstadd_end(solution, ft_lstnew_str(tmp));
	if (median == NO_MED)
		a->p[++(a->top)] = a->head;
	return ((median == NO_MED) ? 1 : 0);
}

int		sorted(t_stack *a)
{
	t_lstnum	*tmp;

	tmp = a->head;
	while (tmp)
	{
		if (tmp->next && tmp->next->n < tmp->n)
			return (0);
		tmp = tmp->next;
		if (tmp == a->p[a->top])
			break ;
	}
	return (1);
}

void	push_b(t_stack *b, t_stack *a, int count, char *tmp)
{
	int i;

	i = 0;
	count = (count == -1) ? 3 : count;
	while (i++ < count)
	{
		push(&b->head, &a->head, &a->end);
		ft_strcat(tmp, "pa\n");
	}
}

void	b_to_a(t_stack *a, t_stack *b, t_list **solution)
{
	int		count;
	long	median;
	char	tmp[a->ac * 4];

	tmp[0] = '\0';
	count = get_count(b);
	median = NO_MED;
	if (count <= 6 && count > 2)
		median = special_median_b(b);
	else if (count > 6)
		median = get_true_median(b);
	if (median != NO_MED)
		split_round_median_b(a, b, (int)median, tmp);
	else
		sort_b(b, count, tmp);
	if (median == NO_MED)
		push_b(b, a, count, tmp);
	if (tmp[0])
		ft_lstadd_end(solution, ft_lstnew_str(tmp));
}

t_list	*solver(t_stack *a, t_stack *b)
{
	t_list	*solution;
	int		ret;
	int		sort;

	solution = ft_lstnew("\0", 1);
	while (!(sort = sorted(a)) || b->head != NULL)
	{
		if (!sort)
		{
			while ((ret = split_a(a, b, &solution)) == 0)
				;
			if (ret == -1)
				exit(1);
		}
		else
			a->p[++(a->top)] = a->head;
		b_to_a(a, b, &solution);
	}
	return (solution);
}
