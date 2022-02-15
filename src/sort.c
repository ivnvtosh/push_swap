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

void	sort_three(int count, t_stack **a, t_stack **b)
{
	(void)count;
	(void)a;
	(void)b;
}

void	sort_four(int count, t_stack **a, t_stack **b)
{
	(void)count;
	(void)a;
	(void)b;
}

void	sort_five(int count, t_stack **a, t_stack **b)
{
	(void)count;
	(void)a;
	(void)b;
}

void	justsort(int count, t_stack **a, t_stack **b);

void	sort(int count, t_stack **a, t_stack **b)
{
	if (count == 2)
		ft_putstr_fd("sa\n", 1);
	else if (count == 3)
		sort_three(count, a, b);
	else if (count == 4)
		sort_four(count, a, b);
	else if (count == 5)
		sort_five(count, a, b);
	else
		justsort(count, a, b);
	stack_clear(a);
	stack_clear(b);
}
