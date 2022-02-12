/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:39:47 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/11 18:39:49 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	action(t_stack **a, t_stack **b, const char *s);

void	apply(t_stack **a, t_stack **b, int count, char *s)
{
	while (count > 0)
	{
		action(a, b, s);
		count--;
	}
}

void    apply_commands(t_stack **a, t_stack **b, t_calc command)
{
    if (command.r.r > 0)
		apply(a, b, command.r.r, "rr");
    if (command.rr.r > 0)
		apply(a, b, command.rr.r, "rrr");
    if (command.r.a > 0)
		apply(a, b, command.r.a, "ra");
    if (command.r.b > 0)
		apply(a, b, command.r.b, "rb");
    if (command.rr.a > 0)
		apply(a, b, command.rr.a, "rra");
    if (command.rr.b > 0)
		apply(a, b, command.rr.b, "rrb");
	action(a, b, "pa");
}
