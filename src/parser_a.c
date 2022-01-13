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

void	ft_exit(const char *s, int code);
void	stack_clear(t_stack *stack, const char *s);

t_stack	*get_stack(char **argv)
{
	t_stack	*stack;
	t_stack	*elem_first;
	t_stack	*elem_prev;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		ft_exit("memory allocation failure.", -2);
	stack->cell = ft_atoi(*argv++);
	elem_first = stack;
	while (*argv)
	{
		stack->next = (t_stack *)malloc(sizeof(t_stack));
		if (stack->next == NULL)
			stack_clear(elem_first, "memory allocation failure.");
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
			ft_exit("enter only numbers.", -1);
		n = ft_atoll(*argv);
		if (n < INT_MIN || n > INT_MAX)
			ft_exit("enter a number in the integer range.", -1);
		argv++;
	}
}

void	duplicates(t_stack *stack)
{
	t_stack	*elem_first;
	t_stack	*elem_prev;

	elem_first = stack;
	elem_prev = NULL;
	while (elem_prev != elem_first)
	{
		elem_prev = stack;
		stack = stack->next;
		while (stack != elem_first)
		{
			if (elem_prev->cell == stack->cell)
				stack_clear(elem_first, "enter non-repeating numbers.");
			stack = stack->next;
		}
		stack = elem_prev->next;
	}
}

void	sorted(t_stack *stack)
{
	t_stack	*elem_first;
	t_stack	*elem_next;

	elem_first = stack;
	elem_next = stack->next;
	while (elem_next != elem_first && stack->cell < elem_next->cell)
	{
		stack = stack->next;
		elem_next = elem_next->next;
	}
	if (elem_next == elem_first)
		ft_exit("enter an unsorted numbers.", -1);
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
