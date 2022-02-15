
#include "libst.h"
#include <stddef.h>

t_stack	*stack_get_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack != NULL)
	{
		if (stack->value > max->value)
			max = stack;
		stack = stack->prev;
	}
	return (max);
}
