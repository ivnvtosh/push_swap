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

void	error(const char *s, int code);
void	error_2(t_stack *stack, const char *s);

t_stack	*get_stack(char **argv)
{
	t_stack	*stack;
	t_stack	*elem_first;
	t_stack	*elem_prev;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		error("memory allocation failure.", -2);
	stack->cell = ft_atoi(*argv++);
	elem_first = stack;
	while (*argv)
	{
		stack->next = (t_stack *)malloc(sizeof(t_stack));
		if (stack->next == NULL)
			error_2(elem_first, "memory allocation failure.");
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
			error("enter only numbers.", -1);
		n = ft_atoll(*argv);
		if (n < INT_MIN || n > INT_MAX)
			error("enter a number in the integer range.", -1);
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
				error_2(elem_first, "enter non-repeating numbers.");
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
		error_2(elem_first, "enter an unsorted numbers.");
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
