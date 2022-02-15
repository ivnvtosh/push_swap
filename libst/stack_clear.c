
#include "libst.h"
#include <stdlib.h>

void	stack_clear(t_stack **stack)
{
	t_stack	*top;

	while (*stack)
	{
		top = *stack;
		*stack = (*stack)->prev;
		stack_delone(top);
	}
	*stack = NULL;
}
