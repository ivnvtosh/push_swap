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
	unsigned int	min;
	unsigned int	mid;
	unsigned int	max;
}	t_var;

t_var	get_min_mid_max(t_stack *stack, int count);
void	action(t_stack **a, t_stack **b, const char *s);
void	print(t_stack *a, t_stack *b);

static void	send_from_a_to_b(t_stack **a, t_stack **b, int count, t_var var)
{
	while (count > 0)
	{
		if (var.min == (*a)->index || var.max == (*a)->index)
			action(a, b, "ra");
		else
		{
			if (var.mid < (*a)->index)
				action(a, b, "pb");
			else
			{
				action(a, b, "pb");
				if (var.min == (*a)->index || var.max == (*a)->index)
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
	send_from_a_to_b(a, b, count, var);
	// search_place(a, b, var);
}
