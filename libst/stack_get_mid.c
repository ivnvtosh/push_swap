
#include "libst.h"
#include <stddef.h>

t_stack	*stack_get_mid(t_stack *stack)
{
	t_stack	*top;
	int		mid;

	top = stack;
	mid = 0;
	while (stack != NULL)
	{
		mid +=  stack->value;
		stack = stack->prev;
	}
	mid /= stack_get_height(top);
	stack = top;
	while (stack->value != mid)
		stack = stack->prev;
	return (stack);
}
