/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:18:32 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/26 19:18:33 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../libft/libft.h"

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
