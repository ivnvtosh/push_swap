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
	unsigned int	min;
	unsigned int	mid;
	unsigned int	max;
}	t_var;

static unsigned int	get_min(t_stack *stack, int count)
{
	unsigned int	min;

	if (stack == NULL)
		return (0);
	if (stack == stack->next)
		return (stack->index);
	min = INT_MAX;
	while (count > 0)
	{
		if (min > stack->index)
			min = stack->index;
		stack = stack->next;
		count--;
	}
	return (min);
}

static unsigned int	get_mid(t_stack *stack, int count)
{
	unsigned int	mid;
	unsigned int	tmp;

	if (stack == NULL)
		return (0);
	if (stack == stack->next)
		return (stack->index);
	mid = 0;
	tmp = count;
	while (count > 0)
	{
		mid += stack->index;
		stack = stack->next;
		count--;
	}
	mid /= tmp;
	return (mid);
}

static unsigned int	get_max(t_stack *stack, int count)
{
	unsigned int	max;

	if (stack == NULL)
		return (0);
	if (stack == stack->next)
		return (stack->index);
	max = 0;
	while (count > 0)
	{
		if (max < stack->index)
			max = stack->index;
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
	return (var);
}
