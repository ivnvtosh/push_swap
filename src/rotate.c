/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:17:02 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/14 09:17:05 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	rotate(t_stack **stack)
{
	if (*stack == NULL || (*stack) == (*stack)->next)
		return ;
	*stack = (*stack)->next;
}

void	reverse_rotate(t_stack **stack)
{
	if (*stack == NULL || (*stack) == (*stack)->next)
		return ;
	*stack = (*stack)->prev;
}
