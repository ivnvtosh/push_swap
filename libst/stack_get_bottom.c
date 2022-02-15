/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_bottom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:13:27 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:13:28 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libst.h"
#include <stddef.h>

t_stack	*stack_get_bottom(t_stack *stack)
{
	while (stack->prev != NULL)
		stack = stack->prev;
	return (stack);
}
