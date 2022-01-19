
#include "checker_bonus.h"

t_stack	*parser(int *count, char **nubmers);

void	checker(int count, char **nubmers)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = parser(&count, nubmers);
	stack_b = NULL;
	terminate(stack_a, stack_b, 0);
}