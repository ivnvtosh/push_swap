/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:06:52 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/28 17:06:53 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

static int	get_min(t_stack *stack, int count)
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
static int	get_next(t_stack *stack, int count, int find)
{
	int	var;

	var = INT_MAX;
	while (count > 0)
	{
		if (var > stack->number && find < stack->number)
			var = stack->number;
		stack = stack->next;
		count--;
	}
	return (var);
}

void	add_index(t_stack *stack, int count)
{
	int	find;
	int	i;

	find = get_min(stack, count);
	i = 0;
	while (i != count)
	{
		if (stack->number == find)
		{
			find = get_next(stack, count, find);
			stack->index = i++;
		}
		stack = stack->next;
	}
}
