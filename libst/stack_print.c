
#include "libst.h"
#include <stdio.h>

void	stack_print_one(t_stack *stack)
{
	printf("\x1b[4m     \n");
	if (stack == NULL)
		printf("|nil|\n");
	while (stack != NULL)
	{
		printf("|%3d|\n", stack->value);
		stack = stack->prev;
	}
	printf("\x1b[0m\n");
}

void	stack_print(t_stack *a, t_stack *b)
{
	printf("\x1b[4m         \n");
	while (a != NULL || b != NULL)
	{
		if (a != NULL)
		{
			printf("|%3u|", a->value);
			a = a->prev;
		}
		else
			printf("|   |");
		if (b != NULL)
		{
			printf("%3u|\n", b->value);
			b = b->prev;
		}
		else
			printf("   |\n");
	}
	printf("| a | b |\n\x1b[0m\n");
}
