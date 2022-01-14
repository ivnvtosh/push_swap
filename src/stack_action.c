/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:45:33 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/14 08:45:45 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	stack_swap(t_stack *stack);
void	stack_push(t_stack **stack_from, t_stack **stack_in);
void	stack_rotate(t_stack **stack);
void	stack_reverse_rotate(t_stack **stack);
void	error_3(t_stack *stack_a, t_stack *stack_b, const char *s);
void	stack_print(t_stack *stack_a, t_stack *stack_b);

void	check_swap(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (c == 'a')
		stack_swap(*stack_a);
	else if (c == 'b')
		stack_swap(*stack_b);
	else if (c == 's')
	{
		stack_swap(*stack_a);
		stack_swap(*stack_b);
	}
	else
		error_3(*stack_a, *stack_b, "u r invalid! action.");
}

void	check_push(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (c == 'a')
		stack_push(stack_b, stack_a);
	else if (c == 'b')
		stack_push(stack_a, stack_b);
	else
		error_3(*stack_a, *stack_b, "u r invalid! action.");
}

void	check_rotate(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (c == 'a')
		stack_rotate(stack_a);
	else if (c == 'b')
		stack_rotate(stack_b);
	else if (c == 'r')
	{
		stack_rotate(stack_a);
		stack_rotate(stack_b);
	}
	else
		error_3(*stack_a, *stack_b, "u r invalid! action.");
}

void	check_reverse_rotate(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (c == 'a')
		stack_reverse_rotate(stack_a);
	else if (c == 'b')
		stack_reverse_rotate(stack_b);
	else if (c == 'r')
	{
		stack_reverse_rotate(stack_a);
		stack_reverse_rotate(stack_b);
	}
	else
		error_3(*stack_a, *stack_b, "u r invalid! action.");
}

void	stack_action(t_stack **stack_a, t_stack **stack_b, const char *s)
{
	ft_putendl_fd(s, 1);
	if (*s == 's')
		check_swap(stack_a, stack_b, *(s + 1));
	else if (*s == 'p')
		check_push(stack_a, stack_b, *(s + 1));
	else if (*s == 'r' && *(s + 2) == '\0')
		check_rotate(stack_a, stack_b, *(s + 1));
	else if (*s == 'r')
		check_reverse_rotate(stack_a, stack_b, *(s + 2));
	else
		error_3(*stack_a, *stack_b, "u r invalid! action.");
	stack_print(*stack_a, *stack_b);
}
