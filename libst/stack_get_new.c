
#include "libst.h"
#include <stdlib.h>

t_stack	*stack_get_new(int value)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->value = value;
	stack->prev = NULL;
	return (stack);
}
