/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:06:45 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/23 21:06:57 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

typedef struct s_var
{
	int	min;
	int	mid;
	int	max;
}	t_var;

t_var	get_min_mid_max(t_stack *stack, int count);
void	action(t_stack **stack_a, t_stack **stack_b, const char *s);
void	print(t_stack *stack_a, t_stack *stack_b);

void	send_in_stack_b(t_stack **stack_a, t_stack **stack_b, int count, t_var var)
{
	while (count > 0)
	{
		if (var.min == (*stack_a)->number || var.max == (*stack_a)->number)
			action(stack_a, stack_b, "ra");
		else
		{
			if (var.mid < (*stack_a)->number)
				action(stack_a, stack_b, "pb");
			else
			{
				action(stack_a, stack_b, "pb");
				if (var.min == (*stack_a)->number || var.max == (*stack_a)->number)
				{
					action(stack_a, stack_b, "rr");
					count--;
				}
				else
					action(stack_a, stack_b, "rb");
			}
		}
		count--;
	}
}

void	quicksort(t_stack **stack_a, t_stack **stack_b, int count)
{
	t_var	var;

	var = get_min_mid_max(*stack_a, count); 
	send_in_stack_b(stack_a, stack_b, count, var);

}
