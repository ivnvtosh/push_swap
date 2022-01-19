/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:58:32 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/19 19:58:34 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	clean(t_stack *stack)
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
	t_stack	*start;
	int		i;

	if (stack == NULL)
		return (0);
	start = stack;
	i = 0;
	while (stack->next != start)
	{
		stack = stack->next;
		i++;
	}
	return (i + 1);
}
