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

int command_sum(t_calc calc)
{
	int	sum_r;
	int	sum_rr;

	sum_r = calc.r.a + calc.r.b + calc.r.r;
	sum_rr = calc.rr.a + calc.rr.b + calc.rr.r;
    return (sum_r + sum_rr);
}

t_calc	the_best(t_stack *b, int count)
{
    t_calc  command;

	command = b->prev->calc;
	b = b->prev->prev;
	while (count > 1)
	{
		if (command_sum(b->calc) < command_sum(command))
            command = b->calc;
		b = b->prev;
		count--;
	}
	// printf("command\n");
	// printf("ra - %d\n", command.r.a);
	// printf("rb - %d\n", command.r.b);
	// printf("rr - %d\n\n", command.r.r);
	// printf("rra - %d\n", command.rr.a);
	// printf("rrb - %d\n", command.rr.b);
	// printf("rrr - %d\n\n", command.rr.r);
    return (command);
}
