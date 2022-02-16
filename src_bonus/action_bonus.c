/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:45:08 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/16 18:45:09 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	action(t_stack **a, t_stack **b, const char *comm)
{
	ft_putendl_fd(comm, 1);
	if (*comm == 's')
		check_swap(a, b, *(comm + 1));
	else if (*comm == 'p')
		check_push(a, b, *(comm + 1));
	else if (*comm == 'r' && *(comm + 2) == '\n')
		check_rotate(a, b, *(comm + 1));
	else if (*comm == 'r')
		check_reverse_rotate(a, b, *(comm + 2));
}
