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
#include <limits.h>

void	action(t_stack **a, t_stack **b, const char *s);

void    apply_commands(t_stack *a, t_stack *b, t_calc command)
{
    while (command.r.r)
    {
		action(a, b, "rr");
        command.r.r--;
    }
    while (command.rr.r)
    {
		action(a, b, "rrr");
        command.rr.r--;
    }
    while (command.r.a)
    {
		action(a, b, "ra");
        command.r.a--;
    }
    while (command.r.b)
    {
		action(a, b, "rb");
        command.r.b--;
    }
     while (command.rr.a)
    {
		action(a, b, "rra");
        command.rr.a--;
    }
    while (command.rr.b)
    {
		action(a, b, "rrb");
        command.rr.b--;
    }
}
