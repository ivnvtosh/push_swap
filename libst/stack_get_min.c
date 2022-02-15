
#include "libst.h"
#include <stddef.h>

t_stack	*stack_get_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack != NULL)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->prev;
	}
	return (min);
}
