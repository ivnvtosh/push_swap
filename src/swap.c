/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:19:12 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/14 08:20:23 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	swap(t_stack *stack)
{
	if (stack == NULL || stack == stack->next)
		return ;
	ft_swap(&stack->number, &stack->next->number);
}
