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
void	action(t_stack **a, t_stack **b, const char *s);
void	print(t_stack *a, t_stack *b);

void	send_in_b(t_stack **a, t_stack **b, int count, t_var var)
{
	while (count > 0)
	{
		if (var.min == (*a)->number || var.max == (*a)->number)
			action(a, b, "ra");
		else
		{
			if (var.mid < (*a)->number)
				action(a, b, "pb");
			else
			{
				action(a, b, "pb");
				if (var.min == (*a)->number || var.max == (*a)->number)
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

// void	search_place(t_stack **a, t_stack **b, t_var var)
// {

// }

void	quicksort(t_stack **a, t_stack **b, int count)
{
	t_var	var;

	var = get_min_mid_max(*a, count);
	send_in_b(a, b, count, var);
	// search_place(a, b, var);
}
