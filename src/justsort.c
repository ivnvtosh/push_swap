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

void	chunks(int count, t_stack **a, t_stack **b, t_var var);
void	calculate(t_stack *a, t_stack *b);
void	recalculate(t_stack *b);
t_score	search_best(t_stack *b);
void	apply_comm(t_stack **a, t_stack **b, t_score score);

// void	lol(t_stack **a, t_stack **b, t_stack *top, t_var var)
// {
// 	if (top->value == var.mid && top->value == var.min)
// 	{
// 		action(a, b, "sa");
// 		return ;
// 	}
// 	if (top->value == var.max)
// 		top = top->prev;
// 	while (top->prev != NULL && top->value < top->prev->value)
// 		top = top->prev;
// 	if (top->prev != NULL)
// 		action(a, b, "sa");
// }

void	push_from_a_to_b(int count, t_stack **a, t_stack **b, t_var var)
{
	while (count > 0)
	{
		// if (var.min == (*a)->value || var.max == (*a)->value || var.mid == (*a)->value)
		if (var.min == (*a)->value || var.max == (*a)->value)
			action(a, b, "ra");
		else
		{
			if (var.mid < (*a)->value)
				action(a, b, "pb");
			else
			{
				action(a, b, "pb");
				if (var.min == (*a)->value || var.max == (*a)->value)
				{
					action(a, b, "rr");
					count--;
				}
				else
					action(a, b, "rb");
			}
		}
		count--;
	}
	// lol(a, b, *a, var);
}

void	justsort(int count, t_stack **a, t_stack **b)
{
	t_score	score;
	t_var	var;

	var.min = stack_get_min(*a)->value;
	var.mid = stack_get_mid(*a)->value;
	var.max = stack_get_max(*a)->value;
	if (count < 300)
		push_from_a_to_b(count, a, b, var);
	else
		chunks(count, a, b, var);
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
