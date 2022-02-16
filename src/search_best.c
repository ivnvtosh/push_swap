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

static int	get_mid(t_stack *b)
{
	int	mid;

	mid = -1;
	while (b != NULL)
	{
		if (mid < b->mid)
			mid = b->mid;
		b = b->prev;
	}
	return (mid);
}

// t_score	search_best(t_stack *b)
// {
// 	t_score	score;
// 	int		mid;

// 	// score = b->score;
// 	// b = b->prev;
// 	score.ra = 100;
// 	score.rb = 100;
// 	score.rr = 100;
// 	score.rra = 100;
// 	score.rrb = 100;
// 	score.rrr = 100;
// 	mid = get_mid(b);
// 	while (b != NULL)
// 	{
// 		if (score_sum(b->score) < score_sum(score) && b->mid == mid)
// 			score = b->score;
// 		b = b->prev;
// 	}
// 	return (score);
// }

t_score	search_best(t_stack *b)
{
	t_score	score;
	int		mid;

	score = b->score;
	b = b->prev;
	mid = get_mid(b);
	while (b != NULL)
	{
		if (score_sum(b->score) < score_sum(score))
			score = b->score;
		b = b->prev;
	}
	return (score);
}
