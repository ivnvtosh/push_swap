/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_comm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:55:12 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/16 01:55:18 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply(t_stack **a, t_stack **b, int count, char *s)
{
	while (count > 0)
	{
		action(a, b, s);
		count--;
	}
}

void	apply_comm(t_stack **a, t_stack **b, t_score score)
{
	if (score.rr > 0)
		apply(a, b, score.rr, RR);
	if (score.rrr > 0)
		apply(a, b, score.rrr, RRR);
	if (score.ra > 0)
		apply(a, b, score.ra, RA);
	if (score.rb > 0)
		apply(a, b, score.rb, RB);
	if (score.rra > 0)
		apply(a, b, score.rra, RRA);
	if (score.rrb > 0)
		apply(a, b, score.rrb, RRB);
	action(a, b, "pa");
}
