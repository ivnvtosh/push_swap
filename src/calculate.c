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

int	least(int a, int b);
int	biggest(int a, int b);

int	calculate_ra(t_stack *a, t_stack *b)
{
	t_stack	*top;
	int		i;

	i = 0;
	top = a;
	while (a->prev != NULL)
	{
		if (a->value < b->value && a->prev->value > b->value)
			return (++i);
		a = a->prev;
		i++;
	}
	a = top;
	while (a->prev != NULL)
	{
		if (a->value < b->value && a->prev->value > b->value)
			return (i);
		a = a->prev;
		i++;
	}
	return (i);
}

t_score	calculate_one(int count, t_stack *a, t_stack *b, int i)
{
	t_score	score;

	score.ra = calculate_ra(a, b);
	score.rb = i;
	score.rra = stack_get_height(a) - score.ra;
	if (score.ra > stack_get_height(a))
	{
		score.ra = 0;
		score.rra = 0;
	}
	if (i == 0)
		score.rrb = 0;
	else
		score.rrb = count - i;
	score.rr = least(score.ra, score.rb);
	score.rrr = least(score.rra, score.rrb);
	return (score);
}

void	calculate(t_stack *a, t_stack *b)
{
	int		count;
	int		i;

	count = stack_get_height(b);
	i = 0;
	while (b != NULL)
	{
		b->score = calculate_one(count, a, b, i++);
		b = b->prev;
	}
}
