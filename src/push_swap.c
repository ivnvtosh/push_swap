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

t_stack	*parser_a(char **argv);
t_stack	*parser_b(int argc);
void	stack_print(t_stack *stack_a, t_stack *stack_b);

void	stack_swap(t_stack *stack, const char *s)
{
	t_stack	*start;
	t_stack	*temp;

	start = stack;
	if (stack->cont == 0)
		stack = stack->next;
	while (stack != start && stack->cont == 0)
		stack = stack->next;
	temp = stack;
	temp = temp->next;
	ft_swap(&stack->cell, &temp->cell);
	ft_putendl_fd(s, 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b, const char *s)
{
	t_stack	*start;
	t_stack	*end;

	start = stack_a;
	end = stack_b;
	if (stack_a->cont == 0)
		stack_a = stack_a->next;
	while (stack_a != start && stack_a->cont == 0)
		stack_a = stack_a->next;
	if (stack_a->cont == 0 && stack_a == start)
		return ;
	stack_b = stack_b->prev;
	while (stack_b != end && stack_b->cont == 1)
		stack_b = stack_b->prev;
	stack_b->cell = stack_a->cell;
	stack_b->cont = 1;
	stack_a->cont = 0;
	ft_putendl_fd(s, 1);
}

void	ra(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	temp = temp->next;
	*stack = temp;
}

void	push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = parser_a(argv);
	stack_b = parser_b(argc);
	pb(stack_a, stack_b, "pb");
	stack_print(stack_a, stack_b);
	ra(&stack_a);
	stack_print(stack_a, stack_b);
}
