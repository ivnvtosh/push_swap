/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:12:50 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:12:53 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libst.h"
#include <stdlib.h>

void	stack_clear(t_stack **stack)
{
	t_stack	*top;

	while (*stack)
	{
		top = *stack;
		*stack = (*stack)->prev;
		stack_delone(top);
	}
	*stack = NULL;
}
