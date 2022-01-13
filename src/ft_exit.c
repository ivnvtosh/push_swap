/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 05:18:25 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/13 05:18:26 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	ft_exit(const char *s, int code)
{
	ft_putstr_fd("\x1b[31m", 1);
	ft_putstr_fd("Error: ", 1);
	if (code == -1)
		ft_putstr_fd("please, ", 1);
	ft_putstr_fd(s, 1);
	ft_putstr_fd("\x1b[0m\n", 1);
	exit(code);
}

void	stack_clear(t_stack *stack, const char *s)
{
	t_stack	*elem_first;
	t_stack	*elem_prev;

	elem_first = stack;
	elem_prev = stack;
	stack = stack->next;
	free(elem_prev);
	while (stack != elem_first)
	{
		elem_prev = stack;
		stack = stack->next;
		free(elem_prev);
	}
	ft_exit(s, -2);
}
