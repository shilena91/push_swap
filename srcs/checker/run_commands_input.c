/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:40:05 by hopham            #+#    #+#             */
/*   Updated: 2020/01/09 18:53:09 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapper(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strcmp(line, "sa"))
		swap(&a->head);
	else if (!ft_strcmp(line, "sb"))
		swap(&b->head);
	else
	{
		swap(&a->head);
		swap(&b->head);
	}
	while (a->head)
	{
		ft_printf("%i ", a->head->n);
		a->head = a->head->next;
	}
}
