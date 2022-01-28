/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
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

int     get_min(t_stack *stack, int count);
void	terminate(t_stack *a, t_stack *b, int code);

static int	get_next(t_stack *stack, int count, int find)
{
	int	min;

	min = INT_MAX;
	while (count > 0)
	{
		if (min > stack->number && find < stack->number)
			min = stack->number;
		stack = stack->next;
		count--;
	}
	return (min);
}

void	replace(t_stack *stack, int count)
{
	t_stack	*start;
	int		*index;
	int		find;
	int		i;
	int		j;

	index = (int *)malloc(sizeof(int *) * (count));
	if (index == NULL)
		terminate(stack, NULL, 2);
	find = get_min(stack, count);
	i = 0;
	j = 0;
	start = stack;
	while (j != count)
	{
		if (stack->number == find)
		{
			find = get_next(stack, count, find);
			index[i] = j + 1;
			j++;
		}
		stack = stack->next;
		i++;
		if (i == count)
			i = 0;
	}
	stack = start;
	i = 0;
	while (i != count)
	{
		stack->number = index[i++];
		stack = stack->next;
	}
	free(index);
}
