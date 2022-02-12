/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:26:58 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/11 15:27:00 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	action(t_stack **a, t_stack **b, const char *s);

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

static int	chunk(t_stack **a, t_stack **b, int count)
{
	unsigned int here;
    unsigned int mid;

	here = count;
    mid = get_mid(*a, count);
	while (count > 0)
	{
		if (mid < (*a)->index)
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

static void	last(t_stack **a, t_stack **b)
{
	// if ((*a)->index > (*a)->next->index && (*b)->index < (*b)->next->index)
	// 	action(a, b, "ss");
	// else
	// {
		if ((*a)->index < (*a)->next->index)
			action(a, b, "sa");
		if ((*b)->index > (*b)->next->index)
			action(a, b, "sb");
	// }
	action(a, b, "pb");
	action(a, b, "pb");
	action(a, b, "rrb");
	action(a, b, "rrb"); 
	action(a, b, "pa");
	action(a, b, "pa");

}

void	chunks(t_stack **a, t_stack **b, int count)
{
	int	here;

	if (count <= 2)
		return last(a, b);
	here = chunk(a, b, count);
	chunks(a, b, here);
}
