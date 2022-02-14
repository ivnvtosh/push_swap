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

typedef struct s_var
{
	unsigned int	min;
	unsigned int	mid;
	unsigned int	max;
}	t_var;

int command_sum(t_calc calc)
{
	int	sum_r;
	int	sum_rr;

	sum_r = calc.r.a + calc.r.b + calc.r.r;
	sum_rr = calc.rr.a + calc.rr.b + calc.rr.r;
    return (sum_r + sum_rr);
}

t_calc	search_best(t_stack *b, int count, t_var var)
{
    t_calc  command;

	(void)var;
	b = b->prev;
	command = b->calc;
	// printf("%2d   ",       b->index);
	// printf ("ra - %2d, ",  b->calc.r.a);
	// printf("rra - %2d   ", b->calc.rr.a);
	// printf ("rb - %2d, ",  b->calc.r.b);
	// printf("rrb - %2d   ", b->calc.rr.b);
	// printf ("rr - %2d, ",  b->calc.r.r);
	// printf("rrr - %2d\n",  b->calc.rr.r);
	// command.r.a = 100;
	// command.r.b = 100;
	// command.r.r = 100;
	// command.rr.a = 100;
	// command.rr.b = 100;
	// command.rr.r = 100;
	b = b->prev;
	while (count > 2)
	{
		// printf("%2d   ",       b->index);
		// printf ("ra - %2d, ",  b->calc.r.a);
		// printf("rra - %2d   ", b->calc.rr.a);
		// printf ("rb - %2d, ",  b->calc.r.b);
		// printf("rrb - %2d   ", b->calc.rr.b);
		// printf ("rr - %2d, ",  b->calc.r.r);
		// printf("rrr - %2d\n",  b->calc.rr.r);
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
