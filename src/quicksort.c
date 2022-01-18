/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:38:07 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/18 17:38:08 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <limits.h>

void	action(t_stack **stack_a, t_stack **stack_b, const char *s);
int		stacklen(t_stack *stack);
void	print(t_stack *stack_a, t_stack *stack_b);

int	get_pivot(t_stack *stack, int count)
{
	int		pivot;
	int		temp;

	if (stack == NULL)
		return (0);
	if (stack == stack->next)
		return (stack->cell);
	pivot = 0;
	temp = count + 1;
	while (count >= 0)
	{
		pivot += stack->cell;
		stack = stack->next;
		count--;
	}
	pivot /= temp;
	return (pivot);
}

int	polovina(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	pivot;
	int	back;

	back = 0;
	pivot = get_pivot(*stack_a, count);
	while (count >= 0 && *stack_a != (*stack_a)->next->next)
	{
		if (pivot < (*stack_a)->cell)
			action(stack_a, stack_b, "pb");
		else
		{
			action(stack_a, stack_b, "ra");
			back++;
		}
		count--;
	}
	return (back);
}

void	min_back(t_stack **stack_a, t_stack **stack_b, int count)
{
	while (count > 0)
	{
		action(stack_a, stack_b, "rra");
		count--;
	}
}

void	ft_last(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->cell < (*stack_a)->next->cell && (*stack_b)->cell > (*stack_b)->next->cell)
		action(stack_a, stack_b, "ss");
	else
	{
		if ((*stack_a)->cell < (*stack_a)->next->cell)
			action(stack_a, stack_b, "sa");
		if ((*stack_b)->cell > (*stack_b)->next->cell)
			action(stack_a, stack_b, "sb");
	}
	action(stack_a, stack_b, "pa");
	action(stack_a, stack_b, "pa");
}

void	papapapa(t_stack **stack_a, t_stack **stack_b, int count)
{
	while (count > 0)
	{
		action(stack_a, stack_b, "pa");
		count--;
	}
}

void	recursion(t_stack **stack_a, t_stack **stack_b, int degree)
{
	int	back;
	int	copy;

	if (degree < 4)	
		return ;
	copy = degree;
	papapapa(stack_a, stack_b, degree);
	while (degree >= 4)
	{
		back = polovina(stack_a, stack_b, degree);
		min_back(stack_a, stack_b, back);
		degree /= 2;
	}
	ft_last(stack_a, stack_b);
	degree = 4;
	while (degree < copy)
	{
		recursion(stack_a, stack_b, degree);
		degree *= 2;
	}
}

void	lol(t_stack **stack_a, t_stack **stack_b, int degree)
{
	int	copy;

	copy = 4;
	while (copy <= degree)
	{
		recursion(stack_a, stack_b, copy);
		copy *= 2;
	}
}

void	quicksort(t_stack **stack_a, t_stack **stack_b)
{
	int	count;
	int	i;

	i = 1;
	while (*stack_a != (*stack_a)->next->next && *stack_a != (*stack_a)->next)
	{
		count = stacklen(*stack_a);
		polovina(stack_a, stack_b, count);
		i *= 2;
	}
	ft_last(stack_a, stack_b);
	lol(stack_a, stack_b, i);
}
