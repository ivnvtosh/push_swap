/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
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
	t_stack	*start;
	t_stack	*temp;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		ft_exit("Error: memory allocation failure.", -1);
	stack->cell = ft_atoi(*argv++);
	start = stack;
	while (*argv)
	{
		stack->next = (t_stack *)malloc(sizeof(t_stack));
		if (stack->next == NULL)
			stack_clear(start, "Error: memory allocation failure.");
		temp = stack;
		stack = stack->next;
		stack->prev = temp;
		stack->cell = ft_atoi(*argv++);
	}
	stack->next = start;
	start->prev = stack;
	return (start);
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
			ft_exit("Error: please, only numbers.", -1);
		n = ft_atoll(*argv);
		if (n < INT_MIN || n > INT_MAX)
			ft_exit("Error: please, enter a number in the integer range.", -1);
		argv++;
	}
}

void	duplicates(t_stack *stack)
{
	t_stack	*start;
	t_stack	*temp;

	start = stack;
	temp = NULL;
	while (temp != start)
	{
		temp = stack;
		stack = stack->next;
		while (stack != start)
		{
			if (temp->cell == stack->cell)
				stack_clear(start, "Error: enter non-repeating numbers");
			stack = stack->next;
		}
		stack = temp;
		stack = stack->next;
		temp = stack;
	}
}

t_stack	*parser_a(char **argv)
{
	t_stack	*stack;

	check(argv);
	stack = get_stack(argv);
	duplicates(stack);
	return (stack);
}

t_stack	*parser_b(int argc)
{
	t_stack	*stack;
	t_stack	*start;
	t_stack	*temp;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		ft_exit("Error: memory allocation failure.", -1);
	stack->cell = 0;
	start = stack;
	argc -= 1;
	while (argc)
	{
		stack->next = (t_stack *)malloc(sizeof(t_stack));
		if (stack->next == NULL)
			stack_clear(start, "Error: memory allocation failure.");
		temp = stack;
		stack = stack->next;
		stack->prev = temp;
		stack->cell = 0;
		argc -= 1;
	}
	stack->next = start;
	start->prev = stack;
	return (start);
}