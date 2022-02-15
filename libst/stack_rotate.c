
#include "libst.h"
#include <stddef.h>

void	stack_rotate(t_stack **stack)
{
	t_stack *top;

	stack_get_bottom(*stack)->prev = *stack;
	top = (*stack)->prev;
	(*stack)->prev = NULL;
	*stack = top;
}

void	stack_reverce_rotate(t_stack **stack)
{
	t_stack *top;

	top = stack_get_bottom(*stack);
	top->prev = *stack;
	*stack = top;
	while (top->prev != *stack)
		top = top->prev;
	top->prev = NULL;
}
