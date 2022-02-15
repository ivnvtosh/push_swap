/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:50:32 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 20:50:44 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	least(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	biggest(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_score	calculate_one(int count, t_stack *a, t_stack *b, int i)
{
	t_score	score;

	(void)i;
	(void)a;
	(void)b;
	(void)count;
	// score.ra;
	// score.rb;
	score.rr = least(score.ra, score.rb);
	// score.rra;
	// score.rrb;
	// score.rrr = least(score.rra, score.rrb);
	return (score);
}

void	calculate(int count, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	b = b->prev; 
	while (b != NULL)
	{
		b->score = calculate_one(count, a, b, i++);
		b = b->prev;
	}
}
