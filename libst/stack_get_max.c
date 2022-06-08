/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:13:47 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:13:49 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libst.h"
#include <stddef.h>

t_stack	*stack_get_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack != NULL)
	{
		if (stack->value > max->value)
			max = stack;
		stack = stack->prev;
	}
	return (max);
}
