/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_indexes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:10:47 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:10:50 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdlib.h>

typedef struct s_top
{
	t_stack	*stack;
	t_stack	*dup;
}	t_top;

typedef struct s_data
{
	t_stack	*dup;
	t_top	top;
	int		height;
	int		find;
	int		index;
}	t_data;

static t_data	get_data(t_stack *stack)
{
	t_data	data;

	data.dup = stack_duplicate(stack);
	if (data.dup == NULL)
		exit(MALLOC);
	data.top.dup = data.dup;
	data.top.stack = stack;
	data.find = stack_get_min(stack)->value;
	data.height = stack_get_height(stack);
	data.index = 0;
	return (data);
}

static int	get_next_find(t_stack *dup, int prev)
{
	int	find;

	find = __INT_MAX__;
	while (dup != NULL)
	{
		if (find > dup->value && prev < dup->value)
			find = dup->value;
		dup = dup->prev;
	}
	return (find);
}

void	convert_to_indexes(t_stack *stack)
{
	t_data	data;

	data = get_data(stack);
	while (data.index != data.height)
	{
		if (data.find == data.dup->value)
		{
			stack->value = data.index++;
			data.find = get_next_find(data.top.dup, data.find);
		}
		stack = stack->prev;
		data.dup = data.dup->prev;
		if (stack == NULL)
		{
			stack = data.top.stack;
			data.dup = data.top.dup;
		}
	}
	stack_clear(&data.top.dup);
}
