/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   justsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:10:55 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:10:58 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_var
{
	int	min;
	int	mid;
	int	max;
}	t_var;

void	chunks(t_stack **a, t_stack **b, int count, t_var var);
void	calculate(t_stack *a, t_stack *b);
void	recalculate(t_stack *b);
t_score	search_best(t_stack *b);
void	apply_comm(t_stack **a, t_stack **b, t_score score);

void	justsort(int count, t_stack **a, t_stack **b)
{
	t_score	score;
	t_var	var;

	var.min = stack_get_min(*a)->value;
	var.mid = stack_get_mid(*a)->value;
	var.max = stack_get_max(*a)->value;
	chunks(a, b, count, var);
	while (*b != NULL)
	{
		calculate(*a, *b);
		recalculate(*b);
		score = search_best(*b);
		apply_comm(a, b, score);
	}
	if ((*a)->value < count / 2)
		while ((*a)->value != 0)
			action(a, b, RRA);
	else
		while ((*a)->value != 0)
			action(a, b, RA);
}
