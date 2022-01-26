/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:18:39 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/26 19:18:40 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../libft/libft.h"

void	swap(t_stack *stack)
{
	if (stack == NULL || stack == stack->next)
		return ;
	ft_swap(&stack->number, &stack->next->number);
}
