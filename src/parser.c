/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 06:31:57 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/13 06:31:58 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

void	leave(int code);
void	terminate(t_stack *a, t_stack *b, int code);

static int	check(t_stack *start, char *numbers)
{
	long long	n;
	int			i;

	i = 0;
	if (numbers[i] == '-')
		i++;
	while (ft_isdigit(numbers[i]))
		i++;
	if (numbers[i])
		terminate(start, NULL, 1);
	n = ft_atoll(numbers);
	if (n < INT_MIN || n > INT_MAX)
		terminate(start, NULL, 1);
	return (n);
}

static t_stack	*check_allocate(char **numbers)
{
	t_stack	*stack;
	t_stack	*start;
	t_stack	*prev;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		leave(2);
	start = stack;
	stack->number = check(start, *numbers++);
	while (*numbers)
	{
		stack->next = (t_stack *)malloc(sizeof(t_stack));
		if (stack->next == NULL)
			terminate(start, NULL, 2);
		prev = stack;
		stack = stack->next;
		stack->prev = prev;
		stack->number = check(start, *numbers++);
	}
	stack->next = start;
	start->prev = stack;
	return (start);
}

static void	duplicates_sorted(t_stack *stack)
{
	t_stack	*start;
	t_stack	*prev;

	start = stack;
	while (stack->next != start)
	{
		prev = stack;
		stack = stack->next;
		while (stack != start)
		{
			if (prev->number == stack->number)
				terminate(start, NULL, 1);
			stack = stack->next;
		}
		stack = prev->next;
	}
	stack = start;
	while (stack->next != start && stack->number < stack->next->number)
		stack = stack->next;
	if (stack->next == start)
		terminate(start, NULL, 0);
}

t_stack	*parser(char **numbers)
{
	t_stack	*stack;

	stack = check_allocate(numbers);
	duplicates_sorted(stack);
	return (stack);
}
