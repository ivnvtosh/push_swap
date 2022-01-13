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
	if (stack_a)
		printf("%d ", stack_a->cell);
	else
		printf("  ");
	if (stack_b)
		printf("%d\n", stack_b->cell);
	else
		printf("\n");
}

void	stack_print(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*start;

	printf("\x1b[46m   \x1b[0m\n");
	start = stack_a;
	lol(stack_a, stack_b);
	if (stack_a)
		stack_a = stack_a->next;
	if (stack_b)
		stack_b = stack_b->next;
	while (stack_a != start)
	{
		lol(stack_a, stack_b);
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
	}
	printf("_ _\n");
	printf("a b\n");
	printf("\x1b[46m   \x1b[0m\n");
}
