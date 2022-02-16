/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libst.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:12:24 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:12:26 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBST_H
# define LIBST_H

typedef struct s_score
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_score;

typedef struct s_stack
{
	int				value;
	int				mid;
	t_score			score;
	struct s_stack	*prev;
}	t_stack;

void	stack_add_bottom(t_stack **stack, t_stack *new);
void	stack_add_top(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **stack);
void	stack_delone(t_stack *stack);
t_stack	*stack_duplicate(t_stack *stack);
t_stack	*stack_get_bottom(t_stack *stack);
t_stack	*stack_get_max(t_stack *stack);
t_stack	*stack_get_mid(t_stack *stack);
t_stack	*stack_get_min(t_stack *stack);
int		stack_get_height(t_stack *stack);
t_stack	*stack_get_new(int value);
void	stack_print_one(t_stack *stack);
void	stack_print(t_stack *a, t_stack *b);
void	stack_push(t_stack **from, t_stack **to);
void	stack_reverce_rotate(t_stack **stack);
void	stack_rotate(t_stack **stack);
void	stack_swap(t_stack *stack);

#endif
