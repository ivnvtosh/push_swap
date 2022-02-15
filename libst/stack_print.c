/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:14:22 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:14:23 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libst.h"
#include <stdio.h>

void	stack_print_one(t_stack *stack)
{
	printf("\x1b[4m     \n");
	if (stack == NULL)
		printf("|nil|\n");
	while (stack != NULL)
	{
		printf("|%3d|\n", stack->value);
		stack = stack->prev;
	}
	printf("\x1b[0m\n");
}

static void	print(t_stack *b, t_score score)
{
	printf("%3d|\n", b->value);
}

void	stack_print(t_stack *a, t_stack *b)
{
	printf("\x1b[4m         \n");
	while (a != NULL || b != NULL)
	{
		if (a != NULL)
		{
			printf("|%3d|", a->value);
			a = a->prev;
		}
		else
			printf("|   |");
		if (b != NULL)
		{
			print(b, b->score);
			b = b->prev;
		}
		else
			printf("   |\n");
	}
	printf("| a | b |\n\x1b[0m\n");
}
