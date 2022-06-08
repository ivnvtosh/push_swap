/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:11:57 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/21 22:12:08 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_score	get_count_min_or_max(t_stack *a, int count, int search)
{
	t_score	score;
	int		i;

	i = 0;
	while (a->value != search)
	{
		a = a->prev;
		i++;
	}
	score.ra = i;
	score.rra = count - i;
	if (score.ra <= score.rra)
		score.rra = 0;
	else
		score.ra = 0;
	return (score);
}

void	appcomm(t_stack **a, t_stack **b, t_score score)
{
	while (score.ra > 0)
	{
		action(a, b, RA);
		score.ra -= 1;
	}
	while (score.rra > 0)
	{
		action(a, b, RRA);
		score.rra -= 1;
	}
	action(a, b, PB);
}
