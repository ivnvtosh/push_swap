/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:57:53 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/19 19:57:55 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../libft/libft.h"

t_stack	*parser(int *count, char **numbers);
t_list	*parser_commands(t_stack *stack_a, t_stack *stack_b);
void	apply_commands(t_stack **stack_a, t_stack **stack_b, t_list *commands);
void	evaluate_stack(t_stack *stack_a, t_stack *stack_b);
void	terminate(t_stack *stack_a, t_stack *stack_b, int code);

void	checker(int count, char **numbers)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*commands;

	stack_a = parser(&count, numbers);
	stack_b = NULL;
	commands = parser_commands(stack_a, stack_b);
	apply_commands(&stack_a, &stack_b, commands);
	evaluate_stack(stack_a, stack_b);
	terminate(stack_a, stack_b, 5);
}
