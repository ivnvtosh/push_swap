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

typedef struct s_len
{
	int	a;
	int	b;
}	t_len;

int	stack_len(t_stack *stack);

t_len	get_len(t_stack *a, t_stack *b)
{
	t_len	len;

	len.a = stack_len(a);
	len.b = stack_len(b);
	return (len);
}

void	print(t_stack *a, t_stack *b)
{
	t_len	len;

	len = get_len(a, b);
	printf("\x1b[4m                 \n");
	while (len.a > 0 || len.b > 0)
	{
		if (len.a-- > 0)
		{
			printf("|%3d|%3u|", a->number, a->index);
			a = a->next;
		}
		else
			printf("|   |   |");
		if (len.b-- > 0)
		{
			printf("%3d|%3u|\n", b->number, b->index);
			b = b->next;
		}
		else
			printf("   |   |\n");
	}
	printf("| a | i | b | i |\n\x1b[0m\n");
}
