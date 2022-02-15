
#include "libst.h"
#include <stddef.h>

int	stack_get_height(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->prev;
		i += 1;
	}
	return (i);
}
