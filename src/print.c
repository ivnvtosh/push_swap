/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
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

void	print(t_stack *a, t_stack *b)
{
	int	alen;
	int	blen;

	alen = stack_len(a);
	blen = stack_len(b);
	printf("\x1b[4m         \n");
	while (alen > 0 || blen > 0)
	{
		if (alen-- > 0)
		{
			printf("|%3d|", a->number);
			a = a->next;
		}
		else
			printf("|   |");
		if (blen-- > 0)
		{
			printf("%3d|\n", b->number);
			b = b->next;
		}
		else
			printf("   |\n");
	}
	printf("| a | b |\n\x1b[0m\n");
}
