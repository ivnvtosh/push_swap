/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:14:41 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:14:44 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libst.h"
#include <stddef.h>

void	stack_swap(t_stack *stack)
{
	int	c;

	if (stack == NULL || stack->prev == NULL)
		return ;
	c = stack->prev->value;
	stack->prev->value = stack->value;
	stack->value = c;
}
