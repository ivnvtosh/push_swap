/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:11:58 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:11:59 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_var
{
	int	min;
	int	mid;
	int	max;
}	t_var;

void	sort_three(t_stack **a, t_stack **b)
{
	int	min;
	int	max;

	min = stack_get_min(*a)->value;
	max = stack_get_max(*a)->value;
	if ((*a)->value == min && (*a)->prev->value == max)
		action(a, b, SA);
	if ((*a)->value == max && \
		(*a)->prev->value != min && (*a)->prev->value != max)
		action(a, b, SA);
	if ((*a)->value != min && (*a)->value != max && (*a)->prev->value == min)
		action(a, b, SA);
	if ((*a)->value != min && (*a)->value != max && (*a)->prev->value == max)
		action(a, b, RRA);
	if ((*a)->value == max && (*a)->prev->value == min)
		action(a, b, RA);
}

t_score	get_count_min_or_max(t_stack *a, int count, int search);
void	appcomm(t_stack **a, t_stack **b, t_score score);

void	sort_four(t_stack **a, t_stack **b)
{
	t_score	min;
	t_score	max;

	min = get_count_min_or_max(*a, 4, 0);
	max = get_count_min_or_max(*a, 4, 3);
	if (min.ra + min.rra <= max.ra + max.rra)
		appcomm(a, b, min);
	else
		appcomm(a, b, max);
	sort_three(a, b);
	action(a, b, PA);
	if ((*a)->value > (*a)->prev->value)
		action(a, b, RA);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_score	min;
	t_score	max;

	min = get_count_min_or_max(*a, 5, 0);
	max = get_count_min_or_max(*a, 5, 4);
	if (min.ra + min.rra <= max.ra + max.rra)
	{
		appcomm(a, b, min);
		max = get_count_min_or_max(*a, 4, 4);
		appcomm(a, b, max);
	}
	else
	{
		appcomm(a, b, max);
		min = get_count_min_or_max(*a, 4, 0);
		appcomm(a, b, min);
	}
	sort_three(a, b);
	action(a, b, PA);
	action(a, b, PA);
	if ((*a)->value < (*a)->prev->value)
		action(a, b, SA);
	action(a, b, RA);
}

void	justsort(int count, t_stack **a, t_stack **b);

void	sort(int count, t_stack **a, t_stack **b)
{
	if (count == 2)
		action(a, b, SA);
	else if (count == 3)
		sort_three(a, b);
	else if (count == 4)
		sort_four(a, b);
	else if (count == 5)
		sort_five(a, b);
	else
		justsort(count, a, b);
	stack_clear(a);
	stack_clear(b);
}
