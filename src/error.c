/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
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

void	stack_clear(t_stack *stack);

void	error(const char *s, int code)
{
	ft_putstr_fd("\x1b[31m", 1);
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(s, 1);
	ft_putstr_fd("\x1b[0m\n", 1);
	exit(code);
}

void	error_2(t_stack *stack, const char *s)
{
	stack_clear(stack);
	error(s, -2);
}

void	error_3(t_stack *stack_a, t_stack *stack_b, const char *s)
{
	stack_clear(stack_a);
	stack_clear(stack_b);
	error(s, -3);
}
