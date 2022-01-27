/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:17:25 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/26 19:17:30 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../libft/libft.h"

void	swap(t_stack *stack);
void	push(t_stack **stack_from, t_stack **stack_in);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	print(t_stack *a, t_stack *b);

static void	check_swap(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
		swap(*a);
	else if (c == 'b')
		swap(*b);
	else if (c == 's')
	{
		swap(*a);
		swap(*b);
	}
}

static void	check_push(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
		push(b, a);
	else if (c == 'b')
		push(a, b);
}

static void	check_rotate(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
		rotate(a);
	else if (c == 'b')
		rotate(b);
	else if (c == 'r')
	{
		rotate(a);
		rotate(b);
	}
}

static void	check_reverse_rotate(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
		reverse_rotate(a);
	else if (c == 'b')
		reverse_rotate(b);
	else if (c == 'r')
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

void	action(t_stack **a, t_stack **b, const char *s)
{
	if (*s == 's')
		check_swap(a, b, *(s + 1));
	else if (*s == 'p')
		check_push(a, b, *(s + 1));
	else if (*s == 'r' && *(s + 2) == '\n')
		check_rotate(a, b, *(s + 1));
	else if (*s == 'r')
		check_reverse_rotate(a, b, *(s + 2));
}
