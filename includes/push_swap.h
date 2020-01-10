/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 07:12:02 by HoangPham         #+#    #+#             */
/*   Updated: 2020/01/10 17:28:32 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct	s_lstnum
{
	int				n;
	struct s_lstnum	*next;
	struct s_lstnum	*prev;
}				t_lstnum;

typedef struct	s_stack
{
	t_lstnum	*head;
	t_lstnum	*end;
}				t_stack;

typedef struct	s_test
{
	int			head;
	char		*end;
}				t_test;

void	ft_error(void);
void	build_stack(t_stack *a, t_stack *b, int ac, char **av);
void	swapper(t_stack *a, t_stack *b, char *line);
void	swap(t_lstnum **stack);
void	push(t_lstnum **from, t_lstnum **to, t_lstnum **to_end);
void	ft_rotate(t_lstnum **head, t_lstnum **end);
void	rotater(t_stack *a, t_stack *b, char *line);

#endif