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

typedef struct s_var
{
	unsigned int	min;
	unsigned int	mid;
	unsigned int	max;
}	t_var;

void	action(t_stack **a, t_stack **b, const char *s);

static unsigned int	get_mid(t_stack *stack, int count, t_var var)
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
		if (stack->index != var.min && stack->index != var.max)
			mid += stack->index;
		stack = stack->next;
		count--;
	}
	mid /= tmp;
	return (mid);
}

static int	chunk(t_stack **a, t_stack **b, int count, t_var var)
{
	unsigned int here;
    unsigned int mid;

	here = count;
    mid = get_mid(*a, count, var);
	while (count > 0)
	{
		if ((*a)->index == var.min || (*a)->index == var.max)
			action(a, b, "ra");
		else if (mid < (*a)->index)
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

// static void	last(t_stack **a, t_stack **b)
// {
// 	// if ((*a)->index > (*a)->next->index && (*b)->index < (*b)->next->index)
// 	// 	action(a, b, "ss");
// 	// else
// 	// {
// 		if ((*a)->index < (*a)->next->index)
// 			action(a, b, "sa");
// 		if ((*b)->index > (*b)->next->index)
// 			action(a, b, "sb");
// 	// }
// 	action(a, b, "pb");
// 	action(a, b, "pb");
// 	action(a, b, "rrb");
// 	action(a, b, "rrb"); 
// 	action(a, b, "pa");
// 	action(a, b, "pa");
// }

void	chunks(t_stack **a, t_stack **b, int count, t_var var)
{
	int	here;

	if (count <= 2)
		return ;
	here = chunk(a, b, count, var);
	chunks(a, b, here, var);
}
