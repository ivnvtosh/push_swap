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
void	apply_comm(t_stack **a, t_stack **b);

static void	push_from_a_to_b_mid(int count, t_stack **a, t_stack **b, t_var var)
{
	while (count > 0)
	{
		if (var.min == (*a)->value || var.max == (*a)->value)
			action(a, b, RA);
		else
		{
			if (var.mid < (*a)->value)
				action(a, b, PB);
			else
			{
				action(a, b, PB);
				if (var.min == (*a)->value || var.max == (*a)->value)
				{
					action(a, b, RR);
					count--;
				}
				else
					action(a, b, RB);
			}
		}
		count--;
	}
}

static void	push_from_a_to_b(int count, t_stack **a, t_stack **b)
{
	t_var	var;

	var.min = stack_get_min(*a)->value;
	var.mid = stack_get_mid(*a)->value;
	var.max = stack_get_max(*a)->value;
	if (count < 300)
		push_from_a_to_b_mid(count, a, b, var);
	else
		chunks(count, a, b, var);
}

void	justsort(int count, t_stack **a, t_stack **b)
{
	push_from_a_to_b(count, a, b);
	while (*b != NULL)
	{
		calculate(*a, *b);
		recalculate(*b);
		apply_comm(a, b);
	}
	if ((*a)->value < count / 2)
		while ((*a)->value != 0)
			action(a, b, RRA);
	else
		while ((*a)->value != 0)
			action(a, b, RA);
}
