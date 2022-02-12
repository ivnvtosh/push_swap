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

void	chunks(t_stack **a, t_stack **b, int count);
void	calculate(t_stack *a, t_stack *b, int count);
t_calc	the_best(t_stack *b, int count);
void    apply_commands(t_stack **a, t_stack **b, t_calc command);
void	action(t_stack **a, t_stack **b, const char *s);

void	search(t_stack **a, t_stack **b, unsigned int count)
{
	count -= 2;
	while (count > 0)
	{
		if ((*a)->index < (*b)->index)
		{
			while ((*a)->index < (*b)->index)
			{
				action(a, b, "ra");
				if ((*a)->index < (*a)->prev->index)
					break ;
			}
		}
		else
		{
			while ((*a)->prev->index > (*b)->index)
			{
				if ((*a)->index < (*a)->prev->index)
					break ;
				action(a, b, "rra");
			}
		}
		action(a, b, "pa");
		action(a, b, "rrb");
		count--;
	}
}

void	quicksort(t_stack **a, t_stack **b, int count)
{
	t_calc	calc;

	chunks(a, b, count);
	calculate(*a, *b, count);


	print(*a, *b);
	calc = the_best(*b, count / 2 - 2);
	apply_commands(a, b, calc);
	print(*a, *b);


	// search(a, b, count);
}
