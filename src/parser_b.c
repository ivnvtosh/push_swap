/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 06:31:57 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/13 06:31:58 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	ft_exit(const char *s, int code);
void	stack_clear(t_stack *stack, const char *s);

t_stack	*parser_b(int argc)
{
	t_stack	*stack;
	t_stack	*start;
	t_stack	*temp;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		ft_exit("Error: memory allocation failure.", -1);
	stack->cell = 0;
	start = stack;
	argc -= 1;
	while (argc)
	{
		stack->next = (t_stack *)malloc(sizeof(t_stack));
		if (stack->next == NULL)
			stack_clear(start, "Error: memory allocation failure.");
		temp = stack;
		stack = stack->next;
		stack->prev = temp;
		stack->cell = 0;
		argc -= 1;
	}
	stack->next = start;
	start->prev = stack;
	return (start);
}
