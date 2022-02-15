/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:13:16 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:13:18 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libst.h"
#include <stdlib.h>

t_stack	*stack_duplicate(t_stack *stack)
{
	t_stack	*dup;
	t_stack	*bottom;

	dup = NULL;
	while (stack != NULL)
	{
		bottom = stack_get_new(stack->value);
		if (bottom == NULL)
		{
			stack_clear(&dup);
			return (NULL);
		}
		stack_add_bottom(&dup, bottom);
		stack = stack->prev;
	}
	return (dup);
}
