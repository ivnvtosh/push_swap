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

int	stack_len(t_stack *stack);

void	stack_print(t_stack *stack_a, t_stack *stack_b)
{
	int	a;
	int	b;

	a = stack_len(stack_a);
	b = stack_len(stack_b);
	printf("\x1b[4m         \n");
	while (a > 0 || b > 0)
	{
		if (a-- > 0)
		{
			printf("|%3d|", stack_a->cell);
			stack_a = stack_a->next;
		}
		else
			printf("|   |");
		if (b-- > 0)
		{
			printf("%3d|\n", stack_b->cell);
			stack_b = stack_b->next;
		}
		else
			printf("   |\n");
	}
	printf("| a | b |\n\x1b[0m\n");
}
