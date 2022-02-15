
#include "libst.h"
#include <stdlib.h>

void	stack_delone(t_stack *stack)
{
	free(stack);
}
