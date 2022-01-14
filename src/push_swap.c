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

t_stack	*parser(int *argc, char **argv);
void	stack_print(t_stack *stack_a, t_stack *stack_b);
void	manual_sorting(t_stack **stack_a, t_stack **stack_b, int argc);
void	terminate(t_stack *stack_a, t_stack *stack_b, int code);

void	push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = parser(&argc, argv);
	stack_b = NULL;
	if (argc < 6)
		manual_sorting(&stack_a, &stack_b, argc);
	terminate(stack_a, stack_b, 0);
}
