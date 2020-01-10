/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:40:05 by hopham            #+#    #+#             */
/*   Updated: 2020/01/10 17:26:33 by hopham           ###   ########.fr       */
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
}

void	rotater(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strcmp(line, "ra"))
		ft_rotate(&a->head, &a->end);
	else if (!ft_strcmp(line, "rb"))
		ft_rotate(&b->head, &b->end);
	else
	{
		ft_rotate(&a->head, &a->end);
		ft_rotate(&b->head, &b->end);
	}
	
}