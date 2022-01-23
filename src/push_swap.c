/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:14:25 by ccamie            #+#    #+#             */
/*   Updated: 2021/12/25 18:14:28 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

t_stack	*parser(int *count, char **numbers);
void	print(t_stack *stack_a, t_stack *stack_b);
void	quicksort(t_stack **stack_a, t_stack **stack_b, int count);
void	terminate(t_stack *stack_a, t_stack *stack_b, int code);

void	push_swap(int count, char **numbers)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = parser(&count, numbers);
	stack_b = NULL;
	quicksort(&stack_a, &stack_b, count);
	terminate(stack_a, stack_b, 0);
}
