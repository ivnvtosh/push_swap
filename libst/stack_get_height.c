/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:13:35 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:13:38 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libst.h"
#include <stddef.h>

int	stack_get_height(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->prev;
		i += 1;
	}
	return (i);
}
