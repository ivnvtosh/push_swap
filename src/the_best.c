/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_best.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:33:04 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/11 18:33:07 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include <limits.h>

int command_sum(t_calc calc)
{
    return (calc.r.a + calc.r.b + calc.rr.a + calc.rr.b);
}

t_calc	the_best(t_stack *b, int count)
{
    t_calc  command;
    int	    i;

	i = 0;
    command.r.a = INT_MAX;
	b = b->prev;
	while (count > 0)
	{
		if (command_sum(b->calc) < command_sum(command))
            command = b->calc;
		b = b->prev;
		count--;
	}
    return (command);
}
