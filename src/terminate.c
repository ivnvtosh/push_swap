/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 05:18:25 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/13 05:18:26 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	clear(t_stack *stack);

void	leave(int code)
{
	if (code)
		ft_putstr_fd("Error\n", 1);
	exit(code);
}

void	terminate(t_stack *stack_a, t_stack *stack_b, int code)
{
	clear(stack_a);
	clear(stack_b);
	leave(code);
}
