
#include "libst.h"
#include <stddef.h>

void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
		*stack = new;
	else
		stack_get_bottom(*stack)->prev = new;
}
