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

void	push_from_a_to_b(int count, t_stack **a, t_stack **b)
{
	int	min;
	int	mid;
	int	max;

	min = stack_get_min(*a)->value;
	mid = stack_get_mid(*a)->value;
	max = stack_get_max(*a)->value;
	while (count > 0)
	{
		if (min == (*a)->value || max == (*a)->value || mid == (*a)->value)
			action(a, b, "ra");
		else
		{
			if (mid < (*a)->value)
				action(a, b, "pb");
			else
			{
				action(a, b, "pb");
				if (min == (*a)->value || max == (*a)->value)
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
}

void	calculate(int count, t_stack *a, t_stack *b);

void	justsort(int count, t_stack **a, t_stack **b)
{
	push_from_a_to_b(count, a, b);
	calculate(count, *a, *b);
	stack_print(*a, *b);
}
