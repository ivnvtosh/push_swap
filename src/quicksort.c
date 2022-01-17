
#include "push_swap.h"

void	action(t_stack **stack_a, t_stack **stack_b, const char *s);
int		stacklen(t_stack *stack);
void	print(t_stack *stack_a, t_stack *stack_b);

int	get_pivot(t_stack *stack, int count)
{
	t_stack	*start;
	int		pivot;
	int		i;

	if (stack == NULL)
		return (0);
	if (stack == stack->next)
		return (stack->cell);
	start = stack;
	pivot = 0;
	i = 1;
	while (count > 0)
	{
		pivot += stack->cell;
		stack = stack->next;
		i++;
		count--;
	}
	pivot += stack->cell;
	pivot /= i;
	return (pivot);
}

void	polovina(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	pivot;

	pivot = get_pivot(*stack_a, count);
	while (count > 0)
	{
		if (*stack_a == (*stack_a)->next->next)
			return ;	
		printf("%d < %d\n", pivot, (*stack_a)->cell);
		if (pivot < (*stack_a)->cell)
			action(stack_a, stack_b, "pb");
		else
			action(stack_a, stack_b, "ra");
		count--;	
	}
	if (pivot < (*stack_a)->cell)
		action(stack_a, stack_b, "pb");
	else
		action(stack_a, stack_b, "ra");
}

void	quicksort(t_stack **stack_a, t_stack **stack_b)
{
	int	count;
	int	i;
	int	n;

	i = 0;
	while (*stack_a != (*stack_a)->next->next && *stack_a != (*stack_a)->next)
	{
		count = stacklen(*stack_a);
		polovina(stack_a, stack_b, count);
		i++;
	}
	print(*stack_a, *stack_b);
	printf("%d\n", i);
	// if ((*stack_a)->cell < (*stack_a)->next->cell && (*stack_b)->cell > (*stack_b)->next->cell)
	// 	action(stack_a, stack_b, "ss");
	if ((*stack_a)->cell < (*stack_a)->next->cell)
		action(stack_a, stack_b, "sa");
	// if ((*stack_b)->cell > (*stack_b)->next->cell)
	// 	action(stack_a, stack_b, "sb");
	// action(stack_a, stack_b, "pa");
	// action(stack_a, stack_b, "pa");
	i--;
	action(stack_a, stack_b, "pa");
	action(stack_a, stack_b, "pa");
	action(stack_a, stack_b, "pa");
	action(stack_a, stack_b, "pa");
	print(*stack_a, *stack_b);

	n = 4;
	polovina(stack_a, stack_b, n);
	action(stack_a, stack_b, "ra");
	if ((*stack_a)->cell < (*stack_a)->next->cell)
		action(stack_a, stack_b, "sa");
	print(*stack_a, *stack_b);


	action(stack_a, stack_b, "pa");
	action(stack_a, stack_b, "pa");
	action(stack_a, stack_b, "pa");
	action(stack_a, stack_b, "pa");
	action(stack_a, stack_b, "pa");
	action(stack_a, stack_b, "pa");
	action(stack_a, stack_b, "pa");
	action(stack_a, stack_b, "pa");
	print(*stack_a, *stack_b);

	n = 8;
	polovina(stack_a, stack_b, n);
	action(stack_a, stack_b, "ra");
	action(stack_a, stack_b, "ra");
	action(stack_a, stack_b, "ra");
	print(*stack_a, *stack_b);

	n = 4;
	polovina(stack_a, stack_b, n);
	action(stack_a, stack_b, "ra");
	if ((*stack_a)->cell < (*stack_a)->next->cell)
		action(stack_a, stack_b, "sa");
	action(stack_a, stack_b, "ra");
	action(stack_a, stack_b, "ra");
	print(*stack_a, *stack_b);

	action(stack_a, stack_b, "pa");
	action(stack_a, stack_b, "pa");
	action(stack_a, stack_b, "pa");
	action(stack_a, stack_b, "pa");
	print(*stack_a, *stack_b);

	n = 4;
	polovina(stack_a, stack_b, n);
	action(stack_a, stack_b, "ra");
	if ((*stack_a)->cell < (*stack_a)->next->cell)
		action(stack_a, stack_b, "sa");
	waction(stack_a, stack_b, "ra");
	action(stack_a, stack_b, "ra");
	action(stack_a, stack_b, "ra");
	action(stack_a, stack_b, "ra");
	print(*stack_a, *stack_b);




	// action(stack_a, stack_b, "pa");
	// print(*stack_a, *stack_b);
	// if ((*stack_a)->cell < (*stack_a)->next->cell)
	// 	action(stack_a, stack_b, "sa");
}