
#include "libst.h"
#include <stddef.h>

void	stack_push(t_stack **from, t_stack **to)
{
	t_stack	*top;

	top = *from;
	if ((*from)->prev == NULL)
		*from = NULL;
	else
		*from = (*from)->prev;
	stack_add_top(to, top);
}
