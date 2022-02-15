/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:14:36 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:14:37 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libst.h"
#include <stddef.h>

void	stack_rotate(t_stack **stack)
{
	t_stack	*top;

	stack_get_bottom(*stack)->prev = *stack;
	top = (*stack)->prev;
	(*stack)->prev = NULL;
	*stack = top;
}

void	stack_reverce_rotate(t_stack **stack)
{
	t_stack	*top;

	top = stack_get_bottom(*stack);
	top->prev = *stack;
	*stack = top;
	while (top->prev != *stack)
		top = top->prev;
	top->prev = NULL;
}
