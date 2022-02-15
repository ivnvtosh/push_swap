
#include "libst.h"

void	stack_add_top(t_stack **stack, t_stack *new)
{
	new->prev = *stack;
	*stack = new;
}
