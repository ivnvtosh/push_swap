/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:10:24 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:10:28 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_swap(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
		stack_swap(*a);
	else if (c == 'b')
		stack_swap(*b);
	else if (c == 's')
	{
		stack_swap(*a);
		stack_swap(*b);
	}
}

static void	check_push(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
		stack_push(b, a);
	else if (c == 'b')
		stack_push(a, b);
}

static void	check_rotate(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
		stack_rotate(a);
	else if (c == 'b')
		stack_rotate(b);
	else if (c == 'r')
	{
		stack_rotate(a);
		stack_rotate(b);
	}
}

static void	check_reverse_rotate(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
		stack_reverce_rotate(a);
	else if (c == 'b')
		stack_reverce_rotate(b);
	else if (c == 'r')
	{
		stack_reverce_rotate(a);
		stack_reverce_rotate(b);
	}
}

void	action(t_stack **a, t_stack **b, const char *command)
{
	ft_putendl_fd(command, 1);
	if (*command == 's')
		check_swap(a, b, *(command + 1));
	else if (*command == 'p')
		check_push(a, b, *(command + 1));
	else if (*command == 'r' && *(command + 2) == '\0')
		check_rotate(a, b, *(command + 1));
	else if (*command == 'r')
		check_reverse_rotate(a, b, *(command + 2));
}
