/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_best.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:57:36 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/16 01:57:41 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	score_sum(t_score score)
{
	int	r;
	int	rr;

	r = score.ra + score.rb + score.rr;
	rr = score.rra + score.rrb + score.rrr;
	return (r + rr);
}

t_score	search_best(t_stack *b)
{
	t_score	score;

	score = b->score;
	b = b->prev;
	while (b != NULL)
	{
		if (score_sum(b->score) < score_sum(score))
			score = b->score;
		b = b->prev;
	}
	return (score);
}
