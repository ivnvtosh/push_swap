
#include "libst.h"
#include <stdio.h>

void	stack_print(t_stack *stack)
{
	printf("\x1b[4m     \n");
	while (stack != NULL)
	{
		printf("|%3d|\n", stack->value);
		stack = stack->prev;
	}
	printf("| a |\x1b[0m\n");
}
