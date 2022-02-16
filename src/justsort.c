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

// void	push_from_a_to_b(int count, t_stack **a, t_stack **b)
// {
// 	int	min;
// 	int	mid;
// 	int	max;

// 	min = stack_get_min(*a)->value;
// 	mid = stack_get_mid(*a)->value;
// 	max = stack_get_max(*a)->value;
// 	while (count > 0)
// 	{
// 		if (min == (*a)->value || max == (*a)->value)
// 			action(a, b, "ra");
// 		else
// 		{
// 			if (mid < (*a)->value)
// 				action(a, b, "pb");
// 			else
// 			{
// 				action(a, b, "pb");
// 				if (min == (*a)->value || max == (*a)->value)
// 				{
// 					action(a, b, "rr");
// 					count--;
// 				}
// 				else
// 					action(a, b, "rb");
// 			}
// 		}
// 		count--;
// 	}
// }

void	calculate(t_stack *a, t_stack *b);
void	recalculate(t_stack *b);
t_score	search_best(t_stack *b);
void	apply_comm(t_stack **a, t_stack **b, t_score score);

typedef struct s_var
{
	int	min;
	int	mid;
	int	max;
}	t_var;

void	action(t_stack **a, t_stack **b, const char *s);

static int	get_mid(t_stack *stack, int count, t_var var)
{
	int	mid;
	int	tmp;

	mid = 0;
	tmp = count;
	while (count > 0)
	{
		if (stack->value != var.min && stack->value != var.max)
			mid += stack->value;
		stack = stack->prev;
		count--;
	}
	mid /= tmp;
	return (mid);
}

static int	chunk(t_stack **a, t_stack **b, int count, t_var var)
{
	int here;
    int mid;

	here = count;
    mid = get_mid(*a, count, var);
	while (count > 0)
	{
		if ((*a)->value == var.min || (*a)->value == var.max)
			action(a, b, "ra");
		else if (mid < (*a)->value)
		{
			(*a)->mid = mid;
			action(a, b, "pb");
			here--;
		}
		else
			action(a, b, "ra");
		count--;
	}
	return (here);
}

void	chunks(t_stack **a, t_stack **b, int count, t_var var)
{
	int	here;

	if (count <= 2)
		return ;
	here = chunk(a, b, count, var);
	chunks(a, b, here, var);
}

void	justsort(int count, t_stack **a, t_stack **b)
{
	t_score	score;
	t_var	var;

	var.min = stack_get_min(*a)->value;
	var.mid = stack_get_mid(*a)->value;
	var.max = stack_get_max(*a)->value;
	chunks(a, b, count, var);
	// push_from_a_to_b(count, a, b);
	
	while (*b != NULL)
	{
		calculate(*a, *b);
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
