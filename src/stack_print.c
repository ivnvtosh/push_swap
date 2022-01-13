/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 07:15:49 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/13 07:15:50 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	lol(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->cont)
		printf("%d ", stack_a->cell);
	else
		printf("  ");
	if (stack_b->cont)
		printf("%d\n", stack_b->cell);
	else
		printf("\n");
}

void	stack_print(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*start;

	start = stack_a;
	lol(stack_a, stack_b);
	stack_a = stack_a->next;
	stack_b = stack_b->next;
	while (stack_a != start)
	{
		lol(stack_a, stack_b);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
	}
	printf("_ _\na b\n\n");
}
