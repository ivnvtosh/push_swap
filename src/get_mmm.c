/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mmm.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:33:23 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/23 21:33:26 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

typedef struct s_var
{
	int	min;
	int	mid;
	int	max;
}	t_var;

int	get_min(t_stack *stack, int count)
{
	int	min;

	if (stack == NULL)
		return (0);
	if (stack == stack->next)
		return (stack->number);
	min = INT_MAX;
	while (count > 0)
	{
		if (min > stack->number)
			min = stack->number;
		stack = stack->next;
		count--;
	}
	return (min);
}

int	get_mid(t_stack *stack, int count)
{
	int	mid;
	int	tmp;

	if (stack == NULL)
		return (0);
	if (stack == stack->next)
		return (stack->number);
	mid = 0;
	tmp = count;
	while (count > 0)
	{
		mid += stack->number;
		stack = stack->next;
		count--;
	}
	mid /= tmp;
	return (mid);
}

int	get_max(t_stack *stack, int count)
{
	int	max;

	if (stack == NULL)
		return (0);
	if (stack == stack->next)
		return (stack->number);
	max = INT_MIN;
	while (count > 0)
	{
		if (max < stack->number)
			max = stack->number;
		stack = stack->next;
		count--;
	}
	return (max);
}

t_var	get_min_mid_max(t_stack *stack, int count)
{
	t_var	var;

	var.min = get_min(stack, count);
	var.mid = get_mid(stack, count);
	var.max = get_max(stack, count);
	// printf("min = %d\n", var.min);
	// printf("mid = %d\n", var.mid);
	// printf("max = %d\n", var.max);
	return (var);
}

void	action(t_stack **stack_a, t_stack **stack_b, const char *s);

int	polovina(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	up;
	int	mid;

	up = 0;
	mid = get_mid(*stack_a, count);
	while (count > 0)
	{
		if (mid >= (*stack_a)->number)
		{
			action(stack_a, stack_b, "pb");
		}
		else
		{
			action(stack_a, stack_b, "ra");
			up++;
		}
		count--;
	}
	return (up);
}
