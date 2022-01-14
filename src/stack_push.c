/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:19:56 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/14 08:20:02 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	stack_push(t_stack **stack_from, t_stack **stack_in)
{
	t_stack	*elem;

	elem = *stack_from;
	if (elem == NULL)
		return ;
	if (elem == elem->next)
		*stack_from = NULL;
	else
	{
		(*stack_from)->next->prev = (*stack_from)->prev;
		(*stack_from)->prev->next = (*stack_from)->next;
		(*stack_from) = (*stack_from)->next;
	}
	if (*stack_in == NULL)
	{
		elem->next = elem;
		elem->prev = elem;
	}
	else if ((*stack_in)->next == NULL)
	{
		elem->next = *stack_in;
		elem->prev = *stack_in;
		(*stack_in)->next = elem;
		(*stack_in)->prev = elem;
	}
	else
	{
		elem->next = *stack_in;
		elem->prev = (*stack_in)->prev;
		(*stack_in)->prev->next = elem;
		(*stack_in)->prev = elem;
	}
	*stack_in = elem;
}
