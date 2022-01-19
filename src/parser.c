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
void	terminate(t_stack *stack_a, t_stack *stack_b, int code);

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

t_stack	*stack_allocate(char **argv)
{
	t_stack	*stack;
	t_stack	*start;
	t_stack	*prev;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		leave(2);
	stack->number = ft_atoi(*argv++);
	start = stack;
	while (*argv)
	{
		stack->next = (t_stack *)malloc(sizeof(t_stack));
		if (stack->next == NULL)
			terminate(start, NULL, 2);
		prev = stack;
		stack = stack->next;
		stack->prev = prev;
		stack->number = ft_atoi(*argv++);
	}
	stack->next = start;
	start->prev = stack;
	return (start);
}

void	duplicates_sorted(t_stack *stack)
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

t_stack	*get_stack(char **argv)
{
	t_stack	*stack;

	check(argv);
	stack = stack_allocate(argv);
	duplicates_sorted(stack);
	return (stack);
}

t_stack	*parser(int *count, char **numbers)
{
	t_stack	*stack;
	char	**temp;
	int		i;

	if (*count == 1)
	{
		temp = ft_split(*numbers, 32);
		if (temp == NULL)
			leave(2);
		if (temp[1] == NULL)
		{
			free(*temp);
			free(temp);
			leave(1);
		}
		stack = get_stack(temp);
		i = 0;
		while (temp[i])
			free(temp[i++]);
		free(temp);
		*count = i;
	}
	else
		stack = get_stack(numbers);
	return (stack);
}
