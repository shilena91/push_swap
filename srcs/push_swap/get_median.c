/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:45:22 by hopham            #+#    #+#             */
/*   Updated: 2020/01/17 15:50:12 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_count(t_stack *stack)
{
	int			count;
	t_lstnum	*tmp;

	tmp = stack->head;
	count = 0;
	while (tmp != stack->p[stack->top])
	{
		count++;
		tmp = tmp->next;
	}
	if (!stack->p[stack->top] && count == 3)
		return (-1);
	return (count);
}

int	get_true_median(t_stack *a)
{
	t_lstnum	*tmp;
	int			i;
	int			arr[a->ac];

	tmp = a->head;
	i = 0;
	while (tmp != a->p[a->top])
	{
		arr[i] = tmp->next;
		i++;
		tmp = tmp->next;
	}
	sort_int_tab_des(arr, i);
	return (arr[i / 2]);
}
