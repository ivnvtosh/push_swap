/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_mid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:13:57 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:14:01 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libst.h"
#include <stddef.h>

t_stack	*stack_get_mid(t_stack *stack)
{
	t_stack	*top;
	int		mid;

	top = stack;
	mid = 0;
	while (stack != NULL)
	{
		mid += stack->value;
		stack = stack->prev;
	}
	mid /= stack_get_height(top);
	stack = top;
	while (stack->value != mid)
		stack = stack->prev;
	return (stack);
}
