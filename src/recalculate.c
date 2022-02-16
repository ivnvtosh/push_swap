/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recalculate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:47:21 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/16 01:47:23 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest(int a, int b);

typedef struct s_var
{
	int	v1;
	int	v2;
	int	v3;
	int	v4;
}	t_var;

static void	recalculate_one(t_score *score)
{
	(*score).rra = 0;
	(*score).rb = 0;
	(*score).rr = 0;
	(*score).rrr = 0;
}

static void	recalculate_two(t_score *score)
{
	(*score).ra = 0;
	(*score).rrb = 0;
	(*score).rr = 0;
	(*score).rrr = 0;
}

static void	recalculate_three(t_score *score)
{
	(*score).ra -= (*score).rr;
	(*score).rb -= (*score).rr;
	(*score).rra = 0;
	(*score).rrb = 0;
	(*score).rrr = 0;
}

static void	recalculate_four(t_score *score)
{
	(*score).ra = 0;
	(*score).rb = 0;
	(*score).rr = 0;
	(*score).rra -= (*score).rrr;
	(*score).rrb -= (*score).rrr;
}

void	recalculate(t_stack *b)
{
	t_score	score;
	t_var	v;

	while (b != NULL)
	{
		score = b->score;
		v.v1 = score.ra + score.rrb;
		v.v2 = score.rra + score.rb;
		v.v3 = biggest(score.ra, score.rb);
		v.v4 = biggest(score.rra, score.rb);
		if (v.v1 <= v.v2 && v.v1 <= v.v3 && v.v1 <= v.v4)
			recalculate_one(&b->score);
		else if (v.v2 <= v.v1 && v.v2 <= v.v3 && v.v2 <= v.v4)
			recalculate_two(&b->score);
		else if (v.v3 <= v.v1 && v.v3 <= v.v2 && v.v3 <= v.v4)
			recalculate_three(&b->score);
		else if (v.v4 <= v.v1 && v.v4 <= v.v2 && v.v4 <= v.v3)
			recalculate_four(&b->score);
		b = b->prev;
	}
}
