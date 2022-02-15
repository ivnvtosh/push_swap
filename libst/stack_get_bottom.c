
#include "libst.h"
#include <stddef.h>

t_stack	*stack_get_bottom(t_stack *stack)
{
	while (stack->prev != NULL)
		stack = stack->prev;
	return (stack);
}
