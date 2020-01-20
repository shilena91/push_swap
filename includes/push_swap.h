/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 07:12:02 by HoangPham         #+#    #+#             */
/*   Updated: 2020/01/20 15:57:01 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define NO_MED 2147483648

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
	t_lstnum	**p;
	int			top;
	int			ac;
}				t_stack;

void	parse_nb_from_first_str(t_stack *a, char *str);
void	parse_nb_from_second_str(t_stack *a, char *str);

void	ft_error(void);
void	build_stack(t_stack *a, t_stack *b, int ac, char **av);
void	swapper(t_stack *a, t_stack *b, char *line);
void	swap(t_lstnum **stack);
void	push(t_lstnum **from, t_lstnum **to, t_lstnum **to_end);
void	ft_rotate(t_lstnum **head, t_lstnum **end);
void	rotater(t_stack *a, t_stack *b, char *line);
void	ft_reverse_rotate(t_lstnum **head, t_lstnum **end);
void	reverse_rotater(t_stack *a, t_stack *b, char *line);

t_list	*solve(t_stack *a, t_stack *b);
int		get_count(t_stack *stack);
int		get_true_median(t_stack *a);
void	split_around_median_a(t_stack *a, t_stack *b, int med, char *solution);
int		get_special_median_a(t_stack *a);
void	sort_a(t_stack *a, int count, char *solution);
int		get_special_median_b(t_stack *b);
void	split_around_median_b(t_stack *a, t_stack *b, int med, char *solution);
void	sort_b(t_stack *b, int count, char *tmp);

#endif