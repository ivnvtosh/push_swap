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

void	lol(t_stack **a, t_stack **b, t_stack *top, t_var var)
{
	// stack_print(*a, *b);
	if (top->value == var.min && top->prev->value == var.mid)
		return ;
	if (top->value == var.mid && top->prev->value == var.max)
		return ;
	if (top->value == var.max && top->prev->value == var.min)
		return ;
	if (top->value == var.max)
		top = top->prev;
	while (top->prev != NULL && top->value < top->prev->value)
		top = top->prev;
	if (top->prev != NULL)
	{
		if ((*b)->value > (*b)->prev->value)
			action(a, b, SS);
		else
			action(a, b, SA);
	}
	else if ((*b)->value > (*b)->prev->value)
		action(a, b, SB);
	stack_print(*a, *b);
}

void	push_from_a_to_b(int count, t_stack **a, t_stack **b, t_var var)
{
	while (count > 0)
	{

		if (var.min == (*a)->value || var.max == (*a)->value || var.mid == (*a)->value)
		{
			if (count == 1)
				break;
			if (var.min == (*a)->prev->value || var.max == (*a)->prev->value || var.mid == (*a)->prev->value)
				action(a, b, RRA);
			else
				action(a, b, RA);
		}
		else
				action(a, b, PB);
		count--;
	}
	lol(a, b, *a, var);
}

void	push_from_a_to_b_mid(int count, t_stack **a, t_stack **b, t_var var)
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

void	justsort(int count, t_stack **a, t_stack **b)
{
	t_score	score;
	t_var	var;

	var.min = stack_get_min(*a)->value;
	var.mid = stack_get_mid(*a)->value;
	var.max = stack_get_max(*a)->value;
	if (count < 10)
		push_from_a_to_b(count, a, b, var);
	else if (count < 300)
		push_from_a_to_b_mid(count, a, b, var);
	else
		chunks(count, a, b, var);
	while (*b != NULL)
	{
		calculate(*a, *b);
		// stack_print(*a, *b);
		recalculate(*b);
		// stack_print(*a, *b);
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
