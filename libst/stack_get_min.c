/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:14:08 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:14:09 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libst.h"
#include <stddef.h>

t_stack	*stack_get_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack != NULL)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->prev;
	}
	return (min);
}
