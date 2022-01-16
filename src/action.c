/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:45:33 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/14 08:45:45 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	swap(t_stack *stack);
void	push(t_stack **stack_from, t_stack **stack_in);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	print(t_stack *stack_a, t_stack *stack_b);

void	check_swap(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (c == 'a')
		swap(*stack_a);
	else if (c == 'b')
		swap(*stack_b);
	else if (c == 's')
	{
		swap(*stack_a);
		swap(*stack_b);
	}
}

void	check_push(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (c == 'a')
		push(stack_b, stack_a);
	else if (c == 'b')
		push(stack_a, stack_b);
}

void	check_rotate(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (c == 'a')
		rotate(stack_a);
	else if (c == 'b')
		rotate(stack_b);
	else if (c == 'r')
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}

void	check_reverse_rotate(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (c == 'a')
		reverse_rotate(stack_a);
	else if (c == 'b')
		reverse_rotate(stack_b);
	else if (c == 'r')
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
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
}
