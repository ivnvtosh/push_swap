
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
		// printf("%d < %d\n", pivot, (*stack_a)->cell);
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

void	polovina_b(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	pivot;

	pivot = get_pivot(*stack_b, count);
	while (count > 0)
	{
		if (*stack_b == (*stack_b)->next->next)
			return ;	
		// printf("%d < %d\n", pivot, (*stack_a)->cell);
		if (pivot > (*stack_b)->cell)
			action(stack_a, stack_b, "pa");
		else
			action(stack_a, stack_b, "rb");
		count--;	
	}
	if (pivot > (*stack_b)->cell)
		action(stack_a, stack_b, "pa");
	else
		action(stack_a, stack_b, "rb");
}

int	get_min(t_stack *stack)
{
	int		min;
	int		count;

	if (stack == NULL)
		return (0);
	if (stack == stack->next)
		return (stack->cell);
	min = 20000000;
	count = stacklen(stack);
	while (count > 0)
	{
		if (min > stack->cell)
			min = stack->cell;
		stack = stack->next;
		count--;
	}
	return (min);
}

void	min_back(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = get_min(*stack_a);
	while ((*stack_a)->cell != min)
		action(stack_a, stack_b, "rra");
	action(stack_a, stack_b, "ra");
}

void	min_back_b(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = get_min(*stack_b);
	while ((*stack_b)->cell != min)
		action(stack_a, stack_b, "rrb");
}

void	ft_last(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->cell < (*stack_a)->next->cell && (*stack_b)->cell > (*stack_b)->next->cell)
		action(stack_a, stack_b, "ss");
	else
	{
		if ((*stack_a)->cell < (*stack_a)->next->cell)
			action(stack_a, stack_b, "sa");
		if ((*stack_b)->cell > (*stack_b)->next->cell)
			action(stack_a, stack_b, "sb");
	}
	action(stack_a, stack_b, "pa");
	action(stack_a, stack_b, "pa");
}

void	papapapa(t_stack **stack_a, t_stack **stack_b, int count)
{
	while (count > 0)
	{
		action(stack_a, stack_b, "pa");
		count--;
	}
}

void	segment_4(t_stack **stack_a, t_stack **stack_b)
{
	papapapa(stack_a, stack_b, 4);
	polovina(stack_a, stack_b, 4);
	min_back(stack_a, stack_b);
	ft_last(stack_a, stack_b);
}

void	segment_8(t_stack **stack_a, t_stack **stack_b)
{
	papapapa(stack_a, stack_b, 8);
	polovina(stack_a, stack_b, 8);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 4);
	min_back(stack_a, stack_b);
	ft_last(stack_a, stack_b);

	segment_4(stack_a, stack_b);
}

void	segment_16(t_stack **stack_a, t_stack **stack_b)
{

	papapapa(stack_a, stack_b, 16);
	polovina(stack_a, stack_b, 16);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 8);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 4);
	min_back(stack_a, stack_b);
	ft_last(stack_a, stack_b);

	segment_4(stack_a, stack_b);
	segment_8(stack_a, stack_b);
}

void	segment_32(t_stack **stack_a, t_stack **stack_b)
{
	papapapa(stack_a, stack_b, 32);
	polovina(stack_a, stack_b, 32);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 16);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 8);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 4);
	min_back(stack_a, stack_b);
	ft_last(stack_a, stack_b);

	segment_4(stack_a, stack_b);
	segment_8(stack_a, stack_b);
	segment_16(stack_a, stack_b);
}

void	segment_64(t_stack **stack_a, t_stack **stack_b)
{
	papapapa(stack_a, stack_b, 64);
	polovina(stack_a, stack_b, 64);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 32);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 16);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 8);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 4);
	min_back(stack_a, stack_b);
	ft_last(stack_a, stack_b);

	segment_4(stack_a, stack_b);
	segment_8(stack_a, stack_b);
	segment_16(stack_a, stack_b);
	segment_32(stack_a, stack_b);
}

void	segment_128(t_stack **stack_a, t_stack **stack_b)
{
	papapapa(stack_a, stack_b, 128);
	polovina(stack_a, stack_b, 128);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 64);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 32);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 16);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 8);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 4);
	min_back(stack_a, stack_b);
	ft_last(stack_a, stack_b);

	segment_4(stack_a, stack_b);
	segment_8(stack_a, stack_b);
	segment_16(stack_a, stack_b);
	segment_32(stack_a, stack_b);
	segment_64(stack_a, stack_b);
}

void	segment_256(t_stack **stack_a, t_stack **stack_b)
{
	papapapa(stack_a, stack_b, 256);
	polovina(stack_a, stack_b, 256);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 128);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 64);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 32);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 16);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 8);
	min_back(stack_a, stack_b);
	polovina(stack_a, stack_b, 4);
	min_back(stack_a, stack_b);
	ft_last(stack_a, stack_b);

	segment_4(stack_a, stack_b);
	segment_8(stack_a, stack_b);
	segment_16(stack_a, stack_b);
	segment_32(stack_a, stack_b);
	segment_64(stack_a, stack_b);
	segment_128(stack_a, stack_b);
}

void	quicksort(t_stack **stack_a, t_stack **stack_b)
{
	int	count;
	int	i;

	i = 0;
	while (*stack_a != (*stack_a)->next->next && *stack_a != (*stack_a)->next)
	{
		count = stacklen(*stack_a);
		polovina(stack_a, stack_b, count);
		i++;
	}
	ft_last(stack_a, stack_b);

	segment_4(stack_a, stack_b);
	segment_8(stack_a, stack_b);
	segment_16(stack_a, stack_b);
	segment_32(stack_a, stack_b);
	segment_64(stack_a, stack_b);
	segment_128(stack_a, stack_b);
	segment_256(stack_a, stack_b);
}
