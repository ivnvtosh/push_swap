
#include "checker_bonus.h"
#include "../libft/libft.h"

void	terminate(t_stack *stack_a, t_stack *stack_b, int code);

void	evaluate_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*start;

	if (stack_b != NULL)
		terminate(stack_a, stack_b, 3);
	start = stack_a;
	while (stack_a->next != start && stack_a->number < stack_a->next->number)
		stack_a = stack_a->next;
	if (stack_a->next != start)
		terminate(start, stack_b, 3);
}
