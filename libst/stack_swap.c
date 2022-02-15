
#include "libst.h"

void	stack_swap(t_stack *stack)
{
	int	c;

	c = stack->prev->value;
	stack->prev->value = stack->value;
	stack->value = c;
}
