/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:19:43 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/14 08:19:47 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	stack_clear(t_stack *stack)
{
	if (stack == NULL)
		return ;
	if (stack->prev)
		stack->prev->next = NULL;
	while (stack->next)
	{
		stack = stack->next;
		free(stack->prev);
	}
	free(stack);
}

int	stack_len(t_stack *stack)
{
	t_stack	*elem_first;
	int		i;

	if (stack == NULL)
		return (0);
	if (stack == stack->next)
		return (1);
	elem_first = stack;
	i = 0;
	while (stack->next != elem_first)
	{
		stack = stack->next;
		i++;
	}
	return (++i);
}
