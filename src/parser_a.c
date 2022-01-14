/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_a.c                                         :+:      :+:    :+:   */
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
void	terminate(t_stack *stack_a, t_stack *stack_b, int code);

t_stack	*get_stack(char **argv)
{
	t_stack	*stack;
	t_stack	*elem_first;
	t_stack	*elem_prev;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		leave(2);
	stack->cell = ft_atoi(*argv++);
	elem_first = stack;
	while (*argv)
	{
		stack->next = (t_stack *)malloc(sizeof(t_stack));
		if (stack->next == NULL)
			terminate(elem_first, NULL, 2);
		elem_prev = stack;
		stack = stack->next;
		stack->prev = elem_prev;
		stack->cell = ft_atoi(*argv++);
	}
	stack->next = elem_first;
	elem_first->prev = stack;
	return (elem_first);
}

void	check(char **argv)
{
	long long	n;
	int			i;

	while (*argv)
	{
		i = 0;
		if ((*argv)[i] == '-')
			i++;
		while (ft_isdigit((*argv)[i]))
			i++;
		if ((*argv)[i])
			leave(1);
		n = ft_atoll(*argv);
		if (n < INT_MIN || n > INT_MAX)
			leave(1);
		argv++;
	}
}

void	duplicates(t_stack *stack)
{
	t_stack	*elem_first;
	t_stack	*elem_prev;

	elem_first = stack;
	while (stack->next != elem_first)
	{
		elem_prev = stack;
		stack = stack->next;
		while (stack != elem_first)
		{
			if (elem_prev->cell == stack->cell)
				terminate(elem_first, NULL, 1);
			stack = stack->next;
		}
		stack = elem_prev->next;
	}
}

void	sorted(t_stack *stack)
{
	t_stack	*elem_first;

	elem_first = stack;
	while (stack->next != elem_first && stack->cell < stack->next->cell)
		stack = stack->next;
	if (stack->next == elem_first)
		terminate(elem_first, NULL, 0);
}

t_stack	*parser_a(char **argv)
{
	t_stack	*stack;

	check(argv);
	stack = get_stack(argv);
	duplicates(stack);
	sorted(stack);
	return (stack);
}
