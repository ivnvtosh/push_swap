/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:40:00 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/17 15:40:01 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_var
{
	int	min;
	int	mid;
	int	max;
}	t_var;

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
	int	here;

	here = count;
	var.mid = get_mid(*a, count, var);
	while (count > 0)
	{
		if ((*a)->value == var.min || (*a)->value == var.max)
			action(a, b, "ra");
		else if (var.mid < (*a)->value)
		{
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
