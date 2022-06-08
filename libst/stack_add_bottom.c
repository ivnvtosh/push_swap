/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_bottom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:12:37 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:12:39 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libst.h"
#include <stddef.h>

void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
		*stack = new;
	else
		stack_get_bottom(*stack)->prev = new;
}
